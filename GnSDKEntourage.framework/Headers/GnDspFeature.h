/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnDspFeature_h_
#define _GnDspFeature_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**************************************************************************
** GnDspFeature
*/ 

@interface GnDspFeature : NSObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* FeatureData
*/
-(NSString*) featureData;

/**
* FeatureQuality
*/
-(GnDspFeatureQuality) featureQuality;


@end



#endif /* _GnDspFeature_h_ */

