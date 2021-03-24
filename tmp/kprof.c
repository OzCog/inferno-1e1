#include <u.h>
#include <libc.h>
#include <bio.h>
#include <mach.h>

#define	PCRES	8

struct COUNTER
{
	char 	*name;		/* function name */
	long	time;		/* ticks spent there */
};

void
error(int perr, char *s)
{
	fprint(2, "kprof: %s", s);
	if(perr){
		fprint(2, ": ");
		perror(0);
	}else
		fprint(2, "\n");
	exits(s);
}

int
compar(struct COUNTER *a, struct COUNTER *b)
{
	if(a->time < b->time)
		return -1;
	if(a->time == b->time)
		return 0;
	return 1;
}
void
main(int argc, char *argv[])
{
	int fd;
	long i, j, k, n;
	Dir d;
	char *name;
	ulong *data;
	ulong tbase, sum;
	long delta;
	Symbol s;
	Biobuf outbuf;
	Fhdr f;
	struct COUNTER *cp;

	if(argc != 3)
		error(0, "usage: kprof text data");
	/*
	 * Read symbol table
	 */
	fd = open(argv[1], OREAD);
	if(fd < 0)
		error(1, argv[1]);
	if (!crackhdr(fd, &f))
		error(1, "read text header");
	if (f.type == FNONE)
		error(0, "text file not an a.out");
	if (syminit(fd, &f) < 0)
		error(1, "syminit");
	close(fd);
	/*
	 * Read timing data
	 */
	fd = open(argv[2], OREAD);
	if(fd < 0)
		error(1, argv[2]);
	if(dirfstat(fd, &d) < 0)
		error(1, "stat");
	n = d.length/sizeof(data[0]);
	if(n < 2)
		error(0, "data file too short");
	data = malloc(d.length);
	if(data == 0)
		error(1, "malloc");
	if(read(fd, data, d.length) < 0)
		error(1, "text read");
	close(fd);
	for(i=0; i<n; i++)
		data[i] = beswal(data[i]);
	delta = data[0]-data[1];
	print("total: %ld	in kernel text: %ld	outside kernel text: %ld\n",
		data[0], delta, data[1]);
	if(data[0] == 0)
		exits(0);
	if (!textsym(&s, 0))
		error(0, "no text symbols");
	tbase = s.value & ~(mach->pgsize-1);	/* align down to page */
	tbase = 1<<31;
	print("KTZERO %.8lux\n", tbase);
	/*
	 * Accumulate counts for each function
	 */
	cp = 0;
	k = 0;
	for (i = 0, j = (s.value-tbase)/PCRES+2; j < n; i++) {
		name = s.name;		/* save name */
		if (!textsym(&s, i))	/* get next symbol */
			break;
		sum = 0;
		while (j < n && j*PCRES < s.value-tbase)
			sum += data[j++];
		if (sum) {
			cp = realloc(cp, (k+1)*sizeof(struct COUNTER));
			if (cp == 0)
				error(1, "realloc");
			cp[k].name = name;
			cp[k].time = sum;
			k++;
		}
	}
	if (!k)
		error(0, "no counts");
	cp[k].time = 0;			/* "etext" can take no time */
	/*
	 * Sort by time and print
	 */
	qsort(cp, k, sizeof(struct COUNTER), compar);
	Binit(&outbuf, 1, OWRITE);
	Bprint(&outbuf, "ms	  %%	sym\n");
	while(--k>=0)
		Bprint(&outbuf, "%ld\t%3ld.%d\t%s\n",
				cp[k].time,
				100*cp[k].time/delta,
				(1000*cp[k].time/delta)%10,
				cp[k].name);
	exits(0);
}