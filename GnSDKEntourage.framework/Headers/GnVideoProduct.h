/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoProduct_h_
#define _GnVideoProduct_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContent.h"
#import "GnEnums.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnRating.h"
#import "GnTitle.h"
#import "GnVideoDisc.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnVideoDiscEnumerator;


/**
* \class GnVideoProduct
* A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a
* unique commercial code such as a UPC (Univeral Product Code), Hinban, or EAN (European Article Number).
* Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

@interface GnVideoProduct : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnVideoProduct
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
*  Flag indicating if response result contains full (true) or partial metadata
*	<p><b>Remarks:</b></p>
*	Available for the following music and video types:
*  <ul>
*  <li>Album
*  <li>Contributor
*  <li>Track
*  <li>Product
*  <li>Season
*  <li>Series
*  <li>Work
*  </ul>
*	<p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
*	depends on data availability.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
*	Gracenote ID
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnId;

/**
*	Gracenote unique ID
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*	Product ID aka Tag ID
*	<p><b>Remarks:</b></p>
*	Available for most types, this value which can be stored or transmitted - it can bw used as a static identifier for the current content
*  and will not change over time.
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*	Tui (title-unique identifier)
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*	Tui Tag value
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*	Package display language, e.g., "English"
*  <p><b>Remarks:</b></p>
*	The language depends on availability - information in the language set
*	for the locale may not be available, and the object's information may be available only in its
*	default official language. For example, if a locale's set language is Spanish, but the object's
*	information is available only in English, this value returns as English.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) packageLanguageDisplay;

/**
*	Package language ISO code, e.g., "eng".
*	<p><b>Remarks:</b></p>
*	GNSDK supports a subset of the ISO 639-2 Language Code List.
*	Specify a locale language's lower-case three-letter code, which is shown in the macro's C/C++
*	syntax section.
*	<p><b>Note:</b></p>
*   The following languages use Gracenote-specific three-letter codes:
*  <ul>
*  <li>qtb (Simplified Chinese)*
*  <li>qtd (Traditional Chinese)*
*  </ul>
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) packageLanguage;

/**
*	Video production type value, e.g., Documentary
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoProductionType;

/**
*	Video production type identifier value
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) videoProductionTypeId;

/**
*	Original release date in UTC format.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateOriginalRelease;

/**
*	Release date in UTC format
*	<p><b>Remarks:</b></p>
*	Release date values are not always available.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateRelease;

/**
*	Duration value in seconds, such as "3600" for a 60-minute program.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*	Duration units value (seconds, "SEC").
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) durationUnits;

/**
*	Aspect ratio- describes the proportional relationship between the video's width and its height
* expressed as two numbers separated by a colon
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatio;

/**
*	Aspect ratio type, e.g., Standard
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatioType;

/**
*	Video product region value, e.g, 1
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoRegion;

/**
*	Video product region description, e.g., USA, Canada, US Territories, Bermuda, and Cayman Islands
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoRegionDesc;

/**
*	Notes
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) notes;

/**
*	Commerce type value
*	<p><b>Remarks:</b></p>
*	For information on the specific values this key retrieves, contact your Gracenote Support
*	Services representative.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) commerceType;

/**
*  Genre, e.g., Comedy. This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
*  This is a multi-level field requiring a <code>GnDataLevel</code> parameter
*
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

/**
* Rating object.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(GnRating*) rating;

/**
*	Official child title object
*	@ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*  Iterator for external IDs.  External IDs are 3rd party IDs used to cross link this metadata to 3rd party services, e.g. Amazon
*  The ordinal parameter specifies the n'th child external ID to retrieve.
* @ingroup GDO_ChildKeys_ExternalId
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
*	Iterator for child video discs.
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child video disc to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoDiscEnumerator*) discs;

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
+(GnVideoProduct*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoProductEnumerator : NSEnumerator

typedef void (^GnVideoProductBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoProductBlock)handler;

-(NSUInteger) count;

-(GnVideoProduct*) nextObject;

-(GnVideoProduct*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoProduct_h_ */

