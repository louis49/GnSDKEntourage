/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseVideoSeries_h_
#define _GnResponseVideoSeries_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnVideoSeries.h"


@class GnVideoSeriesEnumerator;


/**
*  \class GnResponseVideoSeries
*
*  <p><b>Using range values:</b></p>
*  <ul>
*    <li>If you do not set a starting value, the default behavior returns the first set of results.</li>
*    <li>Range values are useful for paging results.</li>
*  </ul>
*  <p><b>Important:</b></p>
*   Gracenote Service limits the range size for some queries. The maximum range allowed for video queries 
*   is 100 even though range total might be much larger. If you specify a range size greater
*   than the limit, the results are constrained. Neither Gracenote Service nor GNSDK
*   return an error about this behavior. 
*
*   The number of results actually returned for a query may not equal the number of results
*   requested. To accurately iterate through results, always check the range start, end, and total
*   values, and the responses Gracenote returns for the query (or queries). Ensure that you
*   are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
*   using the initial requested value.
*  
*/ 

@interface GnResponseVideoSeries : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Total number of returned matches
*/ 

-(NSUInteger) resultCount;

/**
*	Ordinal of the first result in the returned range.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeStart;

/**
*	Ordinal of the last result in the returned range.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeEnd;

/**
*	Estimated total number of results possible.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeTotal;

/**
* Flag indicating if response match(es) need a user or app decision - either multiple matches returned or less than perfect single match..
*/ 

-(BOOL) needsDecision;

/**
*	Iterator for child series'.
*	<p><b>Remarks:</b></p>
*	The ordinal parameter specifies the n'th child video Series to retrieve.
*	@ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoSeriesEnumerator*) series;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnResponseVideoSeries*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnResponseVideoSeries_h_ */

