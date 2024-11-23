#include "cc.h"

void
evconst(Node *n)
{
	Node *l, *r;
	int et, isf;
	vlong v;
	double d;

	if(n == Z || n->type == T)
		return;

	et = n->type->etype;
	isf = typefd[et];

	l = n->u0.s0.nleft;
	r = n->u0.s0.nright;

	d = 0;
	v = 0;

	switch(n->op) {
	default:
		return;

	case OCAST:
		if(et == TVOID)
			return;
		et = l->type->etype;
		if(isf) {
			if(typefd[et])
				d = l->u0.nfconst;
			else
				d = l->u0.nvconst;
		} else {
			if(typefd[et])
				v = l->u0.nfconst;
			else
				v = convvtox(l->u0.nvconst, n->type->etype);
		}
		break;

	case OCONST:
		break;

	case OADD:
		if(isf)
			d = l->u0.nfconst + r->u0.nfconst;
		else {
			v = l->u0.nvconst + r->u0.nvconst;
		}
		break;

	case OSUB:
		if(isf)
			d = l->u0.nfconst - r->u0.nfconst;
		else
			v = l->u0.nvconst - r->u0.nvconst;
		break;

	case OMUL:
		if(isf)
			d = l->u0.nfconst * r->u0.nfconst;
		else {
			v = l->u0.nvconst * r->u0.nvconst;
		}
		break;

	case OLMUL:
		v = (uvlong)l->u0.nvconst * (uvlong)r->u0.nvconst;
		break;


	case ODIV:
		if(vconst(r) == 0) {
			warn(n, "divide by zero");
			return;
		}
		if(isf)
			d = l->u0.nfconst / r->u0.nfconst;
		else
			v = l->u0.nvconst / r->u0.nvconst;
		break;

	case OLDIV:
		if(vconst(r) == 0) {
			warn(n, "divide by zero");
			return;
		}
		v = (uvlong)l->u0.nvconst / (uvlong)r->u0.nvconst;
		break;

	case OMOD:
		if(vconst(r) == 0) {
			warn(n, "modulo by zero");
			return;
		}
		v = l->u0.nvconst % r->u0.nvconst;
		break;

	case OLMOD:
		if(vconst(r) == 0) {
			warn(n, "modulo by zero");
			return;
		}
		v = (uvlong)l->u0.nvconst % (uvlong)r->u0.nvconst;
		break;

	case OAND:
		v = l->u0.nvconst & r->u0.nvconst;
		break;

	case OOR:
		v = l->u0.nvconst | r->u0.nvconst;
		break;

	case OXOR:
		v = l->u0.nvconst ^ r->u0.nvconst;
		break;

	case OLSHR:
		v = (uvlong)l->u0.nvconst >> r->u0.nvconst;
		break;

	case OASHR:
		v = l->u0.nvconst >> r->u0.nvconst;
		break;

	case OASHL:
		v = l->u0.nvconst << r->u0.nvconst;
		break;

	case OLO:
		v = (uvlong)l->u0.nvconst < (uvlong)r->u0.nvconst;
		break;

	case OLT:
		if(typefd[l->type->etype])
			v = l->u0.nfconst < r->u0.nfconst;
		else
			v = l->u0.nvconst < r->u0.nvconst;
		break;

	case OHI:
		v = (uvlong)l->u0.nvconst > (uvlong)r->u0.nvconst;
		break;

	case OGT:
		if(typefd[l->type->etype])
			v = l->u0.nfconst > r->u0.nfconst;
		else
			v = l->u0.nvconst > r->u0.nvconst;
		break;

	case OLS:
		v = (uvlong)l->u0.nvconst <= (uvlong)r->u0.nvconst;
		break;

	case OLE:
		if(typefd[l->type->etype])
			v = l->u0.nfconst <= r->u0.nfconst;
		else
			v = l->u0.nvconst <= r->u0.nvconst;
		break;

	case OHS:
		v = (uvlong)l->u0.nvconst >= (uvlong)r->u0.nvconst;
		break;

	case OGE:
		if(typefd[l->type->etype])
			v = l->u0.nfconst >= r->u0.nfconst;
		else
			v = l->u0.nvconst >= r->u0.nvconst;
		break;

	case OEQ:
		if(typefd[l->type->etype])
			v = l->u0.nfconst == r->u0.nfconst;
		else
			v = l->u0.nvconst == r->u0.nvconst;
		break;

	case ONE:
		if(typefd[l->type->etype])
			v = l->u0.nfconst != r->u0.nfconst;
		else
			v = l->u0.nvconst != r->u0.nvconst;
		break;

	case ONOT:
		if(typefd[l->type->etype])
			v = !l->u0.nfconst;
		else
			v = !l->u0.nvconst;
		break;

	case OANDAND:
		if(typefd[l->type->etype])
			v = l->u0.nfconst && r->u0.nfconst;
		else
			v = l->u0.nvconst && r->u0.nvconst;
		break;

	case OOROR:
		if(typefd[l->type->etype])
			v = l->u0.nfconst || r->u0.nfconst;
		else
			v = l->u0.nvconst || r->u0.nvconst;
		break;
	}
	if(isf) {
		n->u0.nfconst = d;
	} else {
		n->u0.nvconst = convvtox(v, n->type->etype);
	}
	n->op = OCONST;
}

