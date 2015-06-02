/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoOptions_h_
#define _GnVideoOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnListElement.h"




/**
* GnVideoOptions
*/ 

@interface GnVideoOptions : NSObject

/**
*  Specifies the preferred language for returned results. This option applies only to TOC
*  Lookups.
*  @param preferredLanguage Set language option
*  @ingroup Video_Options
*/ 

-(void) resultPreferLanguage: (GnLanguage)preferredLanguage error: (NSError**)error;

/**
*  Set ordinal for the first result to be returned
*  @param resultStart Set the starting position for the result
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
* <p><b>Note:</b></p>
*   Gracenote Service limits the range size for some queries. If you specify a range size greater
*   than the limit, the results are constrained. Additionally, neither Gracenote Service nor GNSDK
*   returns an error about this behavior.
*  <p><b>Important:</b></p>
*   The number of results actually returned for a query may not equal the number of results initially
*   requested. To accurately iterate through results, always check the range start, end, and total
*   values and the responses Gracenote returns for the query (or queries). Ensure that you
*   are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
*   using the initial requested value.
*  @ingroup Video_Options
*/ 

-(void) resultRangeStart: (NSUInteger)resultStart error: (NSError**)error;

/**
*  Set number of results to be returned
*  @param resultCount 	[in] Maximum number of results a response can return.
*
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
* <p><b>Note:</b></p>
*   Gracenote Service limits the range size for some queries. If you specify a range size greater
*   than the limit, the results are constrained. Additionally, neither Gracenote Service nor GNSDK
*   returns an error about this behavior.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
*   requested. To accurately iterate through results, always check the range start, end, and total
*   values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
*   are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
*   using the initial requested value.
*  @ingroup Video_Options
*/ 

-(void) resultCount: (NSUInteger)resultCount error: (NSError**)error;

/**
*  Indicates the lookup data value for the Video query.
*  @param lookupData [in] One of the GnLookupData values
*  @param bEnable    [in] Set lookup data
*  @ingroup Video_Options
*/ 

-(void) lookupData: (GnLookupData)lookupData bEnable: (BOOL)bEnable error: (NSError**)error;

/**
*  Indicates whether a response is not automatically stored in the cache.
*  @param bNoCache Set boolean to enable caching
*  <p><b>Remarks:</b></p>
*  Set this option to True to retrieve query data from a call to Gracenote Service; doing this
*   ensures retrieving the most recent available data.
*  Set this option to False to retrieve query data that already exists in the lookup cache. When no
*   data exists in the cache, VideoID
*  or Video Explore automatically calls Gracenote Service with the query request.
*  @ingroup Video_Options
*/ 

-(void) queryNoCache: (BOOL)bNoCache error: (NSError**)error;

/**
*  Specifies that a TOC lookup includes the disc's commerce type.
*  @param bEnableCommerceType Set boolean to enable commerce type
*  @ingroup Video_Options
*/ 

-(void) queryCommerceType: (BOOL)bEnableCommerceType error: (NSError**)error;

/**
*  Sets a filter for a Video Explore query handle, using a list value.
*  @param bInclude [in] Set Boolean value to True to include filter key; set to False to exclude the filter
*  @param listElementFilterType [in] One of the GnVideoListElementFilterType filter types
*  @param listElement [in] A list element handle used to populate the filter value. The list
*   element must be from a list that corresponds to the filter name.
*
*  <p><b>Remarks:</b></p>
*  Use this function with the GNSDK Manager Lists functionality to apply filters on and improve the
*   relevance for specific Video Explore search results. Your application must have Video Explore
*   licensing to use this function.
* <p><b>Note:</b></p>
*  The system disregards filters when performing non-text related video queries, and filtering
*   by list elements is restricted to performing a Works search using the following Filter Values:
*  <ul>
*  <li>kListElementFilterGenre</li>
*  <li>kListElementFilterProductionType</li>
*  <li>kListElementFilterSerialType</li>
*  <li>kListElementFilterOrigin</li>
*  </ul>
*  @ingroup Video_Options
*/ 

-(void) resultFilterWithListElementFilterType: (GnVideoListElementFilterType)listElementFilterType listElement: (GnListElement*)listElement bInclude: (BOOL)bInclude error: (NSError**)error;

/**
*
*  Sets a filter for a VideoID or Video Explore query handle.
*  @param filterValue [in] String value for corresponding data key
*  @param filterType [in] One of the GnVideoFilterType filter types
*  <p><b>Remarks:</b></p>
*  Use this function to apply certain filters on and improve the relevance of Work text search query
*   results.
* <p><b>Note:</b></p>
*  The system disregards filters when performing non-text related video queries, and that filtering by<br>
*  list elements is restricted to performing a Works search using the following Filter Values:
*  <ul>
*  <li>kFilterSeasonNumber text (integer as a string)</li>
*  <li>kFilterSeasonEpisodeNumber text (integer as a string)</li>
*  <li>kFilterSeriesEpisodeNumber text (integer as a string)</li>
*  </ul>
*  @ingroup Video_Options
*/ 

-(void) resultFilterWithFilterType: (GnVideoFilterType)filterType filterValue: (NSString*)filterValue error: (NSError**)error;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup Video_Options
*/ 

-(void) networkInterfaceWithIntfName: (NSString*)intfName error: (NSError**)error;

/**
* Return network interface being use with this object's connections if one has been set. 
* If no specific network interface has been set this option will return an empty string.
*  @ingroup Video_Options
*/ 

-(NSString*) networkInterface:(NSError**) error;

/**
*  General option setting for custom string options
*  @param optionKey   [in] Option name
*  @param value	   [in] Option value
*  @ingroup Video_Options
*/ 

-(void) custom: (NSString*)optionKey value: (NSString*)value error: (NSError**)error;


@end



#endif /* _GnVideoOptions_h_ */

