/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLink_h_
#define _GnLink_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnDataObject.h"
#import "GnEnums.h"
#import "GnLinkContent.h"
#import "GnLinkOptions.h"
#import "GnListElement.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"




/**
* GnLink
*/ 

@interface GnLink : NSObject

/**
* GnLink
*/
-(INSTANCE_RETURN_TYPE) initWithGnDataObject: (GnDataObject*)gnDataObject user: (GnUser*)user statusEventsDelegate: (id <GnStatusEventsDelegate>)pEventHandler;

/**
* GnLink
*/
-(INSTANCE_RETURN_TYPE) initWithGnListElement: (GnListElement*)listElement user: (GnUser*)user statusEventsDelegate: (id <GnStatusEventsDelegate>)pEventHandler;

/**
* Retrieves the Link library version string.
* This API can be called at any time, after getting GnManager instance successfully. The returned
* string is a constant. Do not attempt to modify or delete.
*
* Example: <code>1.2.3.123</code> (Major.Minor.Improvement.Build)<br>
* Major: New functionality<br>
* Minor: New or changed features<br>
* Improvement: Improvements and fixes<br>
* Build: Internal build number<br>
*/ 

+(NSString*) version;

/**
*  Retrieves Link library build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, after getting GnManager instance successfully. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(NSString*) buildDate;

/**
* Retrieves count for the specified content
* @param contentType Type of content to count
* @return Count
* <p><b>Remarks:</b></p>
* <code>Count()</code> can be called repeatedly on the same GnLink object with
* different content type requests to
* retrieve the count for differing values of content type.
*/ 

-(NSUInteger) count: (GnLinkContentType)contentType error: (NSError**)error;

/**
* Options
*/
-(GnLinkOptions*) options;

/**
* Retrieves CoverArt data.
* @param imageSize size of the image to retrieve
* @param imagePreference image retrieval preference
* @param item_ord Nth CoverArt
* @return GnLinkContent
*  <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different size and ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) coverArt: (GnImageSize)imageSize imagePreference: (GnImagePreference)imagePreference item_ord: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves GenreArt data.
* @param imageSize size of the image to retrieve
* @param imagePreference image retrieval preference
* @param item_ord Nth GenreArt
* @return GnLinkContent
*  <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different size and ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) genreArt: (GnImageSize)imageSize imagePreference: (GnImagePreference)imagePreference item_ord: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves Image data.
* @param imageSize size of the image to retrieve
* @param imagePreference image retrieval preference
* @param item_ord  Nth Image
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different size and ordinal parameters
* @ingroup Link_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) image: (GnImageSize)imageSize imagePreference: (GnImagePreference)imagePreference item_ord: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves ArtistImage data.
* @param  imageSize size of the image to retrieve
* @param imagePreference image retrieval preference
* @param item_ord Nth ArtistImage
* @return  GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different size and ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) artistImage: (GnImageSize)imageSize imagePreference: (GnImagePreference)imagePreference item_ord: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves Review data.
* @param item_ord Nth Review
* @return  GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) review: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves Biography data.
* @param item_ord [in] Nth Biography
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) biography: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves AristNews data.
* @param item_ord Nth AristNews
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) artistNews: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves LyricXML data.
* @param item_ord Nth LyricXML
* @return  GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) lyricXML: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves LyricText data.
* @param item_ord Nth LyricText
* @return  GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) lyricText: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves CommentsListener data.
* @param item_ord [in] Nth CommentsListener
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) commentsListener: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves CommentsRelease data.
* @param item_ord [in] Nth CommentsRelease
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) commentsRelease: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves News data.
* @param item_ord Nth News
* @return GnLinkContent
* <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) news: (NSUInteger)item_ord error: (NSError**)error;

/**
* Retrieves DspData data.
* @param item_ord Nth DspData
* @return GnLinkContent
*  <p><b>Remarks:</b></p>
* This API can be called repeatedly on the same link query handle with
* different ordinal parameters
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(GnLinkContent*) dspData: (NSUInteger)item_ord error: (NSError**)error;

/**
* SetCancel
*/
-(void) setCancel: (BOOL)bCancel;

/**
* IsCancelled
*/
-(BOOL) isCancelled;


@end



#endif /* _GnLink_h_ */

