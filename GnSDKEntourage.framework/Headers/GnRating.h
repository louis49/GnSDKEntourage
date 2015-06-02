/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnRating_h_
#define _GnRating_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"




/**
* \class GnRating
*/ 

@interface GnRating : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Rating value, e.g., PG
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) rating;

/**
*  Rating type value, e.g., MPAA .
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingType;

/**
*  Rating description .
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingDesc;

/**
*  Rating type Id.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSUInteger) ratingTypeId;

/**
*  Rating reason
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingReason;

/**
*  AMPAA (Motion Picture Assoc. of America) rating.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingMPAA;

/**
*  A MPAA (Motion Picture Assoc. of America) TV rating type.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingMPAATV;

/**
*  A FAB (Film Advisory Board) rating.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingFAB;

/**
*  A CHVRS (Canadian Home Video Rating System) rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingCHVRS;

/**
*  A Canadian TV rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingCanadianTV;

/**
*  A BBFC (British Board of Film Classification) rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingBBFC;

/**
*  A CBFC (Central Board of Film Certification) rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingCBFC;

/**
*  A OFLC (Australia) TV rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingOFLC;

/**
*  A Hong Kong rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingHongKong;

/**
* A Finnish rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingFinnish;

/**
*  A KMRB (Korea Media Rating Board) rating type value.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingKMRB;

/**
* A DVD Parental rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingDVDParental;

/**
* A EIRIN (Japan) rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingEIRIN;

/**
*  A INCAA (Argentina) rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingINCAA;

/**
*  A DJTCQ (Dept of Justice, Rating, Titles and Qualification) (Brazil) rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingDJTCQ;

/**
*  A Quebecois rating.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingQuebec;

/**
*  A French rating.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingFrance;

/**
*  A FSK (German) rating.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingFSK;

/**
*  An Italian rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingItaly;

/**
*  A Spanish rating
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) ratingSpain;


@end



#endif /* _GnRating_h_ */

