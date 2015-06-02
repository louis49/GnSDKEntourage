/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEpgTvAiringsQuery_h_
#define _GnEpgTvAiringsQuery_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnResponseEpgTvAirings.h"
#import "GnTVChannel.h"




/**
* GnEpgTvAiringsQuery
*/
@interface GnEpgTvAiringsQuery : NSObject

/**
* Add a TV channel as an input to the query. At least one TV channel must be added.
*
* @param tvChannel [in] TV channel
* @param ident [in] Optional string identifier returned with the match result
*/ 

-(void) addTvChannel: (GnTVChannel*)tvChannel ident: (NSString*)ident error: (NSError**)error;

/**
* Set a TV airing start time as an input to the query
* 
* @param year
* @param month
* @param day
* @param hour
* @param minute
*/ 

-(void) setAiringStartTime: (NSUInteger)year month: (NSUInteger)month day: (NSUInteger)day hour: (NSUInteger)hour minute: (NSUInteger)minute error: (NSError**)error;

/**
* Set a TV airing end time as an input to the query
* 
* @param year
* @param month
* @param day
* @param hour
* @param minute
*/ 

-(void) setAiringEndTime: (NSUInteger)year month: (NSUInteger)month day: (NSUInteger)day hour: (NSUInteger)hour minute: (NSUInteger)minute error: (NSError**)error;

/**
* Set a start index of the results as an input to the query. This is used to page through the results.
* 
* @param index
*/ 

-(void) setRangeStart: (NSUInteger)index error: (NSError**)error;

/**
* Set the max size of the results as an input to the query. This is used to page through the results.
* 
* @param index
*/ 

-(void) setRangeSize: (NSUInteger)size error: (NSError**)error;

/**
* Set a program title as an input to the query.
*/ 

-(void) setProgramTitle: (NSString*)programTitle error: (NSError**)error;

/**
* FindTvAirings
*/
-(GnResponseEpgTvAirings*) findTvAirings:(NSError**) error;


@end



#endif /* _GnEpgTvAiringsQuery_h_ */

