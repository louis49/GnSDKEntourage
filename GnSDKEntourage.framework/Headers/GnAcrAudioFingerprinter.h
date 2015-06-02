/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrAudioFingerprinter_h_
#define _GnAcrAudioFingerprinter_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnAcrOptions.h"
#import "GnUser.h"




/**
* GnAcrAudioFingerprinter
*/
@interface GnAcrAudioFingerprinter : NSObject

/**
*  Class constructor.
*  @param user	[in] Gracenote user
* @ingroup Acr_InitializationFunctions
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user;

/**
*  Initializes the ACR process that generates and returns a fingerprint to the application.
*  @param audioSampleRate [in] Sample rate
*  @param audioSampleFormat [in] Sample format.
*  @param audioChannels [in] Number of audio channels.
* @ingroup Acr_QueryFunctions
*/ 

-(void) fingerprintBegin: (NSUInteger)audioSampleRate audioSampleFormat: (GnAcrAudioSampleFormat)audioSampleFormat audioChannels: (NSUInteger)audioChannels error: (NSError**)error;

/**
* Provides uncompressed audio data for fingerprint generation only. Returns true if the fingerprint
* generation process gathered enough audio data and has generated a fingerprint. 
* <p><b>Remarks:</b></p>
* Once a fingerprint is generated, it remains part of the query until the query is released or until 
* the fingerprinter is re-initialized by invoking the calling sequence described in the 
* Remarks of FingerprintData().
* @param audioData [in] Buffer containing audio data
* @param audioDataLength [in] Size of buffer containing audio data
* @return True if the fingerprint generation process gathered enough audio data. False otherwise.
* @ingroup Acr_QueryFunctions
*/ 

-(BOOL) fingerprintWrite: (unsigned char*)audioData audioDataLength: (NSUInteger)audioDataLength error: (NSError**)error;

/**
* Finalizes the ACR process that generates and returns a fingerprint to the application.
* @ingroup Acr_QueryFunctions
*/ 

-(void) fingerprintEnd:(NSError**) error;

/**
*  Retrieves the internally-generated Gracenote fingerprint data.
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve internally-generated fingerprint data for cases where the application stores the fingerprint 
*  for various purposes. To retrieve an internally-generated fingerprint, call FingerprintData last, as shown in the following 
*  calling sequence:
*  <ol>
*  <li>FingerprintBegin()
*  <li>FingerprintWrite()
*  <li>FingerprintEnd()
*  <li>FingerprintData()
*  </ol>
*  @return String fingerprint data
* @ingroup Acr_QueryFunctions
*/ 

-(NSString*) fingerprintData:(NSError**) error;

/**
*  Retrieves the time the fingerprint data was generated.
*  @return The time that the fingerprint data was generated in microseconds
* @ingroup Acr_QueryFunctions
*/ 

-(NSUInteger) fingerprintDataCreationTime:(NSError**) error;

/**
* Get the GnAcrOptions object for setting/getting options
* @ingroup Acr_QueryFunctions
*/ 

-(GnAcrOptions*) options;


@end



#endif /* _GnAcrAudioFingerprinter_h_ */

