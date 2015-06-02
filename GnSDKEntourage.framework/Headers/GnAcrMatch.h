/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
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
* \class GnAcrMatch
* Class for Automatic Content Recognition match response
*/ 

@interface GnAcrMatch : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*	Match position
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSUInteger) matchPosition;

/**
* Current position in milliseconds of the matched track.
* The current position tracks the approximate real time position of the
* playing content 
* @return Current position in milliseconds
*/ 

-(NSUInteger) currentPosition;

/**
* The date this content was ingested into the Gracenote Service 
* Uses ISO 8601 Date format, e.g. 2014-01-01T00:00:01,000000000
* @return fingerprint creation date 
*/ 

-(NSString*) fingerprintCreationDate;

/**
*	Official title
*	@ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*	Subtitle. Used primarily with TV programs.
*	@ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) subtitle;

/**
* Video work
*/ 

-(GnVideoWork*) avWork;

/**
* TV airing
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

