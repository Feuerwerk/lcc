/********************************************
*
* QuickDraw II
*
* Copyright Apple Computer, Inc.1986-91
* All Rights Reserved
*
* Copyright 1992, 1993, Byte Works, Inc.
*
********************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __QUICKDRAW__
#define __QUICKDRAW__

/* Error Codes */
#define alreadyInitialized 0x0401       /* Quickdraw already initialized */
#define cannotReset 0x0402              /* never used */
#define notInitialized 0x0403           /* Quickdraw not initialized */
#define screenReserved 0x0410           /* screen reserved */
#define badRect 0x0411                  /* bad rectangle */
#define notEqualChunkiness 0x0420       /* Chunkiness is not equal */
#define rgnAlreadyOpen 0x0430           /* region is already open */
#define rgnNotOpen 0x0431               /* region is not open */
#define rgnScanOverflow 0x0432          /* region scan overflow */
#define rgnFull 0x0433                  /* region is full */
#define polyAlreadyOpen 0x0440          /* poly is already open */
#define polyNotOpen 0x0441              /* poly is not open */
#define polyTooBig 0x0442               /* poly is too big */
#define badTableNum 0x0450              /* bad table number */
#define badColorNum 0x0451              /* bad color number */
#define badScanLine 0x0452              /* bad scan line */
#define notImplemented 0x04FF           /* not implemented */

#define tsNumber 0x04

/* AnSCBByte Masks */
#define _colorTable 0x0F                /* Mask for SCB color table */
#define scbReserved 0x10                /* Mask for SCB reserved bit */
#define scbFill 0x20                    /* Mask for SCB fill bit */
#define scbInterrupt 0x40               /* Mask for SCB interrupt bit */
#define scbColorMode 0x80               /* Mask for SCB color mode bit */

/* ColorData */
#define table320 0x32                   /* (val=size) */
#define table640 0x32                   /* (val=size) */

/* ColorValue */
#define blueMask 0x000F                 /* Mask for Blue nibble */
#define greenMask 0x00F0                /* Mask for green nibble */
#define redMask 0x0F00                  /* Mask for red nibble */

/* FontFlags */
#define widMaxSize 0x0001
#define zeroSize 0x0002

/* GrafPort Sizes */
#define maskSize 0x08                   /* Mask Size (val=size) */
#define locSize 0x10                    /* Loc Size (val=size) */
#define patsize 0x20                    /* Pattern Size (val=size) */
#define pnStateSize 0x32                /* Pen State Size (Val=size) */
#define portSize 0xAA                   /* Size of GrafPort */

/* MasterColors */
#define black 0x000                     /* These work in 320 and 640 mode */
#define blue 0x00F                      /* These work in 320 and 640 mode */
#define darkGreen320 0x080              /* These work in 320 mode */
#define green320 0x0E0                  /* These work in 320 mode */
#define green640 0x0F0                  /* These work in 640 mode */
#define lightBlue320 0x4DF              /* These work in 320 mode */
#define purple320 0x72C                 /* These work in 320 mode */
#define darkGray320 0x777               /* These work in 320 mode */
#define periwinkleBlue320 0x78F         /* These work in 320 mode */
#define brown320 0x841                  /* These work in 320 mode */
#define lightGray320 0x0CCC             /* These work in 320 mode */
#define red320 0x0D00                   /* These work in 320 mode */
#define lilac320 0x0DAF                 /* These work in 320 mode */
#define red640 0x0F00                   /* These work in 640 mode */
#define orange320 0x0F70                /* These work in 320 mode */
#define flesh320 0x0FA9                 /* These work in 320 mode */
#define yellow 0x0FF0                   /* These work in 320 and 640 mode */
#define white 0x0FFF                    /* These work in 320 and 640 mode */

/* PenMode Data */
#define modeCopy 0x0000
#define modeOR 0x0001
#define modeXOR 0x0002
#define modeBIC 0x0003
#define modeForeCopy 0x0004
#define modeForeOR 0x0005
#define modeForeXOR 0x0006
#define modeForeBIC 0x0007
#define modeNOT 0x8000
#define notCopy 0x8000
#define notOR 0x8001
#define notXOR 0x8002
#define notBIC 0x8003
#define notForeCOPY 0x8004
#define notForeOR 0x8005
#define notForeXOR 0x8006
#define notForeBIC 0x8007

