/********************************************
*
* MIDI Synth Tool Set
*
* Copyright Apple Computer, Inc. 1991
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc
*
********************************************/

#pragma once

#ifndef __TYPES__
#include <types.h>
#endif

#ifndef __MIDISYNTH__
#define __MIDISYNTH__

/* Error Codes */
#define msAlreadyStarted 0x2301         /* MidiSynth already started */
#define msNotStarted 0x2302             /* MidiSynth never started */
#define msNoDPMem 0x2303                /* Can't get direct page memory */
#define msNoMemBlock 0x2304             /* Can't get memory block */
#define msNoMiscTool 0x2305             /* Misc Tools not started */
#define msNoSoundTool 0x2306            /* Sound Tools not started */
#define msGenInUse 0x2307               /* Ensoniq generator in use */
#define msBadPortNum 0x2308             /* Illegal port number */
#define msPortBusy 0x2309               /* Port is busy */
#define msParamRangeErr 0x230a          /* Parameter range error */
#define msMsgQueueFull 0x230b           /* Message queue full */
#define msRecBufFull 0x230c             /* Rec buffer is full */
#define msOutputDisabled 0x230d         /* MIDI output disabled */
#define msMessageError 0x230e           /* Message error */
#define msOutputBufFull 0x230f          /* MIDI output buffer is full */
#define msDriverNotStarted 0x2310       /* Driver not started */
#define msDriverAlreadySet 0x2311       /* Driver already set */
#define msDevNotAvail 0x2380            /* the requested device is not available */
#define msDevSlotBusy 0x2381            /* requested slot is already in use */
#define msDevBusy 0x2382                /* the requested device is already in use */
#define msDevOverrun 0x2383             /* device overrun by incoming MIDI data */
#define msDevNoConnect 0x2384           /* no connection to MIDI */
#define msDevReadErr 0x2385             /* framing error in received MIDI data */
#define msDevVersion 0x2386             /* ROM version is incompatible with device driver */
#define msDevIntHndlr 0x2387            /* conflicting interrupt handler is installed */

/* structure definitions */
typedef struct {
   byte reserved1[0x0c];
   word MpacketStat;
   word MpacketData1;
   word MpacketData2;
   byte SeqClockFrac;
   long SeqClockInt;
   byte reserved2[0x31-0x16];
   byte SeqItemStat;
   byte SeqItemData1;
   byte SeqItemData2;
   byte reserved3[0x3f-0x33];
   byte MetroVol;
   byte reserved4[0xe4-0x3f];
   word MetroFreq;
   byte reserved5[0xea-0xe5];
   byte SeqItemTrack;
   byte reserved6;
   byte PacketBytes;
   byte reserved7[0x100-0xec];
   } msDirectPage, *msDirectPagePtr, **msDirectPageHndl;

typedef struct {
   msDirectPagePtr directPage;
   long reserved;
   } GetMSDataOutputRec, *GetMSDataOutputRecPtr, **GetMSDataOutputRecHndl;

typedef struct {
   word measureNumber;
   word beatNumber;
   word msRemainder;
   } MeasureRec, *MeasureRecPtr, **MeasureRecHndl;

typedef struct {
   ProcPtr EndSeq;
   ProcPtr UserMeter;
   ProcPtr Mstart;
   ProcPtr Mstop;
   ProcPtr PacketIn;
   ProcPtr SeqEvent;
   ProcPtr SysEx;
   ProcPtr PacketOut;
   ProcPtr PgmChange;
   ProcPtr Mcontinue;
   ProcPtr SMarker;
   ProcPtr RecBufFull;
   ProcPtr Reserved1;
   ProcPtr Reserved2;
   } CallBackRec, *CallBackRecPtr, **CallBackRecHndl;

typedef struct {
   pointer PbufStart;
   long Reserved;
   pointer RbufStart;
   pointer RbufEnd;
   word SeqFlags;
   long theClock;
   } SeqPlayRec, *SeqPlayRecPtr, **SeqPlayRecHndl;

typedef struct {
   byte AttackLevel;
   byte AttackRate;
   byte Decay1Level;
   byte Decay1Rate;
   byte Decay2Level;
   byte Decay2Rate;
   byte SustainLevel;
   byte Decay3Rate;
   byte Release1Level;
   byte Release1Rate;
   byte Release2Level;
   byte Release2Rate;
   byte Release3Rate;
   byte DecayGain;
   byte VelocityGain;
   byte PitchBendRange;
   } EnvelopeRec, *EnvelopeRecPtr, **EnvelopeRecHndl;

