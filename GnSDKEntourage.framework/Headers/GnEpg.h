/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEpg_h_
#define _GnEpg_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnDataObject.h"
#import "GnEpgOptions.h"
#import "GnEnums.h"
#import "GnEpgTvAiringsQuery.h"
#import "GnEpgTvChannelsQuery.h"
#import "GnResponseEpgChannels.h"
#import "GnResponseEpgProgram.h"
#import "GnResponseEpgTvProvider.h"
#import "GnStatusEventsDelegate.h"
#import "GnTVChannel.h"
#import "GnTVProgram.h"
#import "GnTVProvider.h"
#import "GnUser.h"




/**
*  The GnEpg class is used to query TV metadata
*/ 

@interface GnEpg : NSObject

/**
*  Initializes the Gracenote EPG library.
*  @param user				[in] Set user
*  @param pEventHandler	[in] GnStatusEventsDelegate
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user statusEventsDelegate: (id <GnStatusEventsDelegate>)pEventHandler;

/** Retrieves the EPG SDK version string.*/ 

+(NSString*) version;

/** Retrieves the EPG SDK Build Date string.*/ 

+(NSString*) buildDate;

/**
* Options
*/
-(GnEpgOptions*) options;

/**
* Performs an EPG query for television providers. Currently only supports television providers from US and Canada.
*
* @param postalcode [in] postalcode
* @param postalCodeCountry [in] country the postalcode applies to.
* @return GnResponseEpgTvProvider
*
*/ 

-(GnResponseEpgTvProvider*) findTvProvider: (NSString*)postalcode postalcodeCountry: (GnEpgPostalCodeCountry)postalcodeCountry error: (NSError**)error;

/**
* FindTvChannels
*/
-(GnResponseEpgChannels*) findTvChannelsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
* FindTvChannels
*/
-(GnResponseEpgChannels*) findTvChannelsWithTvChannel: (GnTVChannel*)tvChannel error: (NSError**)error;

/**
* FindTvChannels
*/
-(GnResponseEpgChannels*) findTvChannelsWithTvProvider: (GnTVProvider*)tvProvider error: (NSError**)error;

/**
* Build a query to find TV channels using multiple search inputs.
*
* @return GnEpgTvChannelsQuery
**/ 

-(GnEpgTvChannelsQuery*) tvChannelsQuery;

/**
* FindTvPrograms
*/
-(GnResponseEpgProgram*) findTvProgramsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
* FindTvPrograms
*/
-(GnResponseEpgProgram*) findTvProgramsWithTvProgram: (GnTVProgram*)tvProgram error: (NSError**)error;

/**
* Build a query to find TV airings using multiple search inputs.
*
* @return GnEpgAiringFinder
*/ 

-(GnEpgTvAiringsQuery*) tvAiringsQuery;

/**
* SetCancel
*/
-(void) setCancel: (BOOL)bCancel;

/**
* IsCancelled
*/
-(BOOL) isCancelled;


@end



#endif /* _GnEpg_h_ */

