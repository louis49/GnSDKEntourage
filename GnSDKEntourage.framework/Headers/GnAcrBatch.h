/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrBatch_h_
#define _GnAcrBatch_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAcrEventsDelegate.h"
#import "GnEnums.h"
#import "GnAcrOptions.h"
#import "GnAcrStatus.h"
#import "GnResponseAcrMatch.h"
#import "GnUser.h"




/**
* GnAcrBatch
*/
@interface GnAcrBatch : NSObject

/**
*  <b>Experimental</b>: Class constructor.
*  @param user	[in] Gracenote user
*  @param pEventHandler [in] ACR event handler
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
* @ingroup Acr_InitializationFunctions
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user acrEventsDelegate: (id <GnAcrEventsDelegate>)pEventHandler;

/**
* <b>Experimental</b>: Adds fingerprint data to be used in a batch query
* @param fp_string [in] String representation of fingerprint data
* @param fp_created_time [in] The time in microseconds that the fingerprint was created on the device
* @param user_ident [in] Optional identifier that will be returned with the query result
*
*  <p><b>Remarks:</b></p>
*  Repeated invocations of this method will add multiple fingerprint data to be used in a query.
*	The maximum number of fingerprint data that you may add to a batch query is defined by kMaximumBatchQuerySize.
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
* @ingroup Acr_QueryFunctions
*/ 

-(void) addFingerprintData: (NSString*)fp_string fp_created_time: (NSUInteger)fp_created_time user_ident: (NSString*)user_ident error: (NSError**)error;

/**
* <b>Experimental</b>: Clears all the fingerprint data to be used in a batch query
*
*  <p><b>Remarks:</b></p>
*  This method will remove all the fingerprint data that have been added by the call to
*  AddFingerprintData() but have not yet been used in a query, as indicated by the call
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
*  to Lookup().
* @ingroup Acr_QueryFunctions
*/ 

-(void) clearFingerprintData:(NSError**) error;

/**
* <b>Experimental</b>: Cancels all pending or in-progress batch queries initiated by the call to Lookup().
*
*  <p><b>Remarks:</b></p>
*  As a result of calling this method, all the fingerprint data from each pending or in-progress
*  batch query will be lost.
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
*  to Lookup().
* @ingroup Acr_QueryFunctions
*/ 

-(void) cancelLookup:(NSError**) error;

/**
* <b>Experimental</b>: Performs a batch query for video metadata using all the fingerprint data previously added using AddFingerprintData().
*
*  <p><b>Remarks:</b></p>
*  All the fingerprint data previously added using AddFingerprintData() will only be used by the
*  query initiated by the call to this method. They will not be available for use in any future queries
*  initiated by subsequent calls to this method.
*  Also, note that this is an asynchronous method and that the query result associated with each fingerprint data
*  will be returned to ResultEvent().
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
*  to Lookup().
* @ingroup Acr_QueryFunctions
*/ 

-(void) videoLookup:(NSError**) error;

/**
* Causes the current thread to wait until all active batch queries are completed or the specified timeout has occurred.
*
* <b>Remarks</b>
* This method should be invoked on the same thread as VideoLookup() as shown in the following calling sequence
* <ol>
* <li>VideoLookup()</li>
* <li>WaitForComplete()</li>
* </ol>
*
* @param timeout_ms [in] Maximum wait timeout in milliseconds.
* @return Returns true if internal processes have completed or false if it is still busy and a timeout occurred
*/ 

-(BOOL) waitForCompleteWithTimeout_ms: (NSUInteger)timeout_ms error: (NSError**)error;

/**
* Causes the current thread to wait until all active batch queries are completed.
*
* <b>Remarks</b>
* This method should be invoked on the same thread as VideoLookup() as shown in the following calling sequence
* <ol>
* <li>VideoLookup()</li>
* <li>WaitForComplete()</li>
* </ol>
*
* @return Returns true if internal processes have completed or false if it is still busy
*/ 

-(BOOL) waitForComplete:(NSError**) error;

/**
*  <b>Experimental</b>: Get the GnAcrOptions object for setting/getting options
*  <p><b>Note:</b></p>
*	Your application must be licensed to perform batch queries. Contact Gracenote about enabling batch queries.
*  to Lookup().
* @ingroup Acr_QueryFunctions
*/ 

-(GnAcrOptions*) options;


@end



#endif /* _GnAcrBatch_h_ */

