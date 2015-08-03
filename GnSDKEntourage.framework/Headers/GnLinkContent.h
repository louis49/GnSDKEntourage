/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLinkContent_h_
#define _GnLinkContent_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* GnLinkContent
*/ 

@interface GnLinkContent : NSObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnLinkContent
*/
-(INSTANCE_RETURN_TYPE) initWithContentData: (unsigned char*)contentData dataSize: (NSUInteger)dataSize contentType: (GnLinkContentType)contentType dataType: (GnLinkDataType)dataType;

/**
* Copy content data to provided buffer (must be of at least DataSize() )
* @param pre_allocaled_byte_buffer
*/ 

-(void) dataBuffer: (unsigned char*)pre_allocated_byte_buffer;

/**
* Retrieves content data buffer
*/ 

-(const unsigned char*) contentData;

/**
* Retrieves content data buffer size
*/ 

-(NSUInteger) dataSize;

/**
* Retrieves content data type
*/ 

-(GnLinkDataType) dataType;


@end



#endif /* _GnLinkContent_h_ */

