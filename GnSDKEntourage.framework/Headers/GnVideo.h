/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnVideo_h_
#define _GnVideo_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnLocale.h"
#import "GnResponseContributors.h"
#import "GnResponseVideoObjects.h"
#import "GnResponseVideoProduct.h"
#import "GnResponseVideoSeasons.h"
#import "GnResponseVideoSeries.h"
#import "GnResponseVideoSuggestions.h"
#import "GnResponseVideoWork.h"
#import "GnEnums.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"
#import "GnVideoOptions.h"
#import "GnVideoProduct.h"
#import "GnVideoSeason.h"
#import "GnVideoSeries.h"
#import "GnVideoWork.h"




/**
* GnVideo
*/ 

@interface GnVideo : NSObject

/**
*  Initializes Gracenote's VideoID and Video Explore libraries.
*  @param user
*  @param pEventHandler
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user statusEventsDelegate: (id <GnStatusEventsDelegate>)pEventHandler;

/**
* Initializes Gracenote's VideoID and Video Explore libraries.
* @param user
* @param locale
* @param pEventHandler
*/ 

-(INSTANCE_RETURN_TYPE) initWithGnUser: (GnUser*)user locale: (GnLocale*)locale statusEventsDelegate: (id <GnStatusEventsDelegate>)pEventHandler;

/**
*  Retrieves the VideoID and Video Explore library's version string.
*
*  This API can be called at any time, even before initialization and after shutdown. The returned
*  string is a constant. Do not attempt to modify or delete.
*
*  Example: <code>1.2.3.123</code> (Major.Minor.Improvement.Build)<br>
*  Major: New functionality<br>
*  Minor: New or changed features<br>
*  Improvement: Improvements and fixes<br>
*  Build: Internal build number<br>
*/ 

+(NSString*) version;

/**
*  Retrieves the VideoID and Video Explore library's build date as a string.
*  This API can be called at any time, even before initialization and after shutdown. The returned
*  string is a constant. Do not attempt to modify or delete.
*  @return String with format: YYYY-MM-DD hh:mm UTC
*
*  Example:<code>"2008-02-12 00:41 UTC"</code>
*/ 

+(NSString*) buildDate;

/**
*  Options
*/ 

-(GnVideoOptions*) options;

/**
*  Find video products using a TOC (Table of Contents) string.
*  @param videoTOC [in] TOC string; must be an XML string constructed by the Gracenote Video Thin Client component.
*  @param TOCFlag [in] TOC string flag; for flags types, see GnVideoTOCFlag
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*  Use this API to find a video product by its TOC.
*/ 

-(GnResponseVideoProduct*) findProductsWithVideoTOC: (NSString*)videoTOC TOCFlag: (GnVideoTOCFlag)TOCFlag error: (NSError**)error;

/**
*  Find video products using a partial GnVideoProduct object.
*  @param videoProduct
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A partial GnVideoProduct object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

-(GnResponseVideoProduct*) findProductsWithVideoProduct: (GnVideoProduct*)videoProduct error: (NSError**)error;

/**
*  Find video products using a partial GnVideoWork object.
*  @param videoWork
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A partial GnVideoWork object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

-(GnResponseVideoProduct*) findProductsWithVideoWork: (GnVideoWork*)videoWork error: (NSError**)error;

/**
*  Find video products using supported GnDataObject types.
*  @param gnObj
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

-(GnResponseVideoProduct*) findProductsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  Find video products using a text search
*  @param textInput [in] Text string.
*  @param searchField [in] Can be GnVideoSearchField.kSearchFieldProductTitle or GnVideoSearchField.kSearchFieldAll
*  @param searchType [in] Video search type; see GnVideoSearchType
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

-(GnResponseVideoProduct*) findProductsWithTextInput: (NSString*)textInput searchField: (GnVideoSearchField)searchField searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
*  Find video products using an external ID
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*  @return GnResponseVideoProduct
*
*  <p><b>Remarks:</b></p>
*  A Product refers to the commercial release of a Film, TV Series, or video content. Products contain a unique commercial
*  code such as a UPC, Hinban, or EAN. Products are for the most part released on a physical format, such as a DVD or Blu-ray.
*/ 

