/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnDsp_h_
#define _GnDsp_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDspFeature.h"
#import "GnEnums.h"
#import "GnUser.h"




/**************************************************************************
** GnDsp
*/ 

@interface GnDsp : NSObject

/**
* Initializes the DSP library.
* @param user set user
* @param featureType The kind of DSP feature, for example a fingerprint.
* @param audioSampleRate The source audio sample rate.
* @param audioSampleSize The source audio sample size.
* @param audioChannels	The source audio channels
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user featureType: (GnDspFeatureType)featureType audioSampleRate: (NSUInteger)audioSampleRate audioSampleSize: (NSUInteger)audioSampleSize audioChannels: (NSUInteger)audioChannels;

/**
*  Retrieves GnDsp SDK version string.
*  This API can be called at any time, after getting instance of GnManager successfully. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/ 

+(NSString*) version;

/**
*  Retrieves the GnDsp SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting instance of GnManager successfully. The returned
* string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(NSString*) buildDate;

/**
* Use this method to feed audio in to GnDsp until it returns true
* @param audioData The source audio
* @param audioDataBytes The source audio size in bytes
* @return false : GnDsp needs more audio, true : GnDsp received enough audio to generate required feature
*/ 

-(BOOL) featureAudioWrite: (unsigned char*)audioData audioDataBytes: (NSUInteger)audioDataBytes error: (NSError**)error;

/**
* Indicates the the DSP feature has reached the end of the write operation.
*/ 

-(void) featureEndOfAudioWrite:(NSError**) error;

/**
* Retrieve GnDspFeature
* @return GnDspFeature
*/ 

-(GnDspFeature*) featureRetrieve:(NSError**) error;


@end



#endif /* _GnDsp_h_ */

