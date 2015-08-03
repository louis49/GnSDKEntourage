/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTVProvider_h_
#define _GnTVProvider_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnName.h"




/**
* TV provider collection
*/ 

@interface GnTVProvider : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Provider's Gracenote ID.
*/ 

-(NSString*) gnId;

/**
* Provider type
*/ 

-(NSString*) providerType;

/**
* Provider's name object
*/ 

-(GnName*) name;

/**
* Place
*/
-(NSString*) place;


@end


@interface GnTVProviderEnumerator : NSEnumerator

typedef void (^GnTVProviderBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnTVProviderBlock)handler;

-(NSUInteger) count;

-(GnTVProvider*) nextObject;

-(GnTVProvider*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnTVProvider_h_ */