-(GnResponseVideoProduct*) findProductsWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Find video works using a partial GnVideoProduct object.
*  @param videoProduct [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  A partial GnVideoProduct can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithVideoProduct: (GnVideoProduct*)videoProduct error: (NSError**)error;

/**
*  Find video works using a partial GnVideoWork object.
*  @param videoWork [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  A partial GnVideoWork object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithVideoWork: (GnVideoWork*)videoWork error: (NSError**)error;

/**
*  Find video works using a partial GnContributor object.
*  @param contributor [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  A partial GnContributor object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithContributor: (GnContributor*)contributor error: (NSError**)error;

/**
*  Find video works using a partial GnVideoSeason object.
*  @param videoSeason [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*  A partial GnVideoSeason object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithVideoSeason: (GnVideoSeason*)videoSeason error: (NSError**)error;

/**
*  Find video works using a  partial GnVideoSeries object.
*  @param videoSeries [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*  A partial GnVideoSeries object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithVideoSeries: (GnVideoSeries*)videoSeries error: (NSError**)error;

/**
*  Find video works using supported GnDataObject types.
*  @param gnObj [in]
*  @return GnResponseVideoWork
*
*  <p><b>Remarks:</b></p>
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  Find video works using a text search.
*  @param textInput [in] text string.
*  @param searchField [in] Can be any GnVideoSearchField option except GnVideoSearchField.kSearchFieldProductTitle
*  @param searchType [in] Video search type, see GnVideoSearchType
*
*  @return GnResponseVideoWork
*  <p><b>Remarks:</b></p>
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithTextInput: (NSString*)textInput searchField: (GnVideoSearchField)searchField searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*
*  @return GnResponseVideoWork
*  <p><b>Remarks:</b></p>
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
*  body of work, or, more specifically, to indicate a particular movie or television show.
*/ 

-(GnResponseVideoWork*) findWorksWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Find video seasons using a partial GnVideoWork object.
*  @param videoWork [in]
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*  A partial GnVideoWork object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithVideoWork: (GnVideoWork*)videoWork error: (NSError**)error;

/**
*  Find video seasons using a partial GnContributor object.
*  @param contributor [in]
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*  A partial GnContributor object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithContributor: (GnContributor*)contributor error: (NSError**)error;

/**
*  Find video seasons using a partial GnVideoSeason object.
*  @param videoSeason [in]
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*  A partial GnVideoSeason object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithVideoSeason: (GnVideoSeason*)videoSeason error: (NSError**)error;

/**
*  Find video seasons using a partial GnVideoSeries object.
*  @param videoSeries [in]
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*  A partial GnVideoSeries object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithVideoSeries: (GnVideoSeries*)videoSeries error: (NSError**)error;

/**
*  Find video seasons using supported GnDataObject types.
*  @param gnObj [in]
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  Find video seasons using an external ID.
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*  @return GnResponseVideoSeasons
*
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works, typically representing a season of a TV series. For example: CSI: Miami (Season One), CSI: Miami
*  (Season Two), CSI: Miami (Season Three).
*/ 

-(GnResponseVideoSeasons*) findSeasonsWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Find video series using a partial GnVideoWork object.
*  @param videoWork [in]
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*  A partial GnVideoWork object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeries*) findSeriesWithVideoWork: (GnVideoWork*)videoWork error: (NSError**)error;

/**
*  Find video series using a contributor Tui and TuiTag or partial GnContributor object.
*  @param contributor [in]
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*  A partial GnContributor object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeries*) findSeriesWithContributor: (GnContributor*)contributor error: (NSError**)error;

/**
*  Find video series using a video season Tui and TuiTag or partial GnVideoSeason.
*  @param videoSeason [in]
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*  A partial GnVideoSeason object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeries*) findSeriesWithVideoSeason: (GnVideoSeason*)videoSeason error: (NSError**)error;

/**
*  Find video series using a partial GnVideoSeries object.
*  @param videoSeries [in]
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*  A partial GnVideoSeries object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseVideoSeries*) findSeriesWithVideoSeries: (GnVideoSeries*)videoSeries error: (NSError**)error;

/**
*  Find video series using supported GnDataObject types.
*  @param gnObj [in]
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*/ 

-(GnResponseVideoSeries*) findSeriesWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  Find video series using a text search.
*  @param textInput [in]  Video series title
*  @param searchType [in] Can only be GnVideoSearchType.kSearchFieldSeriesTitle - you cannot search for a Series
*  using GnVideoSearchType.kSearchFieldAll
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigation.
*/ 

-(GnResponseVideoSeries*) findSeriesWithTextInput: (NSString*)textInput searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
*  Find video series using an external ID.
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*  @return GnResponseVideoSeries
*
*   <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and often comprised of Seasons (generally for TV series),
*  for example: CSI: Miami, CSI: Vegas, CSI: Crime Scene Investigati
*/ 

