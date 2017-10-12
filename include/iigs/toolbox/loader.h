/********************************************
*
* Loader
*
* Copyright Apple Computer, Inc.1986-90
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __LOADER__
#define __LOADER__

/* Error Codes */
#define idNotFound 0x1101               /* segment/application/entry not found */
#define idPathnameErr 0x1103
#define idNotLoadFile 0x1104            /* file is not a load file */
#define idBusyErr 0x1105                /* system loader is busy */
#define idFilVersErr 0x1107             /* file version error */
#define idUserIDErr 0x1108              /* user ID error */
#define idSequenceErr 0x1109            /* segnum out of sequence */
#define idBadRecordErr 0x110A           /* illegal load record found */
#define idForeignSegErr 0x110B          /* segment is foreign */

struct InitialLoadOutputRec {
   Word userID;
   Pointer startAddr;
   Word dPageAddr;
   Word buffSize;
   };
typedef struct InitialLoadOutputRec InitialLoadOutputRec, *InitialLoadOutputRecPtr;

struct RestartOutRec {
   Word userID;
   Pointer startAddr;
   Word dPageAddr;
   Word buffSize;
   };
typedef struct RestartOutRec RestartOutRec, *RestartOutRecPtr;

struct LoadSegNameOut {
   Pointer segAddr;
   Word userID;
   Word fileNum;
   Word segNum;
   };
typedef struct LoadSegNameOut LoadSegNameOut, *LoadSegNameOutPtr;

struct UnloadSegOutRec {
   Word userID;
   Word fileNum;
   Word segNum;
   };
typedef struct UnloadSegOutRec UnloadSegOutRec, *UnloadSegOutRecPtr;

extern pascal void GetLoadSegInfo(Word, Word, Word, Pointer) inline(0x0F11,dispatcher);
extern pascal Word GetUserID(Pointer) inline(0x1011,dispatcher);
extern pascal Word GetUserID2(Pointer) inline(0x2111,dispatcher);
extern pascal InitialLoadOutputRec InitialLoad(Word, Pointer, Word) inline(0x0911,dispatcher);
extern pascal InitialLoadOutputRec InitialLoad2(Word, Pointer, Word, Word) inline(0x2011,dispatcher);
extern pascal Pointer LGetPathname(Word, Word) inline(0x1111,dispatcher);
extern pascal Pointer LGetPathname2(Word, Word) inline(0x2211,dispatcher);
extern pascal void LoaderInitialization(void) inline(0x0111,dispatcher);
extern pascal void LoaderReset(void) inline(0x0511,dispatcher);
extern pascal void LoaderShutDown(void) inline(0x0311,dispatcher);
extern pascal void LoaderStartUp(void) inline(0x0211,dispatcher);
extern pascal Boolean LoaderStatus(void) inline(0x0611,dispatcher);
extern pascal Word LoaderVersion(void) inline(0x0411,dispatcher);
extern pascal LoadSegNameOut LoadSegName(Word, Pointer, Pointer) inline(0x0D11,dispatcher);
extern pascal Pointer LoadSegNum(Word, Word, Word) inline(0x0B11,dispatcher);
extern pascal void RenamePathname(Pointer, Pointer) inline(0x1311,dispatcher);
extern pascal RestartOutRec Restart(Word) inline(0x0A11,dispatcher);
extern pascal UnloadSegOutRec UnloadSeg(Longword) inline(0x0E11,dispatcher);
extern pascal void UnloadSegNum(Word, Word, Word) inline(0x0C11,dispatcher);
extern pascal Word UserShutDown(Word, Word) inline(0x1211,dispatcher);



#endif
