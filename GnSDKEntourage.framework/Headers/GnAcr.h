/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcr_h_
#define _GnAcr_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
*  This class provides information about the ACR library
*/ 

@interface GnAcr : NSObject

/**
*  ACR library's version string.
*
*  This API can be called at any time. The returned
*   string is a constant - DO NOT attempt to modify or delete.
*
*  Example: <code>1.2.3.123</code> (Major.Minor.Improvement.Build)<br>
*  Major: New functionality<br>
*  Minor: New or changed features<br>
*  Improvement: Improvements and fixes<br>
*  Build: Internal build number<br>
* @ingroup Acr_InitializationFunctions
*/ 

+(NSString*) version;

/**
*  ACR library's build date as a string.
*  @return String with format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time. The returned
*   string is a constant - DO NOT attempt to modify or delete.
*
*  Example:<code>"2008-02-12 00:41 UTC"</code>
* @ingroup Acr_InitializationFunctions
*/ 

+(NSString*) buildDate;


@end



#endif /* _GnAcr_h_ */

