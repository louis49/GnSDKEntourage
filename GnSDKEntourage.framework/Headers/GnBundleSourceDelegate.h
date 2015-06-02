/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnBundleSourceDelegate_h_
#define _GnBundleSourceDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"




@protocol GnBundleSourceDelegate <NSObject>

@required

/**
* Get bundle data. Override to provide bundle data for the ingestion process.
* @param dataBuffer		Buffer to write bundle data
* @param dataSize			Size of buffer
* @return Number of bytes written to buffer
*/ 

-(NSUInteger) getBundleData: (unsigned char*)dataBuffer dataSize: (NSUInteger)dataSize cancellableDelegate: (id <GnCancellableDelegate>)canceller;


@end



#endif /* _GnBundleSourceDelegate_h_ */

