/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoFeature_h_
#define _GnVideoFeature_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnDataObject.h"
#import "GnRating.h"
#import "GnTitle.h"
#import "GnVideoChapter.h"
#import "GnVideoCredit.h"
#import "GnVideoWork.h"


@class GnVideoChapterEnumerator;
@class GnVideoCreditEnumerator;
@class GnVideoWorkEnumerator;


/**
* \class GnVideoFeature 
* Class containing metadata for a video feature, which has a full-length running time usually between 60 and 120 minutes.
* A feature is the main component of a DVD or Blu-ray disc which may, in addition, contain extra, or bonus, video clips and features.
*
*/ 

@interface GnVideoFeature : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Feature's ordinal value
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) ordinal;

/**
*  Matched boolean value indicating whether this type
*  is the one that matched the input criteria. Available from many video types.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) matched;

/**
*  Video feature type value.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoFeatureType;

/**
*  Video production type value.
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
*  Video production ID type value
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) videoProductionTypeId;

/**
*  Release date in UTC format
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateRelease;

/**
*  Original release date in UTC format.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateOriginalRelease;

/**
*  Notes
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) notes;

/**
* Aspect ratio - describes the proportional relationship between the video's width and its height
* expressed as two numbers separated by a colon
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatio;

/**
*  Aspect ratio type, e.g., Standard
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatioType;

/**
*  Duration value in seconds.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Duration units value (e.g., seconds, "SEC")
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) durationUnits;

/**
*  Plot summary
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSummary;

/**
*  Plot synopsis, e.g., (for Friends episode) "Monica's popularity at a karaoke club might have more to do with her revealing dress than her voice;
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsis;

/**
*  Plot tagline, e.g., "The terrifying motion picture from the terrifying No. 1 best seller."
*  GNSDK_GDO_VALUE_PLOT_TAGLINE
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotTagline;

/**
*  Plot synopsis language, e.g., English
*  <p><b>Remarks:</b></p>
*  The language depends on availability - information in the language set
*   for the locale may not be available, and the object's information may be available only in its
*   default official language. For example, if a locale's set language is Spanish, but the object's
*   information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) plotSynopsisLanguage;

/**
* Genre. e.g., Drama. This is a list/locale dependent,multi-level field
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
*  This is a multi-level field requiring a <code>GnDataLevel</code> parameter
*
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

/**
*  Official title object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*  Rating object
* @ingroup GDO_ValueKeys_Misc
*/ 

-(GnRating*) rating;

/**
*  Iterator for child video works
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child  video Work to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoWorkEnumerator*) works;

/**
*  Iterator for child video chapters
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child  video chapter to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoChapterEnumerator*) chapters;

/**
*   Iterable for child credits. For music types, this includes
*   all credits except the artist credit.
* @ingroup GDO_ChildKeys_Credit
*/ 

-(GnVideoCreditEnumerator*) videoCredits;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoFeature*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoFeatureEnumerator : NSEnumerator

typedef void (^GnVideoFeatureBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoFeatureBlock)handler;

-(NSUInteger) count;

-(GnVideoFeature*) nextObject;

-(GnVideoFeature*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoFeature_h_ */

