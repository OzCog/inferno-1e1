#include "limbo.h"

void
dtocanon(double f, ulong v[])
{
	union { double d; ulong ul[2]; } a;

	a.d = 1.;
	if(a.ul[0]){
		a.d = f;
		v[0] = a.ul[0];
		v[1] = a.ul[1];
	}else{
		a.d = f;
		v[0] = a.ul[1];
		v[1] = a.ul[0];
	}
}
