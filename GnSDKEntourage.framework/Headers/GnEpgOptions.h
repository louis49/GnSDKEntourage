/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEpgOptions_h_
#define _GnEpgOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* GnEpgOptions
*/
@interface GnEpgOptions : NSObject

/**
*  Indicates the lookup data value for the EPG query.
*  @param lookupData [in] One of the GnLookupData values
*  @param bEnable    [in] Enable lookup data
*  @ingroup Epg_Options
*/ 

-(void) lookupData: (GnLookupData)lookupData bEnable: (BOOL)bEnable error: (NSError**)error;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup Epg_Options
*/ 

-(void) networkInterfaceWithIntfName: (NSString*)intfName error: (NSError**)error;

/**
* Return network interface being use with this object's connections if one has been set. 
* If no specific network interface has been set this option will return an empty string.
*  @ingroup Epg_Options
*/ 

-(NSString*) networkInterface:(NSError**) error;

/**
*  General option setting for custom string options
*  @param optionKey   [in] Option name
*  @param value	   [in] Option value
*  @ingroup Epg_Options
*/ 

-(void) custom: (NSString*)optionKey value: (NSString*)value error: (NSError**)error;


@end



#endif /* _GnEpgOptions_h_ */

