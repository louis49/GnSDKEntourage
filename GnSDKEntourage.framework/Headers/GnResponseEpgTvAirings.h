/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseEpgTvAirings_h_
#define _GnResponseEpgTvAirings_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTVAiring.h"


@class GnTVAiringEnumerator;


/**
* GnResponseEpgTvAirings
*/ 

@interface GnResponseEpgTvAirings : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Number of results returned
*/ 

-(NSUInteger) resultCount;

/**
* RangeStart
*/
-(NSUInteger) rangeStart;

/**
* Ordinal value of last result
*/ 

-(NSUInteger) rangeEnd;

/**
* Possible number of results
*/ 

-(NSUInteger) rangeTotal;

/**
* Flag indicating if user decision needed - either multiple results or single match is determined to be less than perfect
*/ 

-(BOOL) needsDecision;

/**
* Iterator to access the matched TV airings.
*/ 

-(GnTVAiringEnumerator*) tvAirings;


@end



#endif /* _GnResponseEpgTvAirings_h_ */

