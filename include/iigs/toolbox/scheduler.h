/********************************************
*
* Scheduler
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

#ifndef __SCHEDULER__
#define __SCHEDULER__

#define busyFlag 0x00E100FFL

extern pascal void SchBootInit(void) inline(0x0107,dispatcher);
extern pascal void SchStartUp(void) inline(0x0207,dispatcher);
extern pascal void SchShutDown(void) inline(0x0307,dispatcher);
extern pascal Word SchVersion(void) inline(0x0407,dispatcher);
extern pascal void SchReset(void) inline(0x0507,dispatcher);
extern pascal Boolean SchStatus(void) inline(0x0607,dispatcher);
extern pascal Boolean SchAddTask(VoidProcPtr) inline(0x0907,dispatcher);
extern pascal void SchFlush(void) inline(0x0A07,dispatcher);

#endif