/* QDStartup */
#define mode320 0x0000                  /* Argument to QDStartup */
#define mode640 0x0080                  /* Argument to QDStartup */

typedef Integer ColorValue;
typedef Byte AnSCBByte;
struct Cursor {
   Word cursorHeight;                   /* size in bytes */
   Word cursorWidth;                    /* enclosing rectangle */
   Word cursorData[1]; 
   Word cursorMask[1]; 
   Point cursorHotSpot; 
   };
typedef struct Cursor Cursor, *CursorPtr, **CursorHndl;

struct BufDimRec {
   Word maxWidth; 
   Word textBufHeight; 
   Word textBufferWords; 
   Word fontWidth; 
   };
typedef struct BufDimRec BufDimRec, *BufDimRecPtr, **BufDimRecHndl;

struct FontGlobalsRecord {
   Word fgFontID;                       /* currently 12 bytes long, but may be expanded */
   TextStyle fgStyle; 
   Word fgSize; 
   Word fgVersion; 
   Word fgWidMax; 
   Word fgFBRExtent; 
   };
typedef struct FontGlobalsRecord FontGlobalsRecord, *FontGlobalsRecPtr, **FontGlobalsRecHndl;

struct FontInfoRecord {
   Word ascent; 
   Word descent; 
   Word widMax; 
   Word leading; 
   };
typedef struct FontInfoRecord FontInfoRecord, *FontInfoRecPtr, **FontInfoRecHndl;

struct PaintParam {
   LocInfoPtr ptrToSourceLocInfo; 
   LocInfoPtr ptrToDestLocInfo; 
   Rect *ptrToSourceRect; 
   Point *ptrToDestPoint; 
   Word mode; 
   Handle maskHandle;                   /* clip region */
   };
typedef struct PaintParam PaintParam, *PaintParamPtr, **PaintParamHndl;

struct PenState {
   Point psPenLoc;
   Point psPenSize;
   Word psPenMode;
   Pattern psPenPat;
   Mask psPenMask; 
   };
typedef struct PenState PenState, *PenStatePtr, **PenStateHndl;

struct RomFontRec {
   Word rfFamNum; 
   Word rfFamStyle; 
   Word rfSize; 
   FontHndl rfFontHandle; 
   Pointer rfNamePtr; 
   Word rfFBRExtent; 
   };
typedef struct RomFontRec RomFontRec, *RomFontRecPtr, **RomFontRecHndl;

