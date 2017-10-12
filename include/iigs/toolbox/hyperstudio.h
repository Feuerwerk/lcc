/****************************************************************
*
*  HyperStudio.h - Interface for HyperStudio
*
*  December 1992
*  Mike Westerfield
*
*  Thanks to Ken Kashmarek, who supplied the original files from
*  wich I shamelessly swiped the names used here.  (Of course,
*  that made it easier for him to convert his software!)
*
*  Copyright 1992, 1993
*  Byte Works, Inc.
*
****************************************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __hyperstudio__
#define __hyperstudio__

/* Callback numbers */

#define cMoveToFirst		1
#define cMoveToLast		2
#define cMovePrev		3
#define cMoveNext		4
#define cMoveToID		5
#define cRedrawCard		6
#define cGetStackName	        7
#define cFindText		8
#define cPokeyFlag		9
#define cDoMenu		        10
#define cGetHSMode		11
#define cGetHSVersion	        12
#define cGetStackPathName       13
#define cGetNumCards	        14
#define cGetNumButtons	        15
#define cGetNumFields	        16
#define cGetNumGraphics	        17
#define cPoint2StackHead        18
#define cPoint2FirstCard        19
#define cPoint2CurrCard	        20
#define cPoint2NextCard	        21
#define cPoint2CardItems        22
#define cPoint2NextCdItem       23
#define cPoint2StackItem        24
#define cGetCallerAddr	        25
#define cHideStackItem	        26
#define cShowStackItem	        27
#define cLockItem		28
#define cUnLockItem		29
#define cDeleteStackItem        30
#define cGetItemRect	        31
#define cSetItemRect	        32
#define cGetButtonIcon	        33
#define cSetButtonIcon	        34
#define cGetItemStats	        35
#define cLaunchApplication      36
#define cGetItemLoc		37
#define cRedrawItem		38
#define cMouseClick		39
#define cGetHSCursorAdr	        40
#define cPassText		41
#define cGetClickLoc	        42
#define cExecuteButton	        43
#define cScrollField	        44
#define cSetHSFont		45
#define cSetBrushNum	        46
#define cSetLineWidth	        47
#define cGetOffScreen	        48
#define cGetCurrentScore        49
#define cSetNextTransition      50
#define cIsMenuThere	        51
#define cGetUndoBuffer	        52
#define cGetCardPalette         53
#define cPlayDiskSound	        54
#define cPlayResSound	        55
#define cGetSelectedInfo        56
#define cGetPatterns	        57
#define cGetFieldText	        58
#define cSetFieldText	        59
#define cGetHSFont		60
#define cLoadPaintFile	        61
#define cSwapCardPos	        62
#define cSortCards		63
#define cSetDirtyFlag	        64
#define cAddScript2Button       65
#define cCreatePaletteWindow    66
#define cCallNBA		67
#define cCallHS_XCMD            68
#define cGetResRefNums	        69
#define cSetBkgdDirty	        70
#define cPlaySound		71
#define cGetAdvancedUser        72
#define cVideoOn		73
#define cVideoOff		74
#define cMakeTransMask	        75
#define cInitTrans		76
#define cIncTrans		77
#define cHorizStrip		78
#define cVertStrip		79
#define cBrushDialog	        80
#define cLineDialog		81
#define cPatternDialog	        82
#define cColorDialog	        83
#define cStartDrawing	        84
#define cDrawToScreen	        85
#define cDrawToOffScreen        86
#define cEndDrawing		87
#define cSetDrawColor	        88
#define cGetNewBtnName	        89
#define cGetSndStatus	        90
#define cSetMarkedCard	        91
#define cGetNewExtrasMenu       92
#define cGetOtherCursors        93
#define cDoButtonAnimation      94
#define cPlayAnimation	        95
#define cFlush2Undo		96
#define cLoadStackField	        97
#define cSaveStackField	        98
#define cPrintStackField        99
#define cLoadText		100
#define cSaveText		101
#define cPrintText		102
#define cGetPaintVars	        103
#define cGetItemHandle	        104
#define cBeginXSound	        105
#define cEndXSound		106
#define cGetColorCtlDefProc     107



#define mAboutHyperStudio	0
#define mPreferences		1
#define mNewStack		2
#define mOpenStack		3
#define mSaveStack		4
#define mSaveStackAs		5
#define mLoadBackground		6
#define mSaveBackground		7
#define mAddClipArt		8
#define mPageSetup		9
#define mPrint			10
#define mQuit			11
#define mUndo			12
#define mCut			13
#define mCopy			14
#define mPaste			15
#define mClear			16
#define mNewCard		17
#define mDeleteCard		18
#define mCutCard		19
#define mCopyCard		20
#define mFlipHorizontal		21
#define mFlipVertical		22
#define mEraseBackground	23
#define mBack			24
#define mHome			25
#define mFirstCard		26
#define mPreviousCard		27
#define mNextCard		28
#define mLastCard		29
#define mMoveToCard		30
#define mFindText		31
#define mSetCurrentTool		32
#define mItemInfo		33
#define mCardInfo		34
#define mBackgroundInfo		35
#define mStackInfo		36
#define mBringCloser		37
#define mSendFarther		38
#define mAddButton		39
#define mAddGraphic		40
#define mAddField		41
#define mAddVideo		42
#define mSetCurrentColor	43
#define mLineSizedialog		44
#define mBrushShapedialog	45
#define mToggleDrawFilled	46
#define mToggleDrawMultiple	47
#define mToggleDrawCentered	48
#define mTextStyledialog	49
#define mTextColordialog	50
#define mBackgroundColordialog	51
#define mReplaceColorsdialog	52
#define mEditPattern            53
#define mStandardPaletteRestore 54
#define mHideItems              55
#define mToggleMenubarVisibility 56
      
typedef struct wdString {		/* word string */
  word length;
  char string[];
  } wdString, *wdStringPtr;

typedef struct HSParams {		/* HyperStudio parameters */
  word ButtonID;
  word CardID;
  handle ScriptHand;
  longword ScriptLength;
  wdString *TextPassedPtr;
  ptr CallBack;
  word Version;
  word MemoryID;
  word Command;
  word SubCommand;
  longword CP1;
  longword CP2;
  longword CP3;
  longword CP4;
  longword CP5;
  } HSParams, *HSParamPtr;

extern pascal void __NBACALLBACK (int, HSParamPtr);

#endif
