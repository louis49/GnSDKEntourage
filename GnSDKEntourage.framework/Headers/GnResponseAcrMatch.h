/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseAcrMatch_h_
#define _GnResponseAcrMatch_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAcrMatch.h"
#import "GnDataObject.h"


@class GnAcrMatchEnumerator;


/**
*  \class GnResponseAcrMatch
*
*  <p><b>Remarks about range values:</b></p>
*  If you do not set a starting value, the default behavior is to return the first set of results.
*  Range values are available to aid in paging results. Gracenote Service limits the number of
*  responses returned in any one request, so the range values are available to indicate the total
*  number of results, and where the current results fit in within that total.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results
*  requested. To accurately iterate through results, always check the range start, end, and total
*  values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
*  are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
*  using the initial requested value.
*/ 

@interface GnResponseAcrMatch : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Total number of result matches
*/ 

-(NSUInteger) resultCount;

/**
*	Ordinal of the first result in the returned range.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeStart;

/**
*	Ordinal of the last result in the returned range.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeEnd;

/**
*	Estimated total number of results possible.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeTotal;

/**
*  Iterator for child acr products.
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child	acr product to retrieve.
* @ingroup GDO_ChildKeys_ACR
*/ 

-(GnAcrMatchEnumerator*) acrMatches;

/**
* The identifier supplied by the user when the fingerprint data associated with this ACR match response was generated
* <p><b>Remarks:</b></p>
* Currently, the fingerprint identifier is only available if one was provided at the time that the fingerprint data
* was added to an ACR batch query.
*/ 

-(NSString*) fingerprintIdentifier;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnResponseAcrMatch*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnResponseAcrMatch_h_ */

