/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoSide_h_
#define _GnVideoSide_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTitle.h"
#import "GnVideoLayer.h"


@class GnVideoLayerEnumerator;


/**
* \class GnVideoSide 
* Both DVDs and Blu-ray discs can be dual side. Double-Sided discs include a single layer on each side of the disc
* that data can be recorded to. Double-Sided recordable DVDs come in two formats: DVD-R and DVD+R, including the rewritable DVD-RW and
* DVD+RW. These discs can hold about 8.75GB of data if you burn to both sides. Dual-side Blu-ray discs can store 50 GB of
* data (25GB on each side).
*/ 

@interface GnVideoSide : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Ordinal value
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) ordinal;

/**
*  Matched boolean value indicating whether this type
*  is the one that matched the input criteria.
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
*  Iterator for video layers
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child video layer to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoLayerEnumerator*) layers;


@end


@interface GnVideoSideEnumerator : NSEnumerator

typedef void (^GnVideoSideBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoSideBlock)handler;

-(NSUInteger) count;

-(GnVideoSide*) nextObject;

-(GnVideoSide*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoSide_h_ */

