/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLookupFpLocal_h_
#define _GnLookupFpLocal_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnBundleSourceDelegate.h"
#import "GnCancellableDelegate.h"
#import "GnDataObject.h"
#import "GnFpLocalCustomData.h"
#import "GnLookupFpLocal.h"




/**************************************************************************
** GnLookupFpLocal
*/ 

@interface GnLookupFpLocal : NSObject

/**
* Initializes the LookupFpLocal library.
*/ 

+(GnLookupFpLocal*) enable:(NSError**) error;

/**
*  Retrieves GnLookupFpLocal SDK version string.
*  This API can be called at any time, after getting an instance of GnManager successfully. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/ 

+(NSString*) version;

/**
*  Retrieves the GnLookupFpLocal SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting an instance of GnManager successfully. The returned
* string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(NSString*) buildDate;

/**
*  This method is used to specify the location of GnLookupFpLocal database. 
*  @param gnsdk_cstr_t location of the database
*  @return void 
*/ 

-(void) storageLocation: (NSString*)location error: (NSError**)error;

/**
*  This method is used to ingest a bundleitem. The caller would need to supply 
*  the callback which gets called from the GnLookupFpLocal to read the data from the 
*  bundleitem. After the GnLookupFpLocal ingests a bundleitem successfully it stores
*  it in cache for future lookups. 
*  @param ingestSource GnBundleSourceDelegate
*  @return void 
*/ 

-(void) bundleIngest: (id <GnBundleSourceDelegate>)ingestSource error: (NSError**)error;

/**
*  This method is used to clear all the bundleitems in GnLookupFpLocal.
*  @return void 
*/ 

-(void) cacheClearAll:(NSError**) error;

/**
*  This method is used to delete a bundleitem in GnLookupFpLocal.
*  @return void 
*/ 

-(void) cacheDelete: (NSString*)bundleId error: (NSError**)error;

/**
*  Retrieves the GnFpLocalCustomData object from a supplied gdo.
*  @return GnFpLocalCustomData object 
*/ 

-(GnFpLocalCustomData*) customData: (GnDataObject*)dataobject;


@end



#endif /* _GnLookupFpLocal_h_ */

