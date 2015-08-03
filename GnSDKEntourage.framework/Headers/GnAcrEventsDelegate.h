/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrEventsDelegate_h_
#define _GnAcrEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnAcrStatus.h"
#import "GnResponseAcrMatch.h"


@class GnAcrStatus;
@class GnResponseAcrMatch;


@protocol GnAcrEventsDelegate <NSObject>

@required

/**
*  Callback to handle ACR status events
*  @param acrStatus [in] ACR status
*/ 

-(void) statusEvent: (GnAcrStatus*)acrStatus;

/**
*  Callback to handle results as they become available.
*  @param responseAcrMatch [in] ACR match response
*  @param acrMatchSourceType [in] Source of the fingerprint match
*  <p><b>Remarks:</b></p>
*  The provided responseAcrMatch will include zero or more matches.
*/ 

-(void) resultEvent: (GnResponseAcrMatch*)responseAcrMatch acrMatchSourceType: (GnAcrMatchSourceType)acrMatchSourceType;


@end



#endif /* _GnAcrEventsDelegate_h_ */

