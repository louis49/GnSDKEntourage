/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrAudio_h_
#define _GnAcrAudio_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnAcrEventsDelegate.h"
#import "GnAcrMusicOptions.h"
#import "GnAcrOptions.h"
#import "GnAcrStatus.h"
#import "GnResponseAcrMatch.h"
#import "GnUser.h"




/**
*  This class allows you to recognize video and music content using audio fingerprinting
*/ 

@interface GnAcrAudio : NSObject

/**
*  Class constructor.
*  @param user	[in] Gracenote user
*  @param pEventHandler [in] ACR event handler
* @ingroup Acr_InitializationFunctions
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user acrEventsDelegate: (id <GnAcrEventsDelegate>)pEventHandler;

/**
*  Prepares ACR to receive audio data for recognition.
*  @deprecated Replaced with AudioProcessStart which takes in additional parameter queryMode
*  @param audioSampleRate [in] Sample rate
*  @param audioSampleFormat [in] Sample format.
*  @param audioChannels [in] Number of audio channels.
* @ingroup Acr_QueryFunctions
*/ 

-(void) audioProcessStart: (NSUInteger)audioSampleRate audioSampleFormat: (GnAcrAudioSampleFormat)audioSampleFormat audioChannels: (NSUInteger)audioChannels error: (NSError**)error;

/**
*  Prepares ACR to receive audio data for recognition.
*  @param audioSampleRate [in] Sample rate
*  @param audioSampleFormat [in] Sample format.
*  @param audioChannels [in] Number of audio channels.
*  @param queryMode [in] Determines the fingerprint query behavior 
* @ingroup Acr_QueryFunctions
*/ 

-(void) audioProcessStart: (NSUInteger)audioSampleRate audioSampleFormat: (GnAcrAudioSampleFormat)audioSampleFormat audioChannels: (NSUInteger)audioChannels audioFPQueryMode: (GnAcrAudioFPQueryMode)audioFPQueryMode error: (NSError**)error;

/**
* Processes a buffer of decoded audio data for recognition.
* @param audioData [in] Buffer containing audio data
* @param audioDataLength [in] Size of buffer containing audio data
*/ 

-(void) audioProcess: (unsigned char*)audioData audioDataLength: (NSUInteger)audioDataLength error: (NSError**)error;

/**
* Stops processing audio data for recognition.
*/ 

-(void) audioProcessStop:(NSError**) error;

/**
*  Perform a one-time video query.
* @ingroup Acr_QueryFunctions
*/ 

-(void) videoLookup:(NSError**) error;

/**
*  Perform a one-time music query.
* @ingroup Acr_QueryFunctions
*/ 

-(void) musicLookup:(NSError**) error;

/**
* Get the GnAcrOptions object for setting/getting options
*/ 

-(GnAcrOptions*) options;

/**
* Get the GnAcrMusicOptions object for setting/getting options related to music queries.
*/ 

-(GnAcrMusicOptions*) musicOptions;


@end



#endif /* _GnAcrAudio_h_ */

