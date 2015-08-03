/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrMatch_h_
#define _GnAcrMatch_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAlbum.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnTVAiring.h"
#import "GnTitle.h"
#import "GnVideoAdvert.h"
#import "GnVideoWork.h"


@class GnExternalIdEnumerator;


/**
* The GnAcrMatch class represents the match result of an ACR query. The class contains the specific Gracenote object 
* (e.g. TV airing, video work, advertisement or album) associated with the fingerprint match.
*/ 

@interface GnAcrMatch : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Retrieves the position in the matched content where the fingerprint match occurred. 
* @return match position in milliseconds
* @ingroup GDO_ValueKeys_ACR
*/ 

-(NSUInteger) matchPosition;

/**
* Retrieves the current position in the matched content. This is the GnAcrMatch.MatchPosition plus
* the amount of time that it took to complete the query.
* @return current position in milliseconds
* @ingroup GDO_ValueKeys_ACR
*/ 

-(NSUInteger) currentPosition;

/**
* Retrieves the date that the fingerprint of the matched content was ingested 
* into the Gracenote Service.
* @return The date in ISO 8601 date format, e.g. 2014-01-01T00:00:01,000000000
* @ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) fingerprintCreationDate;

/**
* Retrieves the official title of the matched object. For example, this could be the
* official title of the TV program or video work. It could also be the title of the
* matched track in an album.
* @return the official title of the matched object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*	Retrieves the subtitle of a TV program, if the fingerprint matched to a TV airing.
*  @return the subtitle of a TV program
*	@ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) subtitle;

/**
* Retrieves the video work associated with this fingerprint match. 
* @return the video work associated with this fingerprint match
*/ 

-(GnVideoWork*) avWork;

/**
* Retrieves the TV airing associated with this fingerprint match. 
* @return the TV airing associated with this fingerprint match
*/ 

-(GnTVAiring*) tvAiring;

/**
* AvAdvert
*/
-(GnVideoAdvert*) avAdvert;

/**
* Album
*/
-(GnAlbum*) album;

/**
* Retrieves the iterator for external identifiers associated with this fingerprint match.
* @return the iterator for external identifiers associated with this fingerprint match
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnAcrMatch*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnAcrMatchEnumerator : NSEnumerator

typedef void (^GnAcrMatchBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnAcrMatchBlock)handler;

-(NSUInteger) count;

-(GnAcrMatch*) nextObject;

-(GnAcrMatch*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnAcrMatch_h_ */

