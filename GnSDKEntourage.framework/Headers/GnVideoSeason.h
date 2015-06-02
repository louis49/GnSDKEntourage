/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoSeason_h_
#define _GnVideoSeason_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContent.h"
#import "GnEnums.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnRating.h"
#import "GnTitle.h"
#import "GnVideoCredit.h"
#import "GnVideoProduct.h"
#import "GnVideoSeries.h"
#import "GnVideoWork.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnVideoCreditEnumerator;
@class GnVideoProductEnumerator;
@class GnVideoSeriesEnumerator;
@class GnVideoWorkEnumerator;


/**
* \class GnVideoSeason
*/ 

@interface GnVideoSeason : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnVideoSeason
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
*  Flag indicating if response result contains full (true) or partial metadata.
* <p><b>Note:</b></p>
*   What constitutes a full result varies among response results, and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
*  Video season's Gracenote identifier.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnId;

/**
*   Video season's Gracenote unique identifier.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*  Video season's product ID (aka Tag ID).
*  <p><b>Remarks:</b></p>
*  Available for most types, this value can be stored or transmitted. Can
*  be used as a static identifier for the current content as it will not change over time.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*  Video season's TUI (title-unique identifier).
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*  Video season's Tui Tag.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*  Video production type, e.g., Animation. This is a list/locale dependent value.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list or locale be loaded into memory through a successful
*  allocation of a GnLocale object
*
*  To render locale-dependent information for list-based values, the application must allocate a GnLocale object.
*  The SDK returns a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for
*  a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoProductionType;

/**
*  Video production type identifier.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) videoProductionTypeId;

/**
*  Video season's original release date.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateOriginalRelease;

/**
*  Duration in seconds such as "3600" for a 60-minute program.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Duration units value (seconds, "SEC").
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) durationUnits;

/**
*  Franchise number.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) franchiseNum;

/**
*  Franchise count.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) franchiseCount;

/**
*  Plot sypnosis, e.g., for Friends episode:."Monica's popularity at a karaoke club might have more to do with her revealing dress than her voice"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsis;

/**
*  Plot sypnosis language, e.g., English
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsisLanguage;

/**
*  Plot tagline, e.g., "An adventure as big as life itself."
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotTagline;

/**
*  Serial type, e.g., Series or Episode
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) serialType;

/**
*  Work type, e.g., Musical
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) workType;

/**
*  Target audience, e.g., "Kids and Family"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) audience;

/**
*  Video mood, e.g., Playful.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoMood;

/**
*  Overall story type, e.g., "Love Story".
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) storyType;

/**
*  Reputation, e.g., "Chick flick".
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) reputation;

/**
*  Scenario, e.g., Action
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) scenario;

/**
*  Setting environment, e.g., "High School"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) settingEnvironment;

/**
*  Setting time period, e.g., "Jazz Age 1919-1929".
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) settingTimePeriod;

/**
*  Topic value, e.g., "Teen Angst"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) topic;

/**
*  Season number.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonNumber;

/**
*  Season count - total number of seasons.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonCount;

/**
*  Source, e.g., "Fairy Tales and Nursery Rhymes"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) source;

/**
*  Style, e.g., "Film Noir"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) style;

/**
*  Genre. This is a list/locale dependent, multi-level field.
*
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list or locale be loaded into memory through a successful
*  allocation of a <code>GnLocale</code> object
*
*  To render locale-dependent information for list-based values, the application must allocate a GnLocale object.
*  The SDK returns a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for
*  a list-based value.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

/**
*  Origin, e.g., "New York City." List/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list or locale be loaded into memory through a successful
*  allocation of a <code>GnLocale</code> object
*
*  To render locale-dependent information for list-based values, the application must allocate a GnLocale object.
*  The SDK returns a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for
*  a list-based value.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) origin: (GnDataLevel)level;

/**
*  Rating object.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(GnRating*) rating;

/**
*   Official title object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*  Franchise title object.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnTitle*) franchiseTitle;

/**
*  Iterator for extended IDs, which identify a source external to Gracenote (e.g., NetFlix), that also have an identifier for this work.
*  Extended ID type supports Link data.
* @ingroup GDO_ChildKeys_ExternalId
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
*   Iterator for child works.
* @ingroup GDO_ChildKeys_Works
*/ 

-(GnVideoWorkEnumerator*) works;

/**
*   Iterator for child products
* @ingroup GDO_ChildKeys_Products
*/ 

-(GnVideoProductEnumerator*) products;

/**
*   Iterable for child credits. For music types, this includes
*   all credits except the artist credit.
* @ingroup GDO_ChildKeys_Credit
*/ 

-(GnVideoCreditEnumerator*) videoCredits;

/**
* Iterator for the content (cover art, biography, etc.)  associated with this video work.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
*   Iterator for child series'
* @ingroup GDO_ChildKeys_Series
*/ 

-(GnVideoSeriesEnumerator*) series;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoSeason*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoSeasonEnumerator : NSEnumerator

typedef void (^GnVideoSeasonBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoSeasonBlock)handler;

-(NSUInteger) count;

-(GnVideoSeason*) nextObject;

-(GnVideoSeason*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoSeason_h_ */

