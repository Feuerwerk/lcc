# conversion
#pragma mark - to int

reg: CVII2(reg) {
    lda %0
    and #$00ff
    bit #$0080
    beq @ok
    ora #$ff00
@ok
    sta %c
} 5

reg: CVIU2(INDIRU1(vregp)) {
    lda %0
    and #$00ff
    sta %c
} 2

reg: CVUI2(INDIRU1(vregp)) {
	lda %0
    and #$00ff
    sta %c
} 2

#pragma mark - to long

# INDIRI2(vregp)
reg: CVII4(reg) {
	ldx #0
	lda %0
	bpl @ok
	dex
@ok
	sta %c
	stx %c+2
} 6
