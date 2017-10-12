/********************************************
*
* Audio Compression and Expansion Tool Set
*
* Copyright Apple Computer, Inc.1986-91
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __ACE__
#define __ACE__

/* Error Codes */
#define aceNoError 0x0000
#define aceIsActive 0x1D01
#define aceBadDP 0x1D02
#define aceNotActive 0x1D03
#define aceNoSuchParam 0x1D04
#define aceBadMethod 0x1D05
#define aceBadSrc 0x1D06
#define aceBadDest 0x1D07
#define aceDataOverlap 0x1D08
#define aceNotImplemented 0x1DFF

extern pascal void ACEBootInit(void) inline(0x011D,dispatcher);
extern pascal void ACEStartUp(Word) inline(0x021D,dispatcher);
extern pascal void ACEShutDown(void) inline(0x031D,dispatcher);
extern pascal Word ACEVersion(void) inline(0x041D,dispatcher);
extern pascal void ACEReset(void) inline(0x051D,dispatcher);
extern pascal Boolean ACEStatus(void) inline(0x061D,dispatcher);
extern pascal LongWord ACEInfo(Word) inline(0x071D,dispatcher);
extern pascal void ACECompBegin(void) inline(0x0B1D,dispatcher);
extern pascal void ACECompress(Handle, Long, Handle, Long, Word, Word) inline(0x091D,dispatcher);
extern pascal void ACEExpand(Handle, Long, Handle, Long, Word, Word) inline(0x0A1D,dispatcher);
extern pascal void ACEExpBegin(void) inline(0x0C1D,dispatcher);

extern pascal void GetACEExpState(Ptr) inline(0x0D1D,dispatcher);
extern pascal void SetACEExpState(Ptr) inline(0x0E1D,dispatcher);

#endif