-(GnResponseVideoSeries*) findSeriesWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Find contributors associated with a partial GnVideoWork object.
*  @param videoWork [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person involved in the creation of a work (such as an actor or a director) or
*  an entity (such as a production company).
*  A partial GnVideoWork object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseContributors*) findContributorsWithVideoWork: (GnVideoWork*)videoWork error: (NSError**)error;

/**
*  Find contributors using a partial GnContributor objet.
*  @param contributor [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*  A partial GnContributor object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseContributors*) findContributorsWithContributor: (GnContributor*)contributor error: (NSError**)error;

/**
*  Find contributors associated with a video season using a partial GnVideoSeason.
*  @param videoSeason [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*  A partial GnVideoSeason object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseContributors*) findContributorsWithVideoSeason: (GnVideoSeason*)videoSeason error: (NSError**)error;

/**
*  Find contributors associated with a partial GnVideoSeries object.
*  @param videoSeries [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*  A partial GnVideoSeason object can be constructed in a number of different ways, typically with a Tui or Tui Tag, or one that has been deserialized.
*  Tui is a Gracenote acronym for "title unique identifier". For example: "267348592". This and tuiTag are used for unique identification within the Gracenote service.
*/ 

-(GnResponseContributors*) findContributorsWithVideoSeries: (GnVideoSeries*)videoSeries error: (NSError**)error;

/**
*  Find contributors using supported GnDataObject types.
*  @param gnObj [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*/ 

-(GnResponseContributors*) findContributorsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  @deprecated This method has been deprecated.
*  Find contributors using a text search.
*  @param textInput [in]
*  @param searchType [in]
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*/ 

-(GnResponseContributors*) findContributorsWithTextInput: (NSString*)textInput searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
*  Find contributors using a text search.
*  @param searchText [in]
*  @param searchField [in] Can be GnVideoSearchField.kSearchFieldContributorName or GnVideoSearchField.kSearchFieldAll
*  @param searchType [in] Video search type, see GnVideoSearchType
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*/ 

-(GnResponseContributors*) findContributorsWithSearchText: (NSString*)searchText searchField: (GnVideoSearchField)searchField searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
*  Find contributors using an external ID.
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*  @return GnResponseContributors
*
*  <p><b>Remarks:</b></p>
*  A contributor is a person or entity involved in creating a work (e.g., actor, director, production company)
*/ 

-(GnResponseContributors*) findContributorsWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Performs a Video Explore query for any type of video object. Use this function to retrieve a specific
*  Video Explore object referenced by a GnDataObject.
*  @param gnObj [in]
*  @return GnResponseVideoObjects
*
*/ 

-(GnResponseVideoObjects*) findObjectsWithGnObj: (GnDataObject*)gnObj error: (NSError**)error;

/**
*  Performs a Video Explore query for any type of video object. Use this function to retrieve
*  all the Video Explore objects (Contributors, Products, Seasons, Series, and Works) associated with a
*  particular external ID.
*  @param externalId [in] External ID. External IDs are 3rd-party IDs used to cross link Gracenote metadata to 3rd-party services.
*  @param externalIdType [in] External ID type; see GnVideoExternalIdType for available external ID types
*  @return GnResponseVideoObjects
*/ 

-(GnResponseVideoObjects*) findObjectsWithExternalId: (NSString*)externalId externalIdType: (GnVideoExternalIdType)externalIdType error: (NSError**)error;

/**
*  Performs a VideoID or Video Explore query for search suggestion text. Use this function to suggest potential matching titles,
*  names, and series as a user enters text in a search query. A suggestion search cannot be performed using GnVideoSearchField.kSearchFieldAll.
*  @param searchText [in] Text string.
*  @param searchField [in] Can be any GnVideoSearchField option except GnVideoSearchType.kSearchFieldAll
*  @param searchType [in] Video search type, see GnVideoSearchType
*  @return GnResponseVideoSuggestions
*/ 

-(GnResponseVideoSuggestions*) findSuggestions: (NSString*)searchText searchField: (GnVideoSearchField)searchField searchType: (GnVideoSearchType)searchType error: (NSError**)error;

/**
* SetCancel
*/
-(void) setCancel: (BOOL)bCancel;

/**
* IsCancelled
*/
-(BOOL) isCancelled;


@end



#endif /* _GnVideo_h_ */

