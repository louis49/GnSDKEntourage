/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTVChannel_h_
#define _GnTVChannel_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContent.h"
#import "GnDataObject.h"
#import "GnExternalId.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;


/**
* \class GnTVChannel
*/ 

@interface GnTVChannel : GnDataObject

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnTVChannel
*/
-(INSTANCE_RETURN_TYPE) initWithTui: (NSString*)tui tuiTag: (NSString*)tuiTag;

/**
*	Gracenote identifier
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnId;

/**
*	Gracenote unique identifier
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) gnUId;

/**
*	Product ID
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) productId;

/**
*	TUI - title-unique identifier
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tui;

/**
*	Tui tag
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) tuiTag;

/**
*	Rank - credit's rank in imporatance
*	@ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(NSString*) rank;

/**
*	The channel number assigned by the TV provider (e.g. DirectTV or Comcast).
*  This is only available if this GnTvChannel was found using a search query in which a GnTvProvider was known.
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) channelNumber;

/**
*	Channel name, e.g., :Lifetime HD"
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) channelName;

/**
*	Channel callsign, e.g., KQED
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) channelCallsign;

/**
*	Identifier - index into an array of channel identifiers that was passed in an EPG query.
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) identifier;

/**
*	ONID(Original Network IDentifier). For European Digital Broadcast Networks (DVB),
*  an ONID is a unique identifier for the original network that is transmitting the signal.
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) onId;

/**
*	TSID (Transport Stream IDentifier). For European Digital Broadcast Networks, a TSID is a
*  16-bit unsigned integer in an MPEG-2 transport stream that identifies the network origination source or transmiter, (or both)
*  that provides a particular transport stream or transport streams. The MPEG-2 standard leaves the issuance of actual TSIDs
*  to individual MPEG-2 "users". One such user is the Advanced Television Systems Committee (ATSC), another is Digital
*  Video Broadcasting (DVB) and the Society of Cable and Telecommunications Engineers (SCTE) among others
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) tSID;

/**
*	SID (Service IDentifier) For European Digital Broadcast Networks (DVB), a SID is specific to every TV channel,
*  it is the unique identifier for a video/audio program within the transponder signal
*	@ingroup GDO_ValueKeys_ACR
*/ 

-(NSString*) sID;

/**
* Iterator for external IDs - 3rd party IDs used to cross link this metadata to 3rd party services, e.g. Amazon
* @ingroup GDO_ChildKeys_ExternalId
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* Iterator for the content (cover art, biography, etc.)  associated with this video work.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* GnType
*/
+(NSString*) gnType;

/**
* From
*/
+(GnTVChannel*) from: (GnDataObject*)obj error: (NSError**)error;


@end


@interface GnTVChannelEnumerator : NSEnumerator

typedef void (^GnTVChannelBlock)(id obj, NSUInteger index, BOOL *stop);

-(void)enumerateObjectsUsingBlock: (GnTVChannelBlock)handler;

-(NSUInteger) count;

-(GnTVChannel*) nextObject;

-(GnTVChannel*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


@end



#endif /* _GnTVChannel_h_ */

