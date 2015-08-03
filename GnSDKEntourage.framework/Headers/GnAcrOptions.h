/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAcrOptions_h_
#define _GnAcrOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
*  Defines a class for configuring ACR options.
*/ 

@interface GnAcrOptions : NSObject

/**
*	Return the ACR audio algorithm to be used when initializing the audio configuration for GnAcrAudio or GnAcrAudioFingerprinter.
*  By default, the audio algorithm is set to GnAcrAudioAlgorithm.kAcrAudioAlgorithmLowQuality.
* @return the audio algorithm
* @ingroup Acr_Options
*/ 

-(GnAcrAudioAlgorithm) audioAlgorithm;

/**
* Set the ACR audio algorithm to be used when initializing the audio configuration for GnAcrAudio or GnAcrAudioFingerprinter.
* By default, the audio algorithm is set to GnAcrAudioAlgorithm.kAcrAudioAlgorithmLowQuality.
* @param algorithm [in] the audio algorithm to be used when initializing the audio configuration
* @ingroup Acr_Options
*/ 

-(void) audioAlgorithmWithAlgorithm: (GnAcrAudioAlgorithm)algorithm;

/**
*	Return the ACR audio optimization mode - accuracy, speed, or adaptive.
* @return the optimization mode
* @ingroup Acr_Options
*/ 

-(GnAcrOptimizationType) optimizationType:(NSError**) error;

/**
*  Set the optimization mode - accuracy, speed, or adaptive.
* <p><b>Note:</b></p>
*   Default value is GnAcrOptimizationType.kAcrOptimizationTypeAccuracy. Optimizing for speed can result in
*   slightly faster, but less accurate, responses.
*   Contact Gracenote Support Services before using adaptive mode.
* @param optimization [in] the optimization mode
* @ingroup Acr_Options
*/ 

-(void) optimizationTypeWithOptimization: (GnAcrOptimizationType)optimization error: (NSError**)error;

/**
* Return the maximum number of seconds allowed before a recognition should be performed.
* @return the maximum number of seconds allowed before a recognition should be performed
* @ingroup Acr_Options
*/ 

-(NSUInteger) lookupOnlineMaxDelay:(NSError**) error;

/**
*  Set the maximum number of seconds allowed before an online video lookup should be performed.
*  The lowest setting to trigger queries is 1 second. Setting the interval to 0 means no forced queries from
*  this timer (off). A low value (approximately 10 seconds or less) could mean that continuous querying will take place.
*  This parameter exists in case transitions are not detected. For example, room background noise could mask the channel changes.
*  In this case a recognition is not performed. If, however, this parameter is set to 180 seconds, for example, then after 180
*  seconds a query takes place. Any match resets this timer.
*  Tradeoffs: A lower value forces more network traffic and CPU usage to generate a fingerprint when everything is working correctly
*  and there are really no transitions to detect (the user is staying on the same channel). It is battery intensive
*  to keep doing unnecessary online queries. A higher value means it will take a long time to force a query and get the next
*  match if transitions are not being detected.
*  Default: '300' (seconds).  Range: 0-86400 (1 day)
*	@param delay [in] The maximum number of seconds between online lookups
* @ingroup Acr_Options
*/ 

-(void) lookupOnlineMaxDelayWithDelay: (NSUInteger)delay error: (NSError**)error;

/**
*  Return the maximum number of seconds allowed before a recognition should be performed using the local cache.
* @return the maximum number of seconds allowed before a recognition should be performed using the local cache.
* @ingroup Acr_Options
*/ 

-(NSUInteger) lookupLocalMaxDelay:(NSError**) error;

/**
*	Set the maximum number of seconds allowed before a local lookup should be performed. The lowest setting to
*  trigger queries is 1 second. Setting the interval to 0 (default) means no forced queries from this timer (off). A low
*  value (approximately 7 seconds or less) could mean that continuous querying will take place.
*  This parameter exists to allow local lookups to be executed more frequently independent from the online lookup max delay.
*  This is because lookups from the local cache are faster and less battery-consuming than online lookups.
*  If a local query does not return a match, please note that no followup online query is made.
*  Default: '0' (off).  Range: 0-86400 (1 day)
*	@param delay [in] The maximum number of seconds between local lookups
* @ingroup Acr_Options
*/ 

-(void) lookupLocalMaxDelayWithDelay: (NSUInteger)delay error: (NSError**)error;

/**
* Check whether only local queries should be performed.
* @return true if only local queries are performed. Returns false if both local and online queries are performed.
* @ingroup Acr_Options
*/ 

-(BOOL) lookupCacheOnly:(NSError**) error;

/**
* Set whether only local queries should be performed.
* @param enable [in] If set to true, enable local-only queries. If set to false, enable both local and online queries.
* @ingroup Acr_Options
*/ 

-(void) lookupCacheOnlyWithEnable: (BOOL)enable error: (NSError**)error;

/**
             Check whether video queries will include TV grid lookups
             @return true if video queries include a tv grid lookup. Returns false if TV grid lookups are included
             @ingroup Acr_Options
*/ 

-(BOOL) includeTVGridLookup:(NSError**) error;

