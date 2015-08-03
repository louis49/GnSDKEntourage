/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTVAiring_h_
#define _GnTVAiring_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnRating.h"
#import "GnTVChannel.h"
#import "GnTVProgram.h"




/**
* \class GnTVAiring
*/ 

@interface GnTVAiring : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*	Tui - title-unique identifier
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*	Tui Tag.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*	Date start value
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateStart;

/**
*	Date end value
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) dateEnd;

/**
*	Duration value in seconds, such as "3600" for a 60-minute program.
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Duration units value (seconds, "SEC")
*/ 

-(NSString*) durationUnits;

/**
*	EPG viewing type
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) epgViewingType;

/**
*	EPG audio type
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) epgAudioType;

/**
*	EPG video type
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) epgVideoType;

/**
*	EPG caption type
*	@ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) epgCaptionType;

/**
*	Rating object.
*	@ingroup GDO_ValueKeys_Misc
*/ 

-(GnRating*) rating;

/**
* TvProgram
*/
-(GnTVProgram*) tvProgram;

/**
* TvChannel
*/
-(GnTVChannel*) tvChannel;


@end


@interface GnTVAiringEnumerator : NSEnumerator

typedef void (^GnTVAiringBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnTVAiringBlock)handler;

-(NSUInteger) count;

-(GnTVAiring*) nextObject;

-(GnTVAiring*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnTVAiring_h_ */

