/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseEpgTvProvider_h_
#define _GnResponseEpgTvProvider_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTVProvider.h"


@class GnTVProviderEnumerator;


/**
* GnResponseEpgTvProvider
*/ 

@interface GnResponseEpgTvProvider : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Number of results returned
*/ 

-(NSUInteger) resultCount;

/**
* Ordinal value of first result
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
* Retrieves an iterator to access the matched tv providers.
*/ 

-(GnTVProviderEnumerator*) tvProviders;


@end



#endif /* _GnResponseEpgTvProvider_h_ */

