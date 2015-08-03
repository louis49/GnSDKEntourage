/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrStatus_h_
#define _GnAcrStatus_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
*  Defines a delegate class for ACR progress status
*/ 

@interface GnAcrStatus : NSObject

/**
* Default constructor
*/ 

-(INSTANCE_RETURN_TYPE) init;

/**
* Construct a GnAcrStatus object
* @param statusType [in] ACR status type
* @param value [in] Value associated with this status
* @param error [in] Optional error, if this status is reporting an error
* @param message [in] Message associated with this status
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnAcrStatusType: (GnAcrStatusType)statusType value: (float)value error: (NSUInteger)error message: (NSString*)message;

/**
* Get the status type
*/ 

-(GnAcrStatusType) statusType;

/**
* Get the value associated with the status type. Currently, this value is only valid
* for status types GnAcrStatusType.kAcrStatusAudioSilent and GnAcrStatusType.kAcrStatusSilenceRatio.
* For GnAcrStatusType.kAcrStatusAudioSilent, the value returned is the silence duration.
* For GnAcrStatusType.kAcrStatusSilenceRatio, the value returned is the silence ratio.
*/ 

-(float) value;

/**
* Get the error
*/ 

-(NSError*) error;

/**
* Get the status message
* Not all status types have messages.  In these cases the API will return an empty string
*/ 

-(NSString*) message;


@end



#endif /* _GnAcrStatus_h_ */

