struct Ureg
{
	ulong	cause;		/* SRR1 */
	ulong	badvaddr;	/* DAR */
	ulong	pc;		/* SRR0 */
	ulong	lr;
	ulong	cr;
	ulong	mq;		/* not in 64-bit implementations */
	ulong	xer;
	ulong	ctr;
	ulong	r0;
	union{ ulong r1;	ulong	sp;	ulong	usp; };
	ulong	r2;
	ulong	r3;
	ulong	r4;
	ulong	r5;
	ulong	r6;
	ulong	r7;
	ulong	r8;
	ulong	r9;
	ulong	r10;
	ulong	r11;
	ulong	r12;
	ulong	r13;
	ulong	r14;
	ulong	r15;
	ulong	r16;
	ulong	r17;
	ulong	r18;
	ulong	r19;
	ulong	r20;
	ulong	r21;
	ulong	r22;
	ulong	r23;
	ulong	r24;
	ulong	r25;
	ulong	r26;
	ulong	r27;
	ulong	r28;
	ulong	r29;
	ulong	r30;
	ulong	r31;
};
