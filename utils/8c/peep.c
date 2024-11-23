#include "gc.h"

void
peep(void)
{
	Reg *r, *r1, *r2;
	Prog *p;
	int t;
/*
 * complete R structure
 */
	t = 0;
	for(r=firstr; r!=R; r=r1) {
		r1 = r->link;
		if(r1 == R)
			break;
		p = r->prog->link;
		while(p != r1->prog)
		switch(p->as) {
		default:
			r2 = rega();
			r->link = r2;
			r2->link = r1;

			r2->prog = p;
			r2->p1 = r;
			r->rs1 = r2;
			r2->rs1 = r1;
			r1->p1 = r2;

			r = r2;
			t++;

		case ADATA:
		case AGLOBL:
		case ANAME:
			p = p->link;
		}
	}

loop1:
	t = 0;
	for(r=firstr; r!=R; r=r->link) {
		p = r->prog;
		if(p->as == AMOVL)
		if(regtyp(&p->to))
		if(regtyp(&p->from)) {
			if(copyprop(r)) {
				excise(r);
				t++;
			}
			if(subprop(r) && copyprop(r)) {
				excise(r);
				t++;
			}
		}
	}
	if(t)
		goto loop1;
}

void
excise(Reg *r)
{
	Prog *p;

	p = r->prog;
	p->as = ANOP;
	p->from = zprog.from;
	p->to = zprog.to;
}

Reg*
uniqp(Reg *r)
{
	Reg *r1;

	r1 = r->p1;
	if(r1 == R) {
		r1 = r->p2;
		if(r1 == R || r1->p2link != R)
			return R;
	} else
		if(r->p2 != R)
			return R;
	return r1;
}

Reg*
uniqs(Reg *r)
{
	Reg *r1;

	r1 = r->rs1;
	if(r1 == R) {
		r1 = r->rs2;
		if(r1 == R)
			return R;
	} else
		if(r->rs2 != R)
			return R;
	return r1;
}

int
regtyp(Adr *a)
{
	int t;

	t = a->type;
	if(t >= D_AX && t <= D_DI)
		return 1;
	return 0;
}

/*
 * the idea is to substitute
 * one register for another
 * from one MOV to another
 *	MOV	a, R0
 *	ADD	b, R0	/ no use of R1
 *	MOV	R0, R1
 * would be converted to
 *	MOV	a, R1
 *	ADD	b, R1
 *	MOV	R1, R0
 * hopefully, then the former or latter MOV
 * will be eliminated by copy propagation.
 */
int
subprop(Reg *r0)
{
	Prog *p;
	Adr *v1, *v2;
	Reg *r;
	int t;

	p = r0->prog;
	v1 = &p->from;
	if(!regtyp(v1))
		return 0;
	v2 = &p->to;
	if(!regtyp(v2))
		return 0;
	for(r=uniqp(r0); r!=R; r=uniqp(r)) {
		if(uniqs(r) == R)
			break;
		p = r->prog;
		switch(p->as) {
		case ACALL:
			return 0;

		case ADIVB:
		case ADIVL:
		case ADIVW:
		case AIDIVB:
		case AIDIVL:
		case AIDIVW:
		case AIMULB:
		case AIMULL:
		case AIMULW:
		case AMULB:
		case AMULL:
		case AMULW:

		case AROLB:
		case AROLL:
		case AROLW:
		case ARORB:
		case ARORL:
		case ARORW:
		case ASALB:
		case ASALL:
		case ASALW:
		case ASARB:
		case ASARL:
		case ASARW:
		case ASHLB:
		case ASHLL:
		case ASHLW:
		case ASHRB:
		case ASHRL:
		case ASHRW:

		case AREP:
		case AREPN:

		case ACWD:
		case ACDQ:

		case AMOVSL:
		case AFSTSW:
			return 0;

		case AMOVL:
			if(p->to.type == v1->type)
				goto gotit;
			break;
		}
		if(copyau(&p->from, v2) ||
		   copyau(&p->to, v2))
			break;
		if(copysub(&p->from, v1, v2, 0) ||
		   copysub(&p->to, v1, v2, 0))
			break;
	}
	return 0;

gotit:
	copysub(&p->to, v1, v2, 1);
	if(debug['P']) {
		print("gotit: %D->%D\n%P", v1, v2, r->prog);
		if(p->from.type == v2->type)
			print(" excise");
		print("\n");
	}
	for(r=uniqs(r); r!=r0; r=uniqs(r)) {
		p = r->prog;
		copysub(&p->from, v1, v2, 1);
		copysub(&p->to, v1, v2, 1);
		if(debug['P'])
			print("%P\n", r->prog);
	}
	t = v1->type;
	v1->type = v2->type;
	v2->type = t;
	if(debug['P'])
		print("%P last\n", r->prog);
	return 1;
}

