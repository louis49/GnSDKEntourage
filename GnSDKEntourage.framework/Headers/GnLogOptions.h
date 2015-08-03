/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLogOptions_h_
#define _GnLogOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnLogOptions.h"




/**
*  Logging options specifies what options are applied to the GNSDK log
*/ 

@interface GnLogOptions : NSObject

/**
* GnLogOptions
*/
-(INSTANCE_RETURN_TYPE) init;

/**
* Specify true for the log to be written synchronously (no background thread).
* By default logs are written to asynchronously. No internal logging
* thread is created if all GnLog instances are specified for synchronous
* writing.
* @param bSyncWrite  Set true to enable synchronized writing, false for asynchrounous (default)
*/ 

-(GnLogOptions*) synchronous: (BOOL)bSyncWrite;

/**
* Specify true to retain and rename old logs. 
* Default behavior is to delete old logs.
* @param bArchive  Set true to keep rolled log files, false to delete rolled logs (default)
*/ 

-(GnLogOptions*) archive: (BOOL)bArchive;

/**
* Specify that when archive is also specified the logs to archive (roll)
* at the start of each day (12:00 midnight). Archiving by the given size
* parameter will still occur normally as well.
*/ 

-(GnLogOptions*) archiveDaily;

/**
* Specify the maximum size of log before new log is created. Enter a value of zero (0) to
* always create new log on open
* @param maxSize  Set to maximum size log file should reach to be rolled. 
* Set to zero to always roll log on creation (default)
*/ 

-(GnLogOptions*) maxSize: (NSUInteger)maxSize;


@end



#endif /* _GnLogOptions_h_ */

