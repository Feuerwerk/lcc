/********************************************
*
* Menu Manager
*
* Copyright Apple Computer, Inc. 1986-91
* All Rights Reserved
*
* CopyRight 1992, Byte Works, Inc.
*
********************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __MENU__
#define __MENU__

/* error codes */
#define menuStarted 0x0F01
#define menuItemNotFound 0x0F02
#define menuNoStruct 0x0F03
#define dupMenuID 0x0F04

/* InsertPathMItems bit flags */
#define ipmiNotExpanded 0x0010
#define ipmiDevNumValid 0x0008
#define ipmiOpenFolders 0x0004
#define ipmiDeviceAtTop 0x0001

/* MenuDefProc Codes */
#define mDrawMsg 0x0000
#define mChooseMsg 0x0001
#define mSizeMsg 0x0002
#define mDrawTitle 0x0003
#define mDrawMItem 0x0004
#define mGetMItemID 0x0005

/* Reference Flags */
#define menuRefPtr 0x0000
#define mRefHandle 0x4000
#define mRefResource 0x8000

/* Menu Flags */
#define menuAllowCache 0x0008
#define menuCustom 0x0010
#define menuXOR 0x0020
#define menuDisabled 0x0080
#define menuAlwaysCallMChoose 0x0100

/* Item Flags */
#define itemBold 0x0001
#define itemItalic 0x0002
#define itemUnderline 0x0004
#define itemXOR 0x0020
#define itemDivider 0x0040
#define itemDisabled 0x0080
#define itemOutline 0x0800
#define itemShadow 0x1000

/* Old Menu Flags */
#define mInvis 0x0004
#define mCustom 0x0010
#define mXor 0x0020
#define mSelected 0x0040
#define mDisabled 0x0080

/* MenuFlag Masks */
#define menuCacheMask 0x0008
#define customMenu 0x0010
#define xorMItemHilite 0x0020
#define xorTitleHilite 0x0020
#define underMItem 0x0040
#define disableItem 0x0080
#define disableMenu 0x0080
#define enableItem 0xFF7F
#define enableMenu 0xFF7F
#define noUnderMItem 0xFFBF
#define colorMItemHilite 0xFFDF
#define colorTitleHilite 0xFFDF
#define colorReplace 0xFFDF
#define standardMenu 0xFFEF

/* Other misc constants */
#define type2 0x0040

#ifndef mtItemRefArrayLength            /* MenuTemplate - default number of Ref's */
#define mtItemRefArrayLength 0x0005
#endif
#ifndef mbtMenuRefArrayLength           /* MenuBarTemplate - default number of Ref's */
#define mbtMenuRefArrayLength 0x0005
#endif

typedef CtlRec MenuBarRec, *MenuBarRecPtr, **MenuBarRecHndl;
struct MenuRec {
   Word menuID;                         /* Menu's ID number */
   Word menuWidth;                      /* Width of menu */
   Word menuHeight;                     /* Height of menu */
   WordProcPtr menuProc;                /* Menu's definition procedure */
   Word menuFlag;                       /* Bit flags */
   Word numOfItems;
   Word titleWidth;                     /* Width of menu's title */
   Pointer titleName;
   Handle menuCache;
   };
typedef struct MenuRec MenuRec, *MenuRecPtr, **MenuRecHndl;

struct MenuItemTemplate {
   Word version;                        /* Version number (must be 0) */
   Word itemID;                         /* Menu item ID */
   Byte itemChar;                       /* Primary keystroke character */
   Byte itemAltChar;                    /* Alternate keystroke character */
   Word itemCheck;                      /* Character code for checked items */
   Word itemFlag;                       /* Menu item flag word */
   Ref itemTitleRef;                    /* Reference to item title string */
} ;
typedef struct MenuItemTemplate MenuItemTemplate;

struct MenuTemplate {
   Word version;                        /* Version number (must be 0) */
   Word menuID;                         /* Menu ID */
   Word menuFlag;                       /* Menu flag word */
   Ref menuTitleRef;                    /* Reference to menu title string */
   Ref itemRefArray[mtItemRefArrayLength]; /* mtItemRefArrayLength references to menu items  */
   };
