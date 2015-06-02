/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnFpLocalCustomData_h_
#define _GnFpLocalCustomData_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnFpLocalCustomData.h"




/**************************************************************************
** GnFpLocalCustomData
*/ 

@interface GnFpLocalCustomData : GnDataObject

/**
* Constructs empty GnFpLocalCustomData object
*/ 

-(INSTANCE_RETURN_TYPE) init;

/**
* GnFpLocalCustomData
*/
-(INSTANCE_RETURN_TYPE) initWithGnFpLocalCustomData: (GnFpLocalCustomData*)copy;

/**
*  Retrieves the DataID associated with this object  
*  @return gnsdk_cstr_t 
*/ 

-(NSString*) dataID;

/**
*  Retrieves the Data associated with this object  
*  @return const gnsdk_byte_t*
*  This API throws an exception. It is important to have the GnLookFpLocal
*  enabled to access the data.
*/ 

-(const unsigned char*) data:(NSError**) error;

/**
*  Retrieves the size of the data associated with this object  
*  @return gnsdk_uint32_t 
*  This API throws an exception. It is important to have the GnLookFpLocal
*  enabled to access the data.
*/ 

-(NSUInteger) dataSize:(NSError**) error;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnFpLocalCustomData*) from: (GnDataObject*)obj error: (NSError**)error;


@end



#endif /* _GnFpLocalCustomData_h_ */

