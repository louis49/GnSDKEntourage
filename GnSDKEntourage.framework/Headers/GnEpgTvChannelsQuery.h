/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEpgTvChannelsQuery_h_
#define _GnEpgTvChannelsQuery_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnResponseEpgChannels.h"




/**
* GnEpgTvChannelsQuery
*/
@interface GnEpgTvChannelsQuery : NSObject

/**
* Add a dvb triplet as an input to the query. 
*
* @param id [in] For DVB ids, the format is {dvb|dvbs|dvbt|dbvc}://{onid}.{tsid}.{sid}
* @param ident [in] Optional string identifier returned in the GnTvChannel object, if this DVB triplet results in a match.
*/ 

-(void) addDvbTriplet: (NSString*)id ident: (NSString*)ident error: (NSError**)error;

/**
* Find TV channels based on query inputs. Must add at least one channel ID (e.g. dvb triplet) as an input to the query.
*
* @return GnResponseEpgChannels 
*/ 

-(GnResponseEpgChannels*) findTvChannels:(NSError**) error;


@end



#endif /* _GnEpgTvChannelsQuery_h_ */

