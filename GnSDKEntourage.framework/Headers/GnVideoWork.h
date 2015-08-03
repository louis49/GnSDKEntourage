/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoWork_h_
#define _GnVideoWork_h_


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
#import "GnVideoSeries.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnVideoCreditEnumerator;
@class GnVideoProductEnumerator;
@class GnVideoSeasonEnumerator;
@class GnVideoSeriesEnumerator;


/**
* \class GnVideoWork
*/ 

@interface GnVideoWork : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnVideoWork
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
*  Flag indicating if result contains full (true) or partial metadata.
* <p><b>Note:</b></p>
*  What constitutes a full result varies among response types and results and also
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
*   Gracenote unique identifier
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*  Product ID aka Tag ID
*  <p><b>Remarks:</b></p>
*  This value which can be stored or transmitted - it can be used as a static identifier for the current
*  content and will not change over time.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*  TUI (title-unique identifier)
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*  TUI tag
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*  Second TUI, if it exists. This TUI is used
*   for matching partial Products objects to full Works objects.
*  Use this value to ensure correct Tui value matching for cases when a video Product GDO contains
*  multiple partial Work GDOs. Each partial Work GDO corresponds
*  to a full Works object, and each full Works object contains the GNSDK_GDO_VALUE_TUI value,
*  incremented by one digit to maintain data integrity with Gracenote Service.
*  The GNSDK_GDO_VALUE_TUI_MATCH_PRODUCT maps the partial Works object Tui value to the full Works
*   object.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiMatchProduct;

/**
*  Video production type ID
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) videoProductionTypeId;

/**
*  Video production type, e.g., Animation. This is a list/locale dependent value.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoProductionType;

/**
*  Video's original release date.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateOriginalRelease;

/**
*  Duration value in seconds such as "3600" (seconds) for a 60-minute program.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Duration units value (seconds, "SEC").
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) durationUnits;

/**
*  Franchise number
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) franchiseNum;

/**
* Franchise count
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) franchiseCount;

/**
*  Series episode value
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seriesEpisode;

/**
*  Series episode count
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seriesEpisodeCount;

/**
*  Season episode value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonEpisode;

/**
*  Season episode count
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonEpisodeCount;

/**
*  Season count value
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonCount;

/**
* Season number value
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) seasonNumber;

/**
*  Plot synopsis e.g., "A semi-autobiographical coming-of-age story"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsis;

/**
*  Plot tagline, e.g., "The Third Dimension is Terror"
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotTagline;

/**
*  Plot synopis language, e.g., English
*  <p><b>Remarks:</b></p>
*  The language of a returned object depends on availability. Information in the language set
*   for the locale may not be available, and the object's information may be available only in its
*   default official language. For example, if a locale's set language is Spanish, but the object's
*   information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsisLanguage;

/**
*  Supported video serial type such as Series or Episode
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
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
*   <code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
*   a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
*   information.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) workType;

/**
*  Audience type, e.g.,"Kids and Family", "African-American", or "Young Adult".
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) audience;

/**
*  Mood, e.g., Playful
* @ingroup GDO_ValueKeys_Music
*/ 

-(NSString*) videoMood;

/**
*  Story type, e.g., "Love Story".
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
*   Scenario, e.g., "Action", "Comedy", and "Drama".
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) scenario;

/**
*  Physical environment - this is not specific location, but rather a general (or generic)
*  location. For example: Prison, High School, Skyscraper, Desert, etc.
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
* Historical time setting, e.g., "Elizabethan Era 1558-1603", or "Jazz Age 1919-1929".
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) settingTimePeriod;

/**
*  Story concept source, e.g., "Fairy Tales and Nursery Rhymes".
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
*  Film style, e.g.,  "Film Noir".
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
*  Film topic, e.g., "Racing" or "Teen Angst".
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
*  Film's reputation, e.g., "Classic", "Chick Flick", or "Cult". This is a critical or
*  popular "value" that is assigned to a work, usually long after the work was released, though some works may qualify
*  shortly after release (e.g., "instant classic" or "blockbuster release").
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

-(NSString*) reputation;

/**
*  Geographic location, e.g., "New York City". This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
*  call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
*  <code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
*  a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
*  information.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) origin: (GnDataLevel)level;

/**
* Genre - e.g., comedy. This is a list/locale dependent, multi-level field.
*
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
*  This is a multi-level field requiring a <code>GnDataLevel</code> parameter
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

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
*  Franchise title object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) franchiseTitle;

/**
*  Series title object.
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) seriesTitle;

/**
*   Iterator for child products
* @ingroup GDO_ChildKeys_Products
*/ 

-(GnVideoProductEnumerator*) products;

/**
*  Iterator for child credits. For music types, this includes
*   all credits except the artist credit.
* @ingroup GDO_ChildKeys_Credit
*/ 

-(GnVideoCreditEnumerator*) videoCredits;

/**
*  Iterator for child seasons.
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child video Season to retrieve.
*  Video product types are generally available from GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON GDOs.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoSeasonEnumerator*) seasons;

/**
* Iterator for child series'
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the the n'th child   video Series to retrieve.
*  Video Series types are generally available from GNSDK_GDO_TYPE_RESPONSE_VIDEO_SERIES GDOs.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoSeriesEnumerator*) series;

/**
*  Iterator for external IDs.  External IDs are 3rd party IDs used to cross link this metadata to 3rd party services, e.g. Amazon
* @ingroup GDO_ChildKeys_ExternalId
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* Iterator for the content (cover art, biography, etc.)  associated with this video work.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoWork*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoWorkEnumerator : NSEnumerator

typedef void (^GnVideoWorkBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoWorkBlock)handler;

-(NSUInteger) count;

-(GnVideoWork*) nextObject;

-(GnVideoWork*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoWork_h_ */

