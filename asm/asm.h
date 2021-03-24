#include "lib9.h"
#include <bio.h>
#include <ctype.h>
#include "../include/isa.h"

enum
{
	Eof		= -1,
	False		= 0,
	True		= 1,
	Strsize		= 512,
	Hashsize	= 128,
};

typedef struct Addr	Addr;
typedef struct Inst	Inst;
typedef struct String	String;
typedef struct Sym	Sym;
typedef struct Keywd	Keywd;
typedef struct Desc	Desc;
typedef struct List	List;
typedef struct Link	Link;

struct Addr
{
	uchar	mode;
	ushort	off;
	long	val;
	Sym*	sym;
};

struct List
{
	List*	link;
	int	addr;
	int	type;
	union {
		int	ival;
		float	fval;
		String*	str;
	}u;
};

struct Inst
{
	uchar	op;
	uchar	type;
	int	size;
	Addr*	reg;
	Addr*	src;
	Addr*	dst;
	ulong	pc;
	Sym*	sym;
	Inst*	link;
};

struct String
{
	int	len;
	String*	next;
	char*	string;
};

struct Sym
{
	char*	name;
	int	lexval;
	Sym*	hash;
	int	value;
	int	ds;
};

struct Desc
{
	int	id;
	int	size;
	int	np;
	uchar*	map;
	Desc*	link;
};

struct Link
{
	int	desc;
	int	addr;
	int	type;
	char*	name;
	Link*	link;
};

Sym*	enter(char*, int);
Sym*	lookup(char*);
void	yyerror(char*, ...);
void	fatal(char*, ...);
void	diag(char*, ...);
int	numsym(char);
int	mpatof(char*, double*);
void	kinit(void);
Inst*	ai(int);
Addr*	aa(int);
void	assem(Inst*);
int	iconv(va_list*, Fconv*);
int	aconv(va_list*, Fconv*);
int	opcode(Inst*);
void	heap(int, int, String*);
List*	newi(int, List*);
List*	news(String*, List*);
void	data(int, int, List*);
void	dout(void);
void	ext(int, int, String*);
void	mklink(int, int, int, String*);
ulong	ftocanon(float);

int	yyparse(void);
int	yylex(void);

extern	Biobuf*	bout;
extern	int	nerr;
extern	int	heapid;
extern	Desc*	dlist;
extern	int	dcount;
extern	int	dseg;
extern	List*	mdata;
extern	Sym*	module;
extern	Link*	links;
extern	Link*	linkt;
extern	int	nlink;
extern	int	listing;
extern	int	dentry;
extern	int	pcentry;
