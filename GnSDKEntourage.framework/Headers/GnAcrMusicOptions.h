/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrMusicOptions_h_
#define _GnAcrMusicOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
*  This class allows you to set options for music queries.
*/ 

@interface GnAcrMusicOptions : NSObject

/**
*  Get whether a music query must return only the single best result.
*  @return Return true, if a single full result is returned. Return false, if multiple partial results may be returned.
*  @ingroup Acr_Options
*/ 

-(BOOL) resultSingle:(NSError**) error;

/**
*  Set whether a music query must return only the single best result.
*  @param enable [in] If set to true, a single full result is returned. If set to false, multiple partial results may be returned.
*  @ingroup Acr_Options
*/ 

-(void) resultSingleWithEnable: (BOOL)enable error: (NSError**)error;

/**
* Get the preferred external ID. When set, this indicates that a music query should preferrably
* return results associated with a particular third-party identifier. Your app
* can use this option to only access third-party IDs from a particular vendor.
* @return The identifier of the preferred third-party vendor or an empty string if the option has
* not been set
* @ingroup Acr_Options
*/ 

-(NSString*) preferResultExternalId:(NSError**) error;

/**
* Set the preferred external ID. When set, this indicates that a music query should preferrably
* return album results associated with a particular third-party identifier. Use this option to only access
* external IDs from a particular vendor.
* @param preferredExternalId [in] The identifier of the preferred third-party vendor
* @ingroup Acr_Options
*/ 

-(void) preferResultExternalIdWithPreferredExternalId: (NSString*)preferredExternalId error: (NSError**)error;

/**
*  Get whether a music query must return only the single best result and that the result
*  should preferably have cover art. When enabled, a single full result is returned. When disabled, multiple
*  partial results may be returned.
*  @return Returns true if enabled. Returns false if not enabled.
*  @ingroup Acr_Options
*/ 

-(BOOL) preferResultCoverArt:(NSError**) error;

/**
*  Set whether a music query must return only the single best result and that the result
*  should preferably have cover art.
*  @param enable [in] If set to true, a single full result is returned. If set to false, multiple partial results may be returned.
*  @ingroup Acr_Options
*/ 

-(void) preferResultCoverArtWithEnable: (BOOL)enable error: (NSError**)error;


@end



#endif /* _GnAcrMusicOptions_h_ */