/*
 * The idea is to remove redundant copies.
 *	v1->v2	F=0
 *	(use v2	s/v2/v1/)*
 *	set v1	F=1
 *	use v2	return fail
 *	-----------------
 *	v1->v2	F=0
 *	(use v2	s/v2/v1/)*
 *	set v1	F=1
 *	set v2	return success
 */
int
copyprop(Reg *r0)
{
	Prog *p;
	Adr *v1, *v2;
	Reg *r;

	p = r0->prog;
	v1 = &p->from;
	v2 = &p->to;
	if(copyas(v1, v2))
		return 1;
	for(r=firstr; r!=R; r=r->link)
		r->u0.ractive = 0;
	return copy1(v1, v2, r0->rs1, 0);
}

int
copy1(Adr *v1, Adr *v2, Reg *r, int f)
{
	int t;
	Prog *p;

	if(r->u0.ractive) {
		if(debug['P'])
			print("act set; return 1\n");
		return 1;
	}
	r->u0.ractive = 1;
	if(debug['P'])
		print("copy %D->%D f=%d\n", v1, v2, f);
	for(; r != R; r = r->rs1) {
		p = r->prog;
		if(debug['P'])
			print("%P", p);
		if(!f && uniqp(r) == R) {
			f = 1;
			if(debug['P'])
				print("; merge; f=%d", f);
		}
		t = copyu(p, v2, A);
		switch(t) {
		case 2:	/* rar, cant split */
			if(debug['P'])
				print("; %D rar; return 0\n", v2);
			return 0;

		case 3:	/* set */
			if(debug['P'])
				print("; %D set; return 1\n", v2);
			return 1;

		case 1:	/* used, substitute */
		case 4:	/* use and set */
			if(f) {
				if(!debug['P'])
					return 0;
				if(t == 4)
					print("; %D used+set and f=%d; return 0\n", v2, f);
				else
					print("; %D used and f=%d; return 0\n", v2, f);
				return 0;
			}
			if(copyu(p, v2, v1)) {
				if(debug['P'])
					print("; sub fail; return 0\n");
				return 0;
			}
			if(debug['P'])
				print("; sub %D/%D", v2, v1);
			if(t == 4) {
				if(debug['P'])
					print("; %D used+set; return 1\n", v2);
				return 1;
			}
			break;
		}
		if(!f) {
			t = copyu(p, v1, A);
			if(!f && (t == 2 || t == 3 || t == 4)) {
				f = 1;
				if(debug['P'])
					print("; %D set and !f; f=%d", v1, f);
			}
		}
		if(debug['P'])
			print("\n");
		if(r->rs2)
			if(!copy1(v1, v2, r->rs2, f))
				return 0;
	}
	return 1;
}

/*
 * return
 * 1 if v only used (and substitute),
 * 2 if read-alter-rewrite
 * 3 if set
 * 4 if set and used
 * 0 otherwise (not touched)
 */