typedef struct MenuTemplate MenuTemplate;

struct MenuBarTemplate {
   Word version;                        /* Version number (must be 0) */
   Word menuFlag;                       /* MenuBar flag word */
   Ref menuRefArray[mbtMenuRefArrayLength]; /* mbtMenuRefArrayLength references to menus */
   };
typedef struct MenuBarTemplate MenuBarTemplate;

typedef struct itemStruct {
   Word itemFlag2;
   Ref itemTitleRef;
   Ref itemIconRef;
   };
typedef struct itemStruct itemStruct;

typedef struct ipmiResultRec {
   Word highestID;
   Handle tempHandle1, tempHandle2;
   };
typedef struct ipmiResultRec ipmiResultRec;

extern pascal void MenuBootInit(void) inline(0x010F,dispatcher);
extern pascal void MenuStartUp(Word, Word) inline(0x020F,dispatcher);
extern pascal void MenuShutDown(void) inline(0x030F,dispatcher);
extern pascal Word MenuVersion(void) inline(0x040F,dispatcher);
extern pascal void MenuReset(void) inline(0x050F,dispatcher);
extern pascal Boolean MenuStatus(void) inline(0x060F,dispatcher);
extern pascal void CalcMenuSize(Word, Word, Word) inline(0x1C0F,dispatcher);
extern pascal void CheckMItem(Boolean, Word) inline(0x320F,dispatcher);
extern pascal Word CountMItems(Word) inline(0x140F,dispatcher);
extern pascal void DeleteMenu(Word) inline(0x0E0F,dispatcher);
extern pascal void DeleteMItem(Word) inline(0x100F,dispatcher);
extern pascal void DisableMItem(Word) inline(0x310F,dispatcher);
extern pascal void DisposeMenu(MenuRecHndl) inline(0x2E0F,dispatcher);
extern pascal void DrawMenuBar(void) inline(0x2A0F,dispatcher);
extern pascal void EnableMItem(Word) inline(0x300F,dispatcher);
extern pascal Word FixMenuBar (void) inline(0x130F,dispatcher);
extern pascal void FlashMenuBar(void) inline(0x0C0F,dispatcher);
extern pascal LongWord GetBarColors(void) inline(0x180F,dispatcher);
extern pascal MenuBarRecHndl GetMenuBar(void) inline(0x0A0F,dispatcher);
extern pascal Word GetMenuFlag(Word) inline(0x200F,dispatcher);
extern pascal GrafPortPtr GetMenuMgrPort(void) inline(0x1B0F,dispatcher);
extern pascal Pointer GetMenuTitle(Word) inline(0x220F,dispatcher);
extern pascal MenuRecHndl GetMHandle(Word) inline(0x160F,dispatcher);
extern pascal StringPtr GetMItem(Word) inline(0x250F,dispatcher);
extern pascal Word GetMItemFlag(Word) inline(0x270F,dispatcher);
extern pascal Word GetMItemMark(Word) inline(0x340F,dispatcher);
extern pascal TextStyle GetMItemStyle(Word) inline(0x360F,dispatcher);
extern pascal Word GetMTitleStart(void) inline(0x1A0F,dispatcher);
extern pascal Word GetMTitleWidth(Word) inline(0x1E0F,dispatcher);
extern pascal MenuBarRecHndl GetSysBar(void) inline(0x110F,dispatcher);
extern pascal void HiliteMenu(Boolean, Word) inline(0x2C0F,dispatcher);
extern pascal void InitPalette(void) inline(0x2F0F,dispatcher);
extern pascal void InsertMenu(MenuRecHndl, Word) inline(0x0D0F,dispatcher);
extern pascal void InsertMItem(Pointer, Word, Word) inline(0x0F0F,dispatcher);
extern pascal Word MenuGlobal(Word) inline(0x230F,dispatcher);
extern pascal void MenuKey(WmTaskRecPtr, MenuRecHndl) inline(0x090F,dispatcher);
extern pascal void MenuNewRes(void) inline(0x290F,dispatcher);
extern pascal void MenuRefresh(VoidProcPtr) inline(0x0B0F,dispatcher);
extern pascal void MenuSelect(WmTaskRecPtr, MenuRecHndl) inline(0x2B0F,dispatcher);
extern pascal MenuRecHndl NewMenu(Pointer) inline(0x2D0F,dispatcher);
extern pascal MenuBarRecHndl NewMenuBar(GrafPortPtr) inline(0x150F,dispatcher);
extern pascal void SetBarColors(Word, Word, Word) inline(0x170F,dispatcher);
extern pascal void SetMenuBar(MenuBarRecHndl) inline(0x390F,dispatcher);
extern pascal void SetMenuFlag(Word, Word) inline(0x1F0F,dispatcher);
extern pascal void SetMenuID(Word, Word) inline(0x370F,dispatcher);
extern pascal void SetMenuTitle(Pointer, Word) inline(0x210F,dispatcher);
extern pascal void SetMItem(Pointer, Word) inline(0x240F,dispatcher);
extern pascal void SetMItemBlink(Word) inline(0x280F,dispatcher);
extern pascal void SetMItemFlag(Word, Word) inline(0x260F,dispatcher);
extern pascal void SetMItemID(Word, Word) inline(0x380F,dispatcher);
extern pascal void SetMItemMark(Word, Word) inline(0x330F,dispatcher);
extern pascal void SetMItemName(Pointer, Word) inline(0x3A0F,dispatcher);
extern pascal void SetMItemStyle(TextStyle, Word) inline(0x350F,dispatcher);
extern pascal void SetMTitleStart(Word) inline(0x190F,dispatcher);
extern pascal void SetMTitleWidth(Word, Word) inline(0x1D0F,dispatcher);
extern pascal void SetSysBar(MenuBarRecHndl) inline(0x120F,dispatcher);