extern pascal void QDBootInit(void) inline(0x0104,dispatcher);
extern pascal void QDStartUp(Word, Word, Word, Word) inline(0x0204,dispatcher);
extern pascal void QDShutDown(void) inline(0x0304,dispatcher);
extern pascal Word QDVersion(void) inline(0x0404,dispatcher);
extern pascal void QDReset(void) inline(0x0504,dispatcher);
extern pascal Boolean QDStatus(void) inline(0x0604,dispatcher);
extern pascal void AddPt(Point *, Point *) inline(0x8004,dispatcher);
extern pascal void CharBounds(Word, Rect *) inline(0xAC04,dispatcher);
extern pascal Word CharWidth(Word) inline(0xA804,dispatcher);
extern pascal void ClearScreen(Word) inline(0x1504,dispatcher);
extern pascal void ClipRect(Rect *) inline(0x2604,dispatcher);
extern pascal void ClosePoly(void) inline(0xC204,dispatcher);
extern pascal void ClosePort(GrafPortPtr) inline(0x1A04,dispatcher);
extern pascal void CloseRgn(RegionHndl) inline(0x6E04,dispatcher);
extern pascal void CopyRgn(RegionHndl, RegionHndl) inline(0x6904,dispatcher);
extern pascal void CStringBounds(Pointer, Rect *) inline(0xAE04,dispatcher);
extern pascal Word CStringWidth(Pointer) inline(0xAA04,dispatcher);
extern pascal void DiffRgn(RegionHndl, RegionHndl, RegionHndl) inline(0x7304,dispatcher);
extern pascal void DisposeRgn(RegionHndl) inline(0x6804,dispatcher);
extern pascal void DrawChar(Word) inline(0xA404,dispatcher);
extern pascal void DrawCString(Pointer) inline(0xA604,dispatcher);
extern pascal void DrawString(Pointer) inline(0xA504,dispatcher);
extern pascal void DrawText(Pointer, Word) inline(0xA704,dispatcher);
extern pascal Boolean EmptyRgn(RegionHndl) inline(0x7804,dispatcher);
extern pascal Boolean EqualPt(Point *, Point *) inline(0x8304,dispatcher);
extern pascal Boolean EqualRect(Rect *, Rect *) inline(0x5104,dispatcher);
extern pascal Boolean EqualRgn(RegionHndl, RegionHndl) inline(0x7704,dispatcher);
extern pascal void EraseArc(Rect *, Integer, Integer) inline(0x6404,dispatcher);
extern pascal void EraseOval(Rect *) inline(0x5A04,dispatcher);
extern pascal void ErasePoly(Handle) inline(0xBE04,dispatcher);
extern pascal void EraseRect(Rect *) inline(0x5504,dispatcher);
extern pascal void EraseRgn(RegionHndl) inline(0x7B04,dispatcher);
extern pascal void EraseRRect(Rect *, Word, Word) inline(0x5F04,dispatcher);
extern pascal void FillArc(Rect *, Integer, Integer, Pattern) inline(0x6604,dispatcher);
extern pascal void FillOval(Rect *, Pattern) inline(0x5C04,dispatcher);
extern pascal void FillPoly(Handle, Pattern) inline(0xC004,dispatcher);
extern pascal void FillRect(Rect *, Pattern) inline(0x5704,dispatcher);
extern pascal void FillRgn(RegionHndl, Pattern) inline(0x7D04,dispatcher);
extern pascal void FillRRect(Rect *, Word, Word, Pattern) inline(0x6104,dispatcher);
extern pascal void ForceBufDims(Word, Word, Word) inline(0xCC04,dispatcher);
extern pascal void FrameArc(Rect *, Integer, Integer) inline(0x6204,dispatcher);
extern pascal void FrameOval(Rect *) inline(0x5804,dispatcher);
extern pascal void FramePoly(Handle) inline(0xBC04,dispatcher);
extern pascal void FrameRect(Rect *) inline(0x5304,dispatcher);
extern pascal void FrameRgn(RegionHndl) inline(0x7904,dispatcher);
extern pascal void FrameRRect(Rect *, Word, Word) inline(0x5D04,dispatcher);
extern pascal Pointer GetAddress(Word) inline(0x0904,dispatcher);
extern pascal Word GetArcRot(void) inline(0xB104,dispatcher);
extern pascal Word GetBackColor(void) inline(0xA304,dispatcher);
extern pascal void GetBackPat(Pattern) inline(0x3504,dispatcher);
extern pascal Fixed GetCharExtra(void) inline(0xD504,dispatcher);
extern pascal void GetClip(RegionHndl) inline(0x2504,dispatcher);
extern pascal RegionHndl GetClipHandle(void) inline(0xC704,dispatcher);
extern pascal Word GetColorEntry(Word, Word) inline(0x1104,dispatcher);
extern pascal void GetColorTable(Word, ColorTable) inline(0x0F04,dispatcher);
extern pascal Pointer GetCursorAdr(void) inline(0x8F04,dispatcher);
extern pascal Word GetFGSize(void) inline(0xCF04,dispatcher);
extern pascal FontHndl GetFont(void) inline(0x9504,dispatcher);
extern pascal Word GetFontFlags(void) inline(0x9904,dispatcher);
extern pascal void GetFontGlobals(FontGlobalsRecPtr) inline(0x9704,dispatcher);
extern pascal Long GetFontID(void) inline(0xD104,dispatcher);
extern pascal void GetFontInfo(FontInfoRecPtr) inline(0x9604,dispatcher);
extern pascal Word GetFontLore(FontGlobalsRecPtr, Word) inline(0xD904,dispatcher);
extern pascal Word GetForeColor(void) inline(0xA104,dispatcher);
extern pascal QDProcsPtr GetGrafProcs(void) inline(0x4504,dispatcher);
extern pascal Word GetMasterSCB(void) inline(0x1704,dispatcher);
extern pascal void GetPen(Point *) inline(0x2904,dispatcher);
extern pascal void GetPenMask(Mask) inline(0x3304,dispatcher);
extern pascal Word GetPenMode(void) inline(0x2F04,dispatcher);
extern pascal void GetPenPat(Pattern) inline(0x3104,dispatcher);
extern pascal void GetPenSize(Point *) inline(0x2D04,dispatcher);
extern pascal void GetPenState(PenStatePtr) inline(0x2B04,dispatcher);
extern pascal Longint GetPicSave(void) inline(0x3F04,dispatcher);
extern pascal Word GetPixel(Integer, Integer) inline(0x8804,dispatcher);
extern pascal LongWord GetPolySave(void) inline(0x4304,dispatcher);
extern pascal GrafPortPtr GetPort(void) inline(0x1C04,dispatcher);
extern pascal void GetPortLoc(LocInfoPtr) inline(0x1E04,dispatcher);
extern pascal void GetPortRect(Rect *) inline(0x2004,dispatcher);
extern pascal LongWord GetRgnSave(void) inline(0x4104,dispatcher);
extern pascal void GetROMFont(RomFontRecPtr) inline(0xD804,dispatcher);
extern pascal void GetRomFont(RomFontRecPtr) inline(0xD804,dispatcher);
extern pascal Word GetSCB(Word) inline(0x1304,dispatcher);
extern pascal Fixed GetSpaceExtra(void) inline(0x9F04,dispatcher);
extern pascal Word GetStandardSCB(void) inline(0x0C04,dispatcher);
extern pascal Longint GetSysField(void) inline(0x4904,dispatcher);
extern pascal FontHndl GetSysFont(void) inline(0xB304,dispatcher);
extern pascal TextStyle GetTextFace(void) inline(0x9B04,dispatcher);
extern pascal Word GetTextMode(void) inline(0x9D04,dispatcher);
extern pascal Word GetTextSize(void) inline(0xD304,dispatcher);
extern pascal Longint GetUserField(void) inline(0x4704,dispatcher);
extern pascal RegionHndl GetVisHandle(void) inline(0xC904,dispatcher);
extern pascal void GetVisRgn(RegionHndl) inline(0xB504,dispatcher);
extern pascal void GlobalToLocal(Point *) inline(0x8504,dispatcher);
extern pascal void GrafOff(void) inline(0x0B04,dispatcher);
extern pascal void GrafOn(void) inline(0x0A04,dispatcher);
extern pascal void HideCursor(void) inline(0x9004,dispatcher);
extern pascal void HidePen(void) inline(0x2704,dispatcher);
extern pascal void InflateTextBuffer(Word, Word) inline(0xD704,dispatcher);
extern pascal void InitColorTable(ColorTable) inline(0x0D04,dispatcher);
extern pascal void InitCursor(void) inline(0xCA04,dispatcher);
extern pascal void InitPort(GrafPortPtr) inline(0x1904,dispatcher);
extern pascal void InsetRect(Rect *, Integer, Integer) inline(0x4C04,dispatcher);
extern pascal void InsetRgn(RegionHndl, Integer, Integer) inline(0x7004,dispatcher);
extern pascal void InvertArc(Rect *, Integer, Integer) inline(0x6504,dispatcher);
extern pascal void InvertOval(Rect *) inline(0x5B04,dispatcher);
extern pascal void InvertPoly(Handle) inline(0xBF04,dispatcher);
extern pascal void InvertRect(Rect *) inline(0x5604,dispatcher);
extern pascal void InvertRgn(RegionHndl) inline(0x7C04,dispatcher);
extern pascal void InvertRRect(Rect *, Word, Word) inline(0x6004,dispatcher);
extern pascal void KillPoly(Handle) inline(0xC304,dispatcher);
extern pascal void Line(Integer, Integer) inline(0x3D04,dispatcher);
extern pascal void LineTo(Integer, Integer) inline(0x3C04,dispatcher);
extern pascal void LocalToGlobal(Point *) inline(0x8404,dispatcher);
extern pascal void MapPoly(Handle, Rect *, Rect *) inline(0xC504,dispatcher);
extern pascal void MapPt(Point *, Rect *, Rect *) inline(0x8A04,dispatcher);
extern pascal void MapRect(Rect *, Rect *, Rect *) inline(0x8B04,dispatcher);
extern pascal void MapRgn(RegionHndl, Rect *, Rect *) inline(0x8C04,dispatcher);
extern pascal void Move(Integer, Integer) inline(0x3B04,dispatcher);
extern pascal void MovePortTo(Integer, Integer) inline(0x2204,dispatcher);
extern pascal void MoveTo(Integer, Integer) inline(0x3A04,dispatcher);
extern pascal RegionHndl NewRgn(void) inline(0x6704,dispatcher);
extern pascal Boolean NotEmptyRect(Rect *) inline(0x5204,dispatcher);
extern pascal void ObscureCursor(void) inline(0x9204,dispatcher);
extern pascal void OffsetPoly(Handle, Integer, Integer) inline(0xC404,dispatcher);
extern pascal void OffsetRect(Rect *, Integer, Integer) inline(0x4B04,dispatcher);
extern pascal void OffsetRgn(RegionHndl, Integer, Integer) inline(0x6F04,dispatcher);
extern pascal handle OpenPoly(void) inline(0xC104,dispatcher);
extern pascal void OpenPort(GrafPortPtr) inline(0x1804,dispatcher);
extern pascal void OpenRgn(void) inline(0x6D04,dispatcher);
extern pascal void PaintArc(Rect *, Integer, Integer) inline(0x6304,dispatcher);
extern pascal void PaintOval(Rect *) inline(0x5904,dispatcher);
extern pascal void PaintPixels(PaintParamPtr) inline(0x7F04,dispatcher);
extern pascal void PaintPoly(Handle) inline(0xBD04,dispatcher);
extern pascal void PaintRect(Rect *) inline(0x5404,dispatcher);
extern pascal void PaintRgn(RegionHndl) inline(0x7A04,dispatcher);
extern pascal void PaintRRect(Rect *, Word, Word) inline(0x5E04,dispatcher);
extern pascal void PenNormal(void) inline(0x3604,dispatcher);
extern pascal void PPToPort(LocInfoPtr, Rect *, Integer, Integer, Word) inline(0xD604,dispatcher);
extern pascal void Pt2Rect(Point *, Point *, Rect *) inline(0x5004,dispatcher);
extern pascal Boolean PtInRect(Point *, Rect *) inline(0x4F04,dispatcher);
extern pascal Boolean PtInRgn(Point *, RegionHndl) inline(0x7504,dispatcher);
extern pascal Word Random(void) inline(0x8604,dispatcher);
extern pascal Boolean RectInRgn(Rect *, RegionHndl) inline(0x7604,dispatcher);
extern pascal void RectRgn(RegionHndl, Rect *) inline(0x6C04,dispatcher);
extern pascal void RestoreBufDims(BufDimRecPtr) inline(0xCE04,dispatcher);
extern pascal void SaveBufDims(BufDimRecPtr) inline(0xCD04,dispatcher);
extern pascal void ScalePt(Point *, Rect *, Rect *) inline(0x8904,dispatcher);
extern pascal void ScrollRect(Rect *, Integer, Integer, RegionHndl) inline(0x7E04,dispatcher);
extern pascal Boolean SectRect(Rect *, Rect *, Rect *) inline(0x4D04,dispatcher);
extern pascal void SectRgn(RegionHndl, RegionHndl, RegionHndl) inline(0x7104,dispatcher);
extern pascal void SetAllSCBs(Word) inline(0x1404,dispatcher);
extern pascal void SetArcRot(Integer) inline(0xB004,dispatcher);
extern pascal void SetBackColor(Word) inline(0xA204,dispatcher);
extern pascal void SetBackPat(Pattern) inline(0x3404,dispatcher);
extern pascal void SetBufDims(Word, Word, Word) inline(0xCB04,dispatcher);
extern pascal void SetCharExtra(Fixed) inline(0xD404,dispatcher);
extern pascal void SetClip(RegionHndl) inline(0x2404,dispatcher);
extern pascal void SetClipHandle(RegionHndl) inline(0xC604,dispatcher);
extern pascal void SetColorEntry(Word, Word, ColorValue) inline(0x1004,dispatcher);
extern pascal void SetColorTable(Word, ColorTable) inline(0x0E04,dispatcher);
extern pascal void SetCursor(Pointer) inline(0x8E04,dispatcher);
extern pascal void SetEmptyRgn(RegionHndl) inline(0x6A04,dispatcher);
extern pascal void SetFont(FontHndl) inline(0x9404,dispatcher);
extern pascal void SetFontFlags(Word) inline(0x9804,dispatcher);
extern pascal void SetFontID(FontID) inline(0xD004,dispatcher);
extern pascal void SetForeColor(Word) inline(0xA004,dispatcher);
extern pascal void SetGrafProcs(QDProcsPtr) inline(0x4404,dispatcher);
extern pascal void SetIntUse(Word) inline(0xB604,dispatcher);
extern pascal void SetMasterSCB(Word) inline(0x1604,dispatcher);
extern pascal void SetOrigin(Integer, Integer) inline(0x2304,dispatcher);
extern pascal void SetPenMask(Mask) inline(0x3204,dispatcher);
extern pascal void SetPenMode(Word) inline(0x2E04,dispatcher);
extern pascal void SetPenPat(Pattern) inline(0x3004,dispatcher);
extern pascal void SetPenSize(Word, Word) inline(0x2C04,dispatcher);
extern pascal void SetPenState(PenStatePtr) inline(0x2A04,dispatcher);
extern pascal void SetPicSave(Longint) inline(0x3E04,dispatcher);
extern pascal void SetPolySave(Longint) inline(0x4204,dispatcher);
extern pascal void SetPort(GrafPortPtr) inline(0x1B04,dispatcher);
extern pascal void SetPortLoc(LocInfoPtr) inline(0x1D04,dispatcher);
extern pascal void SetPortRect(Rect *) inline(0x1F04,dispatcher);
extern pascal void SetPortSize(Word, Word) inline(0x2104,dispatcher);
extern pascal void SetPt(Point *, Integer, Integer) inline(0x8204,dispatcher);
extern pascal void SetRandSeed(Longint) inline(0x8704,dispatcher);
extern pascal void SetRect(Rect *, Integer, Integer, Integer, Integer) inline(0x4A04,dispatcher);
extern pascal void SetRectRgn(RegionHndl, Integer, Integer, Integer, Integer) inline(0x6B04,dispatcher);
extern pascal void SetRgnSave(Handle) inline(0x4004,dispatcher);
extern pascal void SetSCB(Word, Word) inline(0x1204,dispatcher);
extern pascal void SetSolidBackPat(Word) inline(0x3804,dispatcher);
extern pascal void SetSolidPenPat(Word) inline(0x3704,dispatcher);
extern pascal void SetSpaceExtra(Fixed) inline(0x9E04,dispatcher);
extern pascal void SetStdProcs(QDProcsPtr) inline(0x8D04,dispatcher);
extern pascal void SetSysField(Longint) inline(0x4804,dispatcher);
extern pascal void SetSysFont(FontHndl) inline(0xB204,dispatcher);
extern pascal void SetTextFace(TextStyle) inline(0x9A04,dispatcher);
extern pascal void SetTextMode(Word) inline(0x9C04,dispatcher);
extern pascal void SetTextSize(Word) inline(0xD204,dispatcher);
extern pascal void SetUserField(Longint) inline(0x4604,dispatcher);
extern pascal void SetVisHandle(RegionHndl) inline(0xC804,dispatcher);
extern pascal void SetVisRgn(RegionHndl) inline(0xB404,dispatcher);
extern pascal void ShowCursor(void) inline(0x9104,dispatcher);
extern pascal void ShowPen(void) inline(0x2804,dispatcher);
extern pascal void SolidPattern(Word, Pattern) inline(0x3904,dispatcher);
extern pascal void StringBounds(Pointer, Rect *) inline(0xAD04,dispatcher);
extern pascal Word StringWidth(Pointer) inline(0xA904,dispatcher);
extern pascal void SubPt(Point *, Point *) inline(0x8104,dispatcher);
extern pascal void TextBounds(Pointer, Word, Rect *) inline(0xAF04,dispatcher);
extern pascal Word TextWidth(Pointer, Word) inline(0xAB04,dispatcher);
extern pascal void UnionRect(Rect *, Rect *, Rect *) inline(0x4E04,dispatcher);
extern pascal void UnionRgn(RegionHndl, RegionHndl, RegionHndl) inline(0x7204,dispatcher);
extern pascal void XorRgn(RegionHndl, RegionHndl, RegionHndl) inline(0x7404,dispatcher);

extern pascal PatternPtr Get640Colors(void) inline(0xDA04,dispatcher);
extern pascal void Set640Color(Word) inline(0xDB04,dispatcher);

#endif