typedef struct {
   byte TopKey;
   byte OscConfig;
   byte Stereo;
   byte Detune;
   byte WaveAddrA;
   byte WaveSizeA;
   byte VolumeA;
   byte OctaveA;
   byte SemitoneA;
   byte FineTuneA;
   byte WaveAddrB;
   byte WaveSizeB;
   byte VolumeB;
   byte OctaveB;
   byte SemitoneB;
   byte FineTuneB;
   } WavelistRec, *WavelistRecPtr, **WavelistRecHndl;

typedef struct {
   EnvelopeRec gen1EnvRec;
   WavelistRec gen1WaveRecs[8];
   EnvelopeRec gen2EnvRec;
   WavelistRec gen2WaveRecs[8];
   } InstrumentRec, *InstrumentRecPtr, **InstrumentRecHndl;

typedef struct {
   byte TrackNum;
   byte TimeStampHigh;
   byte TimeStampLow;
   byte TimeStampMid;
   byte DataByteCount;
   byte MIDIStat;
   byte DataByte1;
   byte DataByte2;
   } SeqItemRec, *SeqItemRecPtr, **SeqItemRecHndl;

/* available calls */
extern pascal void MSBootInit(void) inline(0x0123,dispatcher);
extern pascal void MSStartUp(void) inline(0x0223,dispatcher);
extern pascal void MSShutDown(void) inline(0x0323,dispatcher);
extern pascal word MSVersion(void) inline(0x0423,dispatcher);
extern pascal void MSReset(void) inline(0x0523,dispatcher);
extern pascal word MSStatus(void) inline(0x0623,dispatcher);
extern pascal MeasureRec ConvertToMeasure(Word, Word, Long);
extern pascal long ConvertToTime(Word, Word, Word, Word) inline(0x2023,dispatcher);
extern pascal void DeleteTrack(Word, Ptr) inline(0x1d23,dispatcher);
extern        void GetMSData(long *reserved, long *DP); // ???
extern pascal void GetTuningTable(Ptr) inline(0x2523,dispatcher);
extern pascal void InitMIDIDriver(Word, Word, Word, ProcPtr) inline(0x2723,dispatcher);
extern pascal void KillAllNotes(void) inline(0x0d23,dispatcher);
extern pascal SeqItemRecPtr Locate(Long, Ptr) inline(0x1123,dispatcher);
extern pascal pointer LocateEnd(Ptr) inline(0x1b23,dispatcher);
extern pascal void Merge(Ptr, Ptr) inline(0x1c23,dispatcher);
extern pascal void MIDIMessage(Word, Word, Word, Word, Word) inline(0x1a23,dispatcher);
extern pascal void MSResume(void) inline(0x2323,dispatcher);
extern pascal void MSSuspend(void) inline(0x2223,dispatcher);
extern pascal void PlayNote(Word, Word, Word) inline(0x0b23,dispatcher);
extern pascal void RemoveMIDIDriver(void) inline(0x2823,dispatcher);
extern pascal void SeqPlayer(SeqPlayRecPtr) inline(0x1523,dispatcher);
extern pascal void SetBasicChan(Word) inline(0x0923,dispatcher);
extern pascal void SetBasicChannel(Word) inline(0x0923,dispatcher);
extern pascal void SetBeat(Word) inline(0x1923,dispatcher);
extern pascal void SetCallBack(CallBackRecPtr) inline(0x1723,dispatcher);
extern pascal void SetInstrument(InstrumentRecPtr, Word) inline(0x1423,dispatcher);
extern pascal void SetMetro(Word, Word, Ptr) inline(0x1e23,dispatcher);
extern pascal void SetMIDIMode(Word) inline(0x0a23,dispatcher);
extern pascal void SetMIDIPort(Boolean, Boolean) inline(0x1323,dispatcher);
extern pascal void SetPlayTrack(Word, Boolean) inline(0x0f23,dispatcher);
extern pascal void SetRecTrack(Word) inline(0x0e23,dispatcher);
extern pascal void SetTempo(Word) inline(0x1623,dispatcher);
extern pascal void SetTrackOut(Word, Word) inline(0x2623,dispatcher);
extern pascal void SetTuningTable(Ptr) inline(0x2423,dispatcher);
extern pascal void SetVelComp(Word) inline(0x1223,dispatcher);
extern pascal void StopNote(Word, Word) inline(0x0c23,dispatcher);
extern pascal void SysExOut(Ptr, Word, ProcPtr) inline(0x1823,dispatcher);
extern pascal void TrackToChannel(Word, Word) inline(0x1023,dispatcher);

#endif
