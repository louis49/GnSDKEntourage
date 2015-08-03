/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoLayer_h_
#define _GnVideoLayer_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnVideoFeature.h"


@class GnVideoFeatureEnumerator;


/**
* \class GnVideoLayer
* Both DVDs and Blu-ray Discs can be dual layer. These discs are only writable on one side of the disc,
* but contain two layers on that single side for writing data to. Dual-Layer recordable DVDs come in two formats: DVD-R DL and DVD+R DL.
* They can hold up to 8.5GB on the two layers. Dual-layer Blu-ray discs can store 50 GB of data (25GB on each layer)
*/ 

@interface GnVideoLayer : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Ordinal value
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) ordinal;

/**
*  Matched boolean value indicating whether this object
*   is the one that matched the input criteria.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) matched;

/**
*  Aspect ratio - describes the proportional relationship between the video's width and its height
* expressed as two numbers separated by a colon
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatio;

/**
*  Aspect ratio type, e.g. Standard
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) aspectRatioType;

/**
*  TV system value, e.g., NTSC.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) tvSystem;

/**
*  Region code, e.g., FE - France
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) regionCode;

/**
*  Video product region value from the current type, e.g., 1. This is a list/locale dependent value.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoRegion;

/**
*  Video product region, e.g.,  USA, Canada, US Territories, Bermuda, and Cayman Islands.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, the application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) videoRegionDesc;

/**
*  Video media type such as Audio-CD, Blu-ray, DVD, or HD DVD.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) mediaType;

/**
*  Iterator for child video features.
*  <p><b>Remarks:</b></p>
*  The ordinal parameter specifies the n'th child  video feature to retrieve.
* @ingroup GDO_ChildKeys_Video
*/ 

-(GnVideoFeatureEnumerator*) features;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoLayer*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnVideoLayerEnumerator : NSEnumerator

typedef void (^GnVideoLayerBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoLayerBlock)handler;

-(NSUInteger) count;

-(GnVideoLayer*) nextObject;

-(GnVideoLayer*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoLayer_h_ */

