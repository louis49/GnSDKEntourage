/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoSeries_h_
#define _GnVideoSeries_h_


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
#import "GnVideoSeason.h"
#import "GnVideoWork.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnVideoCreditEnumerator;
@class GnVideoProductEnumerator;
@class GnVideoSeasonEnumerator;
@class GnVideoWorkEnumerator;


/**
* \class GnVideoSeries
*/ 

@interface GnVideoSeries : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnVideoSeries
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
*  Flag indicating if response result contains full (true) or partial metadata.
* <p><b>Note:</b></p>
*  What constitutes a full result varies among responses and results and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
*   Gracenote ID.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnId;

/**
*   Gracenote unique ID.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*  Product ID, aka Tag ID
*  <p><b>Remarks:</b></p>
*  This value can be stored or transmitted - it is a static identifier for the current content and will not change over time.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*  TUI (title unique identifier)
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*  TUI tag
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*  Production type, e.g., Animation. This is a list/locale dependent field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. The SDK returns
*  a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
*  information.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoProductionType;

/**
*  Production type identifier
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) videoProductionTypeId;

/**
*  Original release date. Available for video Products, Features, and
*  Works.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateOriginalRelease;

/**
*  Duration value such as "3600" (seconds) for a 60-minute
*  program. Available for video Chapters, Features, Products, Seasons, Series, and Works.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Duration units type (seconds, "SEC"). Available for video
*  Chapters, Features, Products, Seasons, Series, and Works.
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
*  Plot synopsis, e.g., "A semi-autobiographical coming-of-age story"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsis;

/**
*  Plot tagline, e.g., "If you forgot what terror was like...its back"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotTagline;

/**
*  Plot synopsis language, e.g., English
*  <p><b>Remarks:</b></p>
*  The language depends on availability: information in the language set
*  for the locale may not be available, and the object's information may be available only in its
*  default official language. For example, if a locale's set language is Spanish, but the object's
*  information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsisLanguage;

/**
*  Video serial type, e.g., Episode.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> objec. The SDK returns
*  a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for a list-based value
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) serialType;

/**
*  Work type, e.g., Musical
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
*  call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
*  <code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
*  a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
*  information.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) workType;

/**
*  Audience, e.g., "Young Adult"
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) audience;

/**
*  Video mood, e.g., Somber
*  <p><b>Remarks:</b></p>
*  Mood information for music and video, depending on the respective calling type.
* @ingroup GDO_ValueKeys_Music
*/ 

-(NSString*) videoMood;

/**
*  Story type, e.g., "Love Story"
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) storyType;

/**
*  Reputation, e.g., Cult
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) reputation;

/**
*  Scenario, e.g., Drama
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
*  call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
*  <code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
*  a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
*  information.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) scenario;

/**
*  Setting environment, e.g., Skyscraper.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) settingEnvironment;

/**
*  Historical time period such as "Elizabethan Era, 1558-1603"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) settingTimePeriod;

/**
*  Source, e.g., "Phillip K. Dick short story".
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) source;

/**
*  Style, such as "Film Noir"
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) style;

/**
*  Topic, such as Racing
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) topic;

/**
*  Genre, e.g., Comedy. This ia a list/locale dependent, multi-level object.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

/**
*  Geographic location, e.g., "New York City". This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) origin: (GnDataLevel)level;

/**
*  Rating object
* @ingroup GDO_ValueKeys_Misc
*/ 

-(GnRating*) rating;

/**
* Official title object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*   Franchise title object.
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) franchiseTitle;

/**
*  Iterator for external IDs, supports Link data.
*  <p><b>Remarks:</b></p>
*  External IDs identify a source external to Gracenote (e.g., NetFlix), that also have an identifier for this work.
*  The ordinal parameter indicates the n'th child external ID to retrieve.
*
* @ingroup GDO_ChildKeys_ExternalId
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* Iterator for child works.
* @ingroup GDO_ChildKeys_Works
*/ 

-(GnVideoWorkEnumerator*) works;

/**
* Iterator for child video products
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoProductEnumerator*) products;

/**
*  Iterator for child seasons
*  <p><b>Remarks:</b></p>
*  The ordinal parameter indicates the n'th child video season to retrieve.
*  Video product types are generally available from video season Gracenote data objects.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoSeasonEnumerator*) seasons;

/**
*   Iterable for child video credits.
*  <p><b>Remarks:</b></p>
*  The ordinal parameter indicates the n'th child video credit to retrieve.
* @ingroup GDO_ChildKeys_Credit
*/ 

-(GnVideoCreditEnumerator*) videoCredits;

/**
* Iterator for the content (cover art, biography, etc.)  associated with this video work.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;


@end


@interface GnVideoSeriesEnumerator : NSEnumerator

typedef void (^GnVideoSeriesBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoSeriesBlock)handler;

-(NSUInteger) count;

-(GnVideoSeries*) nextObject;

-(GnVideoSeries*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoSeries_h_ */

