/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLinkOptions_h_
#define _GnLinkOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* GnLinkOptions
*/
@interface GnLinkOptions : NSObject

/** Set this link query lookup mode.
* @param lookupMode		Lookup mode
* @ingroup Link_Options
*/ 

-(void) lookupMode: (GnLookupMode)lookupMode error: (NSError**)error;

/**
*  Explicitly identifies the track of interest by its ordinal number. This option takes precedence
*   over any provided by track indicator.
*  @ingroup Link_Options
*/ 

-(void) trackOrdinal: (NSUInteger)number error: (NSError**)error;

/**
*  This option sets the source provider of the content (for example, "Acme").
*  @ingroup Link_Options
*/ 

-(void) dataSource: (NSString*)datasource error: (NSError**)error;

/**
*  This option sets the type of the provider content (for example, "cover").
*  @ingroup Link_Options
*/ 

-(void) dataType: (NSString*)datatype error: (NSError**)error;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup Link_Options
*/ 

-(void) networkInterfaceWithIntfName: (NSString*)intfName error: (NSError**)error;

/**
* Return network interface being use with this object's connections if one has been set. 
* If no specific network interface has been set this option will return an empty string.
*  @ingroup Link_Options
*/ 

-(NSString*) networkInterface:(NSError**) error;

/**
*  Clears all options currently set for a given Link query.
*  <p><b>Remarks:</b></p>
*  As Link query handles can be used to retrieve multiple enhanced data items, it may be appropriate
*   to specify different options between data retrievals. You can use this function to clear all options
*   before setting new ones.
*  @ingroup Link_Options
*/ 

-(void) clear:(NSError**) error;


@end



#endif /* _GnLinkOptions_h_ */