extern pascal Pointer GetPopUpDefProc(void) inline(0x3B0F,dispatcher);
extern pascal void HideMenuBar(void) inline(0x450F,dispatcher);
extern pascal void InsertMItem2(Word, Ref, Word, Word) inline(0x3F0F,dispatcher);
extern pascal MenuRecHndl NewMenu2(Word, Ref) inline(0x3E0F,dispatcher);
extern pascal MenuBarRecHndl NewMenuBar2(Word, Ref, Pointer) inline(0x430F,dispatcher);
extern pascal Word PopUpMenuSelect(Word, Word, Word, Word, MenuRecHndl) inline(0x3C0F,dispatcher);
extern pascal void SetMenuTitle2(Word, Ref, Word) inline(0x400F,dispatcher);
extern pascal void SetMItem2(Word, Ref, Word) inline(0x410F,dispatcher);
extern pascal void SetMItemName2(Word, Ref, Word) inline(0x420F,dispatcher);
extern pascal void ShowMenuBar(void) inline(0x460F,dispatcher);

extern pascal Word GetMItemBlink(void) inline(0x4F0F,dispatcher);
extern pascal Word GetMItemFlag2(Word) inline(0x4C0F,dispatcher);
extern pascal Ref GetMItemIcon(Word) inline(0x480F,dispatcher);
extern pascal Ref GetMItemStruct(Word) inline(0x4A0F,dispatcher);
extern pascal void InsertPathMItems(Word, Pointer, Word, Word, Word, Word, Ptr) inline(0x500F,dispatcher);
extern pascal void RemoveMItemStruct(Word) inline(0x4B0F,dispatcher);
extern pascal void SetMItemFlag2(Word, Word) inline(0x4D0F,dispatcher);
extern pascal void SetMItemIcon(Word, Ref, Word) inline(0x470F,dispatcher);
extern pascal void SetMItemStruct(Word, Ref, Word) inline(0x490F,dispatcher);

#endif
