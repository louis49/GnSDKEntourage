/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTVProgram_h_
#define _GnTVProgram_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContent.h"
#import "GnCredit.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnString.h"
#import "GnTitle.h"
#import "GnVideoSeries.h"
#import "GnVideoWork.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnStringEnumerator;


/**
* \class GnTVProgram
*/ 

@interface GnTVProgram : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnTVProgram
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
*  Flag indicating if response result contains full (true) or partial metadata
*  <p><b>Note:</b></p>
*  What constitutes a full result varies among response results and also
*  depends on data availability.
*/ 

-(BOOL) isFullResult;

/**
*	Retrieves the Gracenote ID
*/ 

-(NSString*) gnId;

/**
*	Retrieves the Gracenote unique ID
*/ 

-(NSString*) gnUId;

/**
* Retrieves a product ID.
* <p><b>Remarks:</b></p>
* Available for most types, this retrieves a value which can be stored or transmitted. This
* value can be used as a static identifier for the current content as it will not change over time.
*/ 

-(NSString*) productId;

/**
*	Retrieves the TUI (title-unique identifier)
*/ 

-(NSString*) tui;

/**
*	Retrieves the TUI tag
*/ 

-(NSString*) tuiTag;

/**
*  Retrieves the credits
*/ 

-(GnCredit*) credit;

/**
*  Retrieves the video work
*/ 

-(GnVideoWork*) videoWork;

/**
* Retrieves the iterator for the content (e.g. cover art, biography, etc.) 
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* Retrieves the iterator for external IDs (i.e. third-party IDs)
* @return Iterator
*/ 

-(GnExternalIdEnumerator*) externalIds;

/** 
* Retrieves the iterator to a collection of level 1 Categories, e.g. 'TV Series'.  A program may have multiple level 1 categories
* assigned to it.
*
* Note: An EPG locale list must be loaded for the categories to be returned
* @return Iterator
* @see GnLocale
*
*/ 

-(GnStringEnumerator*) level1Categories;

/** 
* Retrieves the iterator to a collection of level 2 Categories, e.g. 'Science Fiction'.  A program may have multiple level 2 categories
* assigned to it.
*
* Note: An EPG locale list must be loaded for the categories to be returned
* @return Iterator
* @see GnLocale
*
*/ 

-(GnStringEnumerator*) level2Categories;

/**
*	Retrieves the official title
*/ 

-(GnTitle*) officialTitle;

/**
*	Retrieves the subtitle
*/ 

-(GnTitle*) subtitle;

/**
* Retrieves the listing
*/ 

-(NSString*) listing;

/**
*  Retrieves the video series
*/ 

-(GnVideoSeries*) videoSeries;

/**
* Retrieves the season episode number
*/ 

-(NSUInteger) seasonEpisodeNumber;

/**
* Retrieves the season episode count
*/ 

-(NSUInteger) seasonEpisodeCount;

/**
* Retrieves the season number
*/ 

-(NSUInteger) seasonNumber;

/**
* Retrieves the season count
*/ 

-(NSUInteger) seasonCount;

/**
* Retrieves the series episode number
*/ 

-(NSUInteger) seriesEpisodeNumber;

/**
* Retrieves the series episode count
*/ 

-(NSUInteger) seriesEpisodeCount;

/**
* Retrieves the production type of the program, e.g. 'Movie'
* An EPG locale list must be loaded for a value to be returned
* @return String
* @see GnLocale
*/ 

-(NSString*) productionType;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnTVProgram*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnTVProgramEnumerator : NSEnumerator

typedef void (^GnTVProgramBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnTVProgramBlock)handler;

-(NSUInteger) count;

-(GnTVProgram*) nextObject;

-(GnTVProgram*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnTVProgram_h_ */

