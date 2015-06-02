/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseVideoProduct_h_
#define _GnResponseVideoProduct_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnVideoProduct.h"


@class GnVideoProductEnumerator;


/**
* \class GnResponseVideoProduct
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

@interface GnResponseVideoProduct : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Total number of results
*/ 

-(NSUInteger) resultCount;

/**
*  Ordinal of the first result in the returned range.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeStart;

/**
*  Ordinal of the last result in the returned range.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeEnd;

/**
*  Estimated total number of results possible.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rangeTotal;

/**
* Flag indicating if response match(es) need a user or app decision - either multiple matches returned or less than perfect single match..
*/ 

-(BOOL) needsDecision;

/**
*  Iterator for child video products
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoProductEnumerator*) products;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnResponseVideoProduct*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnResponseVideoProduct_h_ */

