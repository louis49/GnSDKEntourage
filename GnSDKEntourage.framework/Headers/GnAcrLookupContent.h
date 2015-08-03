/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrLookupContent_h_
#define _GnAcrLookupContent_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAcrLookupContent.h"




/**
* Indicates the type of metadata that should be queried
*/ 

@interface GnAcrLookupContent : NSObject

/**
* GnAcrLookupContent
*/
-(INSTANCE_RETURN_TYPE) init;

/** Clear the requested lookup content */ 

-(GnAcrLookupContent*) clear;

/** Request a query for video metadata (e.g. TV airing, video work, advertisement, external ID) */ 

-(GnAcrLookupContent*) video;

/** Request a query for music metadata (e.g. album) */ 

-(GnAcrLookupContent*) music;

/** Request a query for custom metadata in the local database. You must enable a lookup source that specifies a query to the local database. */ 

-(GnAcrLookupContent*) customData;


@end



#endif /* _GnAcrLookupContent_h_ */

