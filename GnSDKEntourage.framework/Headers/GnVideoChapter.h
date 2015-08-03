/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoChapter_h_
#define _GnVideoChapter_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTitle.h"
#import "GnVideoCredit.h"


@class GnVideoCreditEnumerator;


/**
* \class GnVideoChapter
*/ 

@interface GnVideoChapter : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Video chapter's ordinal value.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) ordinal;

/**
*  Chapter's duration value in seconds such as "3600" for a 60-minute program.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) duration;

/**
*  Chapter's duration units value (seconds, "SEC").
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) durationUnits;

/**
*  Official Title object.
* @ingroup GDO_ChildKeys_Title
*/ 

-(GnTitle*) officialTitle;

/**
*   Iterator for child credits. For music,this includes all credits except the artist credit.
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
+(GnVideoChapter*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoChapterEnumerator : NSEnumerator

typedef void (^GnVideoChapterBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoChapterBlock)handler;

-(NSUInteger) count;

-(GnVideoChapter*) nextObject;

-(GnVideoChapter*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoChapter_h_ */