int
copyu(Prog *p, Adr *v, Adr *s)
{

	switch(p->as) {

	default:
		if(debug['P'])
			print("unknown op %A\n", p->as);
		return 2;

	case ALEAL:	/* lhs addr, rhs store */
		if(copyas(&p->from, v))
			return 2;


	case ANOP:	/* rhs store */
	case AMOVL:
	case AMOVBLSX:
	case AMOVBLZX:
	case AMOVWLSX:
	case AMOVWLZX:
		if(copyas(&p->to, v)) {
			if(s != A)
				return copysub(&p->from, v, s, 1);
			if(copyau(&p->from, v))
				return 4;
			return 3;
		}
		goto caseread;

	case AROLB:
	case AROLL:
	case AROLW:
	case ARORB:
	case ARORL:
	case ARORW:
	case ASALB:
	case ASALL:
	case ASALW:
	case ASARB:
	case ASARL:
	case ASARW:
	case ASHLB:
	case ASHLL:
	case ASHLW:
	case ASHRB:
	case ASHRL:
	case ASHRW:
		if(copyas(&p->to, v))
			return 2;
		if(copyas(&p->from, v))
			if(p->from.type == D_CX)
				return 2;
		goto caseread;

	case AADDB:	/* rhs rar */
	case AADDL:
	case AADDW:
	case AANDB:
	case AANDL:
	case AANDW:
	case ASUBB:
	case ASUBL:
	case ASUBW:
	case AORB:
	case AORL:
	case AORW:
	case AXORB:
	case AXORL:
	case AXORW:
	case AMOVB:
	case AMOVW:

	case AFMOVB:
	case AFMOVBP:
	case AFMOVD:
	case AFMOVDP:
	case AFMOVF:
	case AFMOVFP:
	case AFMOVL:
	case AFMOVLP:
	case AFMOVV:
	case AFMOVVP:
	case AFMOVW:
	case AFMOVWP:
	case AFMOVX:
	case AFMOVXP:
	case AFADDDP:
	case AFADDW:
	case AFADDL:
	case AFADDF:
	case AFADDD:
	case AFMULDP:
	case AFMULW:
	case AFMULL:
	case AFMULF:
	case AFMULD:
	case AFSUBDP:
	case AFSUBW:
	case AFSUBL:
	case AFSUBF:
	case AFSUBD:
	case AFSUBRDP:
	case AFSUBRW:
	case AFSUBRL:
	case AFSUBRF:
	case AFSUBRD:
	case AFDIVDP:
	case AFDIVW:
	case AFDIVL:
	case AFDIVF:
	case AFDIVD:
	case AFDIVRDP:
	case AFDIVRW:
	case AFDIVRL:
	case AFDIVRF:
	case AFDIVRD:
		if(copyas(&p->to, v))
			return 2;
		goto caseread;

	case ACMPL:	/* read only */
	case ACMPW:
	case ACMPB:

	case AFCOMB:
	case AFCOMBP:
	case AFCOMD:
	case AFCOMDP:
	case AFCOMDPP:
	case AFCOMF:
	case AFCOMFP:
	case AFCOML:
	case AFCOMLP:
	case AFCOMW:
	case AFCOMWP:
	case AFUCOM:
	case AFUCOMP:
	case AFUCOMPP:
	caseread:
		if(s != A) {
			if(copysub(&p->from, v, s, 1))
				return 1;
			return copysub(&p->to, v, s, 1);
		}
		if(copyau(&p->from, v))
			return 1;
		if(copyau(&p->to, v))
			return 1;
		break;

	case AJGE:	/* no reference */
	case AJNE:
	case AJLE:
	case AJEQ:
	case AJHI:
	case AJLS:
	case AJMI:
	case AJPL:
	case AJGT:
	case AJLT:
	case AJCC:
	case AJCS:

	case AADJSP:
	case AFLDZ:
	case AWAIT:
		break;

	case ADIVB:
	case ADIVL:
	case ADIVW:
	case AIDIVB:
	case AIDIVL:
	case AIDIVW:
	case AIMULB:
	case AIMULL:
	case AIMULW:
	case AMULB:
	case AMULL:
	case AMULW:

	case ACWD:
	case ACDQ:
		if(v->type == D_AX || v->type == D_DX)
			return 2;
		goto caseread;

	case AMOVSL:
	case AREP:
	case AREPN:
		if(v->type == D_CX || v->type == D_DI || v->type == D_SI)
			return 2;
		goto caseread;

	case AFSTSW:
		if(v->type == D_AX)
			return 2;
		goto caseread;

	case AJMP:	/* funny */
		if(s != A) {
			if(copysub(&p->to, v, s, 1))
				return 1;
			return 0;
		}
		if(copyau(&p->to, v))
			return 1;
		return 0;

	case ARET:	/* funny */
		if(v->type == REGRET)
			return 2;
		if(s != A)
			return 1;
		return 3;

	case ACALL:	/* funny */
		if(REGARG && v->type == REGARG)
			return 2;

		if(s != A) {
			if(copysub(&p->to, v, s, 1))
				return 1;
			return 0;
		}
		if(copyau(&p->to, v))
			return 4;
		return 3;
	}
	return 0;
}

/*
 * direct reference,
 * could be set/use depending on
 * semantics
 */
int
copyas(Adr *a, Adr *v)
{
	if(a->type != v->type)
		return 0;
	if(regtyp(v))
		return 1;
	if(v->type == D_AUTO || v->type == D_PARAM)
		if(v->u0.aoffset == a->u0.aoffset)
			return 1;
	return 0;
}

/*
 * either direct or indirect
 */
int
copyau(Adr *a, Adr *v)
{

	if(copyas(a, v))
		return 1;
	if(regtyp(v)) {
		if(a->type-D_INDIR == v->type)
			return 1;
		if(a->index == v->type)
			return 1;
	}
	return 0;
}

/*
 * substitute s for v in a
 * return failure to substitute
 */
int
copysub(Adr *a, Adr *v, Adr *s, int f)
{
	int t;

	if(copyas(a, v)) {
		t = s->type;
		if(t >= D_AX && t <= D_DI) {
			if(f)
				a->type = t;
		}
		return 0;
	}
	if(regtyp(v)) {
		t = v->type;
		if(a->type == t+D_INDIR) {
			if(f)
				a->type = s->type+D_INDIR;
			return 0;
		}
		if(a->index == t) {
			if(f)
				a->index = s->type;
			return 0;
		}
		return 0;
	}
	return 0;
}