void
acom(Node *n)
{
	Type *t;
	Node *l, *r;
	int i;

	switch(n->op)
	{

	case ONAME:
	case OCONST:
	case OSTRING:
	case OINDREG:
	case OREGISTER:
		return;

	case OADD:
	case OSUB:
	case OMUL:
		l = n->u0.s0.nleft;
		r = n->u0.s0.nright;
		if(addo(n)) {
			if(addo(r))
				break;
			if(addo(l))
				break;
		}
		acom(l);
		acom(r);
		return;

	default:
		l = n->u0.s0.nleft;
		r = n->u0.s0.nright;
		if(l != Z)
			acom(l);
		if(r != Z)
			acom(r);
		return;
	}

	/* bust terms out */
	t = n->type;
	term[0].mult = 0;
	term[0].node = Z;
	nterm = 1;
	acom1(1, n);
	if(debug['m'])
	for(i=0; i<nterm; i++) {
		print("%d %3lld ", i, term[i].mult);
		prtree1(term[i].node, 1, 0);
	}
	if(nterm < NTERM)
		acom2(n, t);
	n->type = t;
}

int
acomcmp1(void *a1, void *a2)
{
	vlong c1, c2;
	Term *t1, *t2;

	t1 = a1;
	t2 = a2;
	c1 = t1->mult;
	if(c1 < 0)
		c1 = -c1;
	c2 = t2->mult;
	if(c2 < 0)
		c2 = -c2;
	if(c1 > c2)
		return 1;
	if(c1 < c2)
		return -1;
	c1 = 1;
	if(t1->mult < 0)
		c1 = 0;
	c2 = 1;
	if(t2->mult < 0)
		c2 = 0;
	if(c2 -= c1)
		return c2;
	if(t2 > t1)
		return 1;
	return -1;
}

int
acomcmp2(void *a1, void *a2)
{
	vlong c1, c2;
	Term *t1, *t2;

	t1 = a1;
	t2 = a2;
	c1 = t1->mult;
	c2 = t2->mult;
	if(c1 > c2)
		return 1;
	if(c1 < c2)
		return -1;
	if(t2 > t1)
		return 1;
	return -1;
}

