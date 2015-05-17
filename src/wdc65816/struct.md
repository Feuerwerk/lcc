#
# structs and such
#
#

%{
#define struct_size_is(p,x) (p->syms[0] && p->syms[0]->u.c.v.i == x ? 0 : LBURG_MAX)

void copy_struct(Node p, Node *kids, short *nts) {
	int size = (p->syms[0]->u.c.v.i + 1) & ~0x01;

	if (size <= 10) {
		int i;
		int ofs = framesize; // hacky...
		for (i = 0; i < size; i += 2) {
			framesize = i;
			EMIT(
				_("lda %1+%F")
				_("sta %0+%F")
			);

		}
		framesize = ofs;
		return;
	}

	EMIT(
			_("ldx #0")
	__("@loop:")
			_("lda %1,x")
			_("sta %0,x")
			_("inx")
			_("inx")
			_("cpx #%a")
			_("bne @loop")
	);
}


void copy_struct_indirect(Node p, Node *kids, short *nts) {
	int size = (p->syms[0]->u.c.v.i + 1) & ~0x01;

	if (size <= 10) {
		int i;
		int ofs = framesize; // hacky... but easy way to pass a number via %F.

		if (size >= 2) {
			EMIT(
				_("lda %1")
				_("sta [%0]")
			);
		}
		for (i = 2; i < size; i += 2) {
			framesize = i;
			EMIT(
				_("lda %1+%F")
				_("ldy #%F")
				_("sta [%0],y")
			);

		}
		framesize = ofs;
		return;
	}

	EMIT(
			_("ldx #0")
	__("@loop:")
			_("txy")
			_("lda %1,x")
			_("sta [%0],y")
			_("inx")
			_("inx")
			_("cpx #%a")
			_("bne @loop")
	);
}


%}

# *struct = struct

stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) ^{
	// returning struct via pascal?
	if (kids[0]->syms[0] && kids[0]->syms[0] == retv) {
		copy_struct(p, kids, nts);
		return;
	}
	copy_struct_indirect(p, kids, nts);
}

#struct = struct
stmt: ASGNB(vregp, INDIRB(address)) ^{
	copy_struct(p, kids, nts);
}

%{
/*	
stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) {
	; asgnb 
	ldx #0

@loop:
	txy
	lda %1,x
	sta [%0],y
	inx
	inx
	cpx #%a
	bne @loop
} 20




stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) {
	lda %1
	sta [%0]
} struct_size_is(a, 2)

stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) {
	lda %1
	sta [%0]

	lda %1+2
	ldy #2
	sta [%0],y
} struct_size_is(a, 4)

stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) {
	lda %1
	sta [%0]

	lda %1+2
	ldy #2
	sta [%0],y

	lda %1+4
	ldy #4
	sta [%0],y
} struct_size_is(a, 6)

stmt: ASGNB(INDIRP4(vregp),INDIRB(vregp)) {
	lda %1
	sta [%0]

	lda %1+2
	ldy #2
	sta [%0],y

	lda %1+4
	ldy #4
	sta [%0],y

	lda %1+6
	ldy #6
	sta [%0],y
} struct_size_is(a, 8)

stmt: ASGNB(vregp, INDIRB(address)) {
	lda >%1
	sta %0
} struct_size_is(a, 2)

stmt: ASGNB(vregp, INDIRB(address)) {
	lda >%1
	sta %0

	lda >%1+2
	sta %0+2
} struct_size_is(a, 4)

stmt: ASGNB(vregp, INDIRB(address)) {
	lda >%1
	sta %0

	lda >%1+2
	sta %0+2

	lda >%1+4
	sta %0+4
} struct_size_is(a, 6)

*/

%}




# struct = struct (pascal return)
stmt: ASGNB(INDIRP4(addressDP), INDIRB(vregp)) {
	

}



# argb

stmt: ARGB(INDIRB(vregp)) {
	; argb
	ldx #0

@loop:
	lda %0+%a-2,x
	pha
	inx
	inx
	cpx #%a
	bne @loop
} 20

stmt: ARGB(INDIRB(vregp)) {
	; argb %a
	pei %0
} struct_size_is(a, 2)

stmt: ARGB(INDIRB(vregp)) {
	; argb %a
	pei %0+2
	pei %0+0
} struct_size_is(a, 4)

stmt: ARGB(INDIRB(vregp)) {
	; argb %a
	pei %0+4
	pei %0+2
	pei %0+0
} struct_size_is(a, 6)

stmt: ARGB(INDIRB(vregp)) {
	; argb %a
	pei %0+6
	pei %0+4
	pei %0+2
	pei %0+0
} struct_size_is(a, 8)

stmt: ARGB(INDIRB(vregp)) {
	; argb %a
	pei %0+8
	pei %0+6
	pei %0+4
	pei %0+2
	pei %0+0
} struct_size_is(a, 10)

#
