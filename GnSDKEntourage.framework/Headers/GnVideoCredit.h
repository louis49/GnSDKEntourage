/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideoCredit_h_
#define _GnVideoCredit_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContributor.h"
#import "GnEnums.h"
#import "GnDataObject.h"
#import "GnName.h"
#import "GnVideoSeason.h"
#import "GnVideoSeries.h"
#import "GnVideoWork.h"


@class GnVideoSeasonEnumerator;
@class GnVideoSeriesEnumerator;
@class GnVideoWorkEnumerator;


/**
* \class GnVideoCredit
*/ 

@interface GnVideoCredit : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Role, e.g., Actor.
* <p><b>Note:</b></p>
*  For music credits, the absence of a role for a person indicates that person is the primary
*   artist, who may have performed multiple roles.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
* @ingroup GDO_ValueKeys_Role
*/ 

-(NSString*) role;

/**
* Role ID
* @ingroup GDO_ValueKeys_Role
*/ 

-(NSUInteger) roleId;

/**
*  A number identifying the role's listing in the credits.
* @ingroup GDO_ValueKeys_Role
*/ 

-(NSString*) roleBilling;

/**
*  The character's name on the show.
* @ingroup GDO_ValueKeys_Video
*/ 

-(NSString*) characterName;

/**
*  Role's rank in importance.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSUInteger) rank;

/**
*  Genre, e.g., comedy. This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
* @param level :enum value specifying level value
* @return gnsdk_cstr_t
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) genre: (GnDataLevel)level;

/**
*  Artist type. This is a list/locale dependent, multi-level field
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
* @param level        :enum value specifying level value
* @return gnsdk_cstr_t
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) artistType: (GnDataLevel)level;

/**
*  Geographic location, e.g., "New York City". This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
* @param level		[in] enum value specifying level value
* @return gnsdk_cstr_t
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) origin: (GnDataLevel)level;

/**
* Artist era. This is a list/locale dependent, multi-level field.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that a list or locale be loaded into memory.
*
*  To render locale-dependent information for list-based values, your application must allocate a
*  <code>GnLocale</code> object. A <code>LocaleNotLoaded</code> message is returned when locale information
*  is not set prior to a request for a list-based value.
*
* @param level		[in] enum value specifying level value
* @return gnsdk_cstr_t
* @ingroup GDO_ValueKeys_Misc
*/ 

-(NSString*) era: (GnDataLevel)level;

/**
*  Official name object .
* @ingroup GDO_ChildKeys_Name
*/ 

-(GnName*) officialName;

/**
* Contributor object.
* @ingroup GDO_ChildKeys_Contributor
*/ 

-(GnContributor*) contributor;

/**
* Iterable object that allows access to the collection of video work children.
* @ingroup GDO_ChildKeys_Video_Work
*/ 

-(GnVideoWorkEnumerator*) works;

/**
* Series
*/
-(GnVideoSeriesEnumerator*) series;

/**
* Seasons
*/
-(GnVideoSeasonEnumerator*) seasons;


@end


@interface GnVideoCreditEnumerator : NSEnumerator

typedef void (^GnVideoCreditBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnVideoCreditBlock)handler;

-(NSUInteger) count;

-(GnVideoCredit*) nextObject;

-(GnVideoCredit*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnVideoCredit_h_ */