void
acom2(Node *n, Type *t)
{
	Node *l, *r;
	Term trm[NTERM];
	int k, nt, i, j;
	vlong c1, c2;

	/*
	 * copy into automatic
	 */
	c2 = 0;
	nt = nterm;
	for(i=0; i<nt; i++)
		trm[i] = term[i];
	/*
	 * recur on subtrees
	 */
	k = 0;
	for(i=1; i<nt; i++) {
		c1 = trm[i].mult;
		if(c1 == 0)
			continue;
		l = trm[i].node;
		if(l != Z) {
			k = 1;
			acom(l);
		}
	}
	c1 = trm[0].mult;
	if(k == 0) {
		n->op = OCONST;
		n->u0.nvconst = c1;
		return;
	}
	k = ewidth[t->etype];

	/*
	 * prepare constant term,
	 * combine it with an addressing term
	 */
	if(c1 != 0) {
		l = new1(OCONST, Z, Z);
		l->type = t;
		l->u0.nvconst = c1;
		trm[0].mult = 1;
		for(i=1; i<nt; i++) {
			if(trm[i].mult != 1)
				continue;
			r = trm[i].node;
			if(r->op != OADDR)
				continue;
			r->type = t;
			l = new1(OADD, r, l);
			l->type = t;
			trm[i].mult = 0;
			break;
		}
		trm[0].node = l;
	}
	/*
	 * look for factorable terms
	 * c1*i + c1*c2*j -> c1*(i + c2*j)
	 */
	qsort(trm+1, nt-1, sizeof(trm[0]), acomcmp1);
	for(i=nt-1; i>=0; i--) {
		c1 = trm[i].mult;
		if(c1 < 0)
			c1 = -c1;
		if(c1 <= 1)
			continue;
		for(j=i+1; j<nt; j++) {
			c2 = trm[j].mult;
			if(c2 < 0)
				c2 = -c2;
			if(c2 <= 1)
				continue;
			if(c2 % c1)
				continue;
			r = trm[j].node;
			if(ewidth[r->type->etype] != k) {
				r = new1(OCAST, r, Z);
				r->type = t;
			}
			c2 = trm[j].mult/trm[i].mult;
			if(c2 != 1 && c2 != -1) {
				r = new1(OMUL, r, new(OCONST, Z, Z));
				r->type = t;
				r->u0.s0.nright->type = t;
				r->u0.s0.nright->u0.nvconst = c2;
			}
			l = trm[i].node;
			if(ewidth[l->type->etype] != k) {
				l = new1(OCAST, l, Z);
				l->type = t;
			}
			r = new1(OADD, l, r);
			r->type = t;
			if(c2 == -1)
				r->op = OSUB;
			trm[i].node = r;
			trm[j].mult = 0;
		}
	}
	if(debug['m']) {
		print("\n");
		for(i=0; i<nt; i++) {
			print("%d %3lld ", i, trm[i].mult);
			prtree1(trm[i].node, 1, 0);
		}
	}

	/*
	 * put it all back together
	 */
	qsort(trm+1, nt-1, sizeof(trm[0]), acomcmp2);
	l = Z;
	for(i=nt-1; i>=0; i--) {
		c1 = trm[i].mult;
		if(c1 == 0)
			continue;
		r = trm[i].node;
		if(ewidth[r->type->etype] != k || r->op == OBIT) {
			r = new1(OCAST, r, Z);
			r->type = t;
		}
		if(c1 != 1 && c1 != -1) {
			r = new1(OMUL, r, new(OCONST, Z, Z));
			r->type = t;
			r->u0.s0.nright->type = t;
			if(c1 < 0) {
				r->u0.s0.nright->u0.nvconst = -c1;
				c1 = -1;
			} else {
				r->u0.s0.nright->u0.nvconst = c1;
				c1 = 1;
			}
		}
		if(l == Z) {
			l = r;
			c2 = c1;
			continue;
		}
		if(c1 < 0)
			if(c2 < 0)
				l = new1(OADD, l, r);
			else
				l = new1(OSUB, l, r);
		else
			if(c2 < 0) {
				l = new1(OSUB, r, l);
				c2 = 1;
			} else
				l = new1(OADD, l, r);
		l->type = t;
	}
	if(c2 < 0) {
		r = new1(OCONST, 0, 0);
		r->u0.nvconst = 0;
		r->type = t;
		l = new1(OSUB, r, l);
		l->type = t;
	}
	*n = *l;
}

void
acom1(vlong v, Node *n)
{
	Node *l, *r;

	if(v == 0 || nterm >= NTERM)
		return;
	if(!addo(n)) {
		if(n->op == OCONST)
		if(!typefd[n->type->etype]) {
			term[0].mult += v*n->u0.nvconst;
			return;
		}
		term[nterm].mult = v;
		term[nterm].node = n;
		nterm++;
		return;
	}
	switch(n->op) {

	case OCAST:
		acom1(v, n->u0.s0.nleft);
		break;

	case OADD:
		acom1(v, n->u0.s0.nleft);
		acom1(v, n->u0.s0.nright);
		break;

	case OSUB:
		acom1(v, n->u0.s0.nleft);
		acom1(-v, n->u0.s0.nright);
		break;

	case OMUL:
		l = n->u0.s0.nleft;
		r = n->u0.s0.nright;
		if(l->op == OCONST)
		if(!typefd[n->type->etype]) {
			acom1(v*l->u0.nvconst, r);
			break;
		}
		if(r->op == OCONST)
		if(!typefd[n->type->etype]) {
			acom1(v*r->u0.nvconst, l);
			break;
		}

	default:
		diag(n, "not addo");
	}
}

int
addo(Node *n)
{

	if(n != Z)
	if(!typefd[n->type->etype])
	switch(n->op) {

	case OCAST:
		if(nilcast(n->u0.s0.nleft->type, n->type))
			return 1;
		break;

	case OADD:
	case OSUB:
		return 1;

	case OMUL:
		if(n->u0.s0.nleft->op == OCONST)
			return 1;
		if(n->u0.s0.nright->op == OCONST)
			return 1;
	}
	return 0;
}
