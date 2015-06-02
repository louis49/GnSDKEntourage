/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoDisc_h_
#define _GnVideoDisc_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTitle.h"
#import "GnVideoSide.h"


@class GnVideoSideEnumerator;


/**
* \class GnVideoDisc
* A video disc can be either DVD (Digital Video Disc) or Blu-ray.
*/ 

@interface GnVideoDisc : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnVideoDisc
*/
-(INSTANCE_RETURN_TYPE) initWithId: (NSString*)id idTag: (NSString*)idTag;

/**
* Gracenote ID
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnId;

/**
* Gracenote unique ID
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*  Product ID aka Tag ID
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*  TUI - title-unique identifier
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
* Tui Tag value
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*  Ordinal value
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) ordinal;

/**
*  Matched boolean value indicating whether this type
*   is the one that matched the input criteria.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) matched;

/**
*  Notes
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) notes;

/**
*  Official title object
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*  Iterator for child video sides
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child video side to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoSideEnumerator*) sides;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoDisc*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoDiscEnumerator : NSEnumerator

typedef void (^GnVideoDiscBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoDiscBlock)handler;

-(NSUInteger) count;

-(GnVideoDisc*) nextObject;

-(GnVideoDisc*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoDisc_h_ */

