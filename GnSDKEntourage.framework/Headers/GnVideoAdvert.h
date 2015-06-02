/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoAdvert_h_
#define _GnVideoAdvert_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnName.h"
#import "GnTitle.h"


@class GnExternalIdEnumerator;


/**
* \class GnVideoAdvert
* Class for video advertisement metadata
*/ 

@interface GnVideoAdvert : GnDataObject

/**
* Constructs an empty GnVideoAdvert object
*/ 

-(INSTANCE_RETURN_TYPE) init;

/**
* Retrieves the Gracenote Tui (title-unique identifier)
* @return Tui
*/ 

-(NSString*) tui;

/**
* Retrieves the Gracenote Tui Tag
* @return Tui Tag
*/ 

-(NSString*) tuiTag;

/**
* Retrieves the Gracenote unique identifier.
* @return Gracenote unique identifier
*/ 

-(NSString*) gnUId;

/**
* Indicates whether the video advertisement response result is full (not partial). 
*/ 

-(BOOL) isFullResult;

/**
* Retrieves the official title.
* @return Title
*/ 

-(GnTitle*) title;

/**
* Retrieves the brand name.
* @return Name
*/ 

-(GnName*) brand;

/**
* Retrieves the iterator for external identifiers.
* @return Iterator
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnVideoAdvert*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnVideoAdvert_h_ */