/**
             Set whether video queries will include TV grid lookups.
             Default is 'true'
             @param enable If set to true, video queries will perform a server-side lookup to retrieve full channel, airing and program metadata for a video response.  If set to false, no lookup is performed and video query matches will only contain a channel identifier and timestamp information.
             
             @ingroup Acr_Options
*/ 

-(void) includeTVGridLookupWithEnable: (BOOL)enable error: (NSError**)error;

/**
*	Return the number of consecutive 'no matches' that must occur before ACR enters no match mode
*  @return the number of consecutive 'no matches' that must occur before ACR enters no match mode
*  @ingroup Acr_Options
*/ 

-(NSUInteger) noMatchCountThreshold:(NSError**) error;

/**
*	Set the no match count threshold.
*  Default is 60. This means that after 60 consecutive 'no matches' the SDK will go into
*  no match mode, which delays the time between queries. If your app is getting a large number
*  of no matches then it is either capturing silence or audio that cannot be identified.
*	@param threshold [in] the maximum number of consecutive 'no matches' that must occur before ACR enters no match mode
* @ingroup Acr_Options
*/ 

-(void) noMatchCountThresholdWithThreshold: (NSUInteger)threshold error: (NSError**)error;

/**
*	Return the number of seconds to increment the no match time.
* @return the number of seconds to increment the no match time
* @ingroup Acr_Options
*/ 

-(NSUInteger) noMatchTimeIncrement:(NSError**) error;

/**
*	Set the no match time increment value in seconds.
*  Default is '60' seconds. This means that 60 seconds will be added to the time between
*  lookups every time the no match count threshold is reached.
*  Valid range is 8 to 2592000 seconds (30 days).
*	@param seconds [in] The time increment value in seconds
* @ingroup Acr_Options
*/ 

-(void) noMatchTimeIncrementWithSeconds: (NSUInteger)seconds error: (NSError**)error;

/**
*	Return the maximum time for no match mode.
*  Valid range is 60 to 5184000 seconds (60 days)
* @return the maximum time for no match mode in seconds
* @ingroup Acr_Options
*/ 

-(NSUInteger) noMatchMaxTime:(NSError**) error;

/**
*	Set the maximum time for no match mode.
*  Default is '300' seconds (5 minutes). This means that the
*  GnAcrOptions.NoMatchTimeIncrement value will NOT be applied to the delay between queries after 300 seconds.
*  Valid range is 60 to 5184000 seconds (60 days)
*	@param seconds [in] The maximum number of seconds for no match mode
* @ingroup Acr_Options
*/ 

-(void) noMatchMaxTimeWithSeconds: (NSUInteger)seconds error: (NSError**)error;

/**
*	Check whether third-party IDs are included in the lookup results.
* @return true if third-party IDs are included in the lookup results.
* @ingroup Acr_Options
*/ 

-(BOOL) externalId:(NSError**) error;

/**
*	Set whether third-party IDs should be included in lookup results.
*  The default value if unset is false.
*	@param enable [in] If set to true, include third-party IDs in lookup results. If set to false, do not include third-party IDs in lookup results.
* @ingroup Acr_Options
*/ 

-(void) externalIdWithEnable: (BOOL)enable error: (NSError**)error;

/**
*	Check whether content (like images) will be fetched with the lookup results.
* @return true if content will be fetched with the lookup results.
* @ingroup Acr_Options
*/ 

-(BOOL) contentData:(NSError**) error;

/**
*	Set whether content (like images) will be fetched with the lookup results.
*  The default value if unset is false.
*	@param enable [in] If set to true, fetch content with the lookup results. If set to false, do not fetch content with the lookup results.
* @ingroup Acr_Options
*/ 

-(void) contentDataWithEnable: (BOOL)enable error: (NSError**)error;

/**
* Check if manual only mode is enabled. When enabled, ACR will only query on-demand and not
* automatically. If not enabled, ACR will query both automatically and on-demand.
* @return true if enabled.
* @ingroup Acr_Options
*/ 

-(BOOL) manualOnlyMode:(NSError**) error;

/**
* Set the manual-only mode option. When enabled, ACR will only query on-demand and not
* automatically. If not enabled, ACR will query both on-demand and automatically.
* @param enable [in] If set to true, query only on-demand. If set to false, query both on-demand and automatically.
* @ingroup Acr_Options
*/ 

-(void) manualOnlyModeWithEnable: (BOOL)enable error: (NSError**)error;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
* @param intfName [in] Local IP address or system name for the desired network interface
* @ingroup Acr_Options
*/ 

-(void) networkInterfaceWithIntfName: (NSString*)intfName error: (NSError**)error;

/**
* Return the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set this option will return an empty string.
* @return the network interface name (e.g. local IP address or system name). Can be an empty string
* @ingroup Acr_Options
*/ 

-(NSString*) networkInterface:(NSError**) error;

/**
* Set a custom option
* @param optionKey [in] Option name
* @param value	[in] Option value
* @ingroup Acr_Options
*/ 

-(void) customWithOptionKey: (NSString*)optionKey value: (NSString*)value error: (NSError**)error;

/**
* Return the value for a custom option
* @param key [in] Option name
* @return Option value. Can be an empty string
* @ingroup Acr_Options
*/ 

-(NSString*) customWithKey: (NSString*)key error: (NSError**)error;


@end



#endif /* _GnAcrOptions_h_ */

