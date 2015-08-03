/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseVideoObjects_h_
#define _GnResponseVideoObjects_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnVideoProduct.h"
#import "GnVideoSeason.h"
#import "GnVideoSeries.h"
#import "GnVideoWork.h"


@class GnContributorEnumerator;
@class GnVideoProductEnumerator;
@class GnVideoSeasonEnumerator;
@class GnVideoSeriesEnumerator;
@class GnVideoWorkEnumerator;


/**
* \class GnResponseVideoObjects
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

@interface GnResponseVideoObjects : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  ResultCount - total number of returned matches
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
* Flag indicating if response match(es) need a user or app decision - either multiple matches returned or less than perfect single match..
*/ 

-(BOOL) needsDecision;

/**
*  Iterator for child products
*/ 

-(GnVideoProductEnumerator*) products;

/**
*  Iterator for child Works
*/ 

-(GnVideoWorkEnumerator*) works;

/**
*  Iterator for child Seasons
*/ 

-(GnVideoSeasonEnumerator*) seasons;

/**
*  Iterator for child Series
*/ 

-(GnVideoSeriesEnumerator*) series;

/**
*  Iterator for child contributors
*/ 

-(GnContributorEnumerator*) contributors;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnResponseVideoObjects*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnResponseVideoObjects_h_ */

