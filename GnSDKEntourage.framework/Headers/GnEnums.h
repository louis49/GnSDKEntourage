/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2015. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GNENUMS_H_
#define _GNENUMS_H_




/***************************************
* GnLookupMode
*/
typedef NS_ENUM(NSInteger,GnLookupMode)
{
    /**
    * Invalid lookup mode
    */
    kLookupModeInvalid = 0,
    
    /**
    * This mode forces the lookup to be done against the local database only. Local caches created from (online) query
    * results are not queried in this mode.
    * If no local database exists, the query will fail.
    */
    kLookupModeLocal,
    
    /**
    * This is the default lookup mode. If a cache exists, the query checks it first for a match.
    * If a no match is found in the cache, then an online query is performed against Gracenote Service.
    * If a result is found there, it is stored in the local cache.  If no online provider exists, the query will fail.
    * The length of time before cache lookup query expires can be set via the user object.
    */
    kLookupModeOnline,
    
    /**
    * This mode forces the query to be done online only and will not perform a local cache lookup first.
    * If no online provider exists, the query will fail. In this mode online queries and lists are not
    * written to local storage, even if a storage provider has been initialize.
    */
    kLookupModeOnlineNoCache,
    
    /**
    * This mode forces the query to be done online only and will not perform a local cache lookup first.
    * If no online provider exists, the query will fail. If a storage provider has been initialized,
    * queries and lists are immediately written to local storage, but are never read unless the lookup mode is changed.
    */
    kLookupModeOnlineNoCacheRead,
    
    /**
    * This mode forces the query to be done against the online cache only and will not perform a network lookup.
    * If no online provider exists, the query will fail.
    */
    kLookupModeOnlineCacheOnly
    
} ;


/***************************************
* GnLookupData
*/
typedef NS_ENUM(NSInteger,GnLookupData)
{
    /**
    * Invalid lookup data
    */
    kLookupDataInvalid = 0,
    
    /**
    * Indicates whether a response should include data for use in fetching content (like images).
    * <p><b>Remarks:</b></p>
    * An application's client ID must be entitled to retrieve this specialized data. Contact your
    *	Gracenote Global Services and Support representative with any questions about this enhanced
    *	functionality.
    */
    kLookupDataContent,
    
    /**
    * Indicates whether a response should include any associated classical music data.
    * <p><b>Remarks:</b></p>
    * An application's license must be entitled to retrieve this specialized data. Contact your
    * Gracenote Global Services and Support representative with any questions about this enhanced functionality.
    */
    kLookupDataClassical,
    
    /**
    * Indicates whether a response should include any associated sonic attribute data.
    * <p><b>Remarks:</b></p>
    * An application's license must be entitled to retrieve this specialized data. Contact your
    * Gracenote Global Services and Support representative with any questions about this enhanced functionality.
    */
    kLookupDataSonicData,
    
    /**
    * Indicates whether a response should include associated attribute data for GNSDK Playlist.
    * <p><b>Remarks:</b></p>
    * An application's license must be entitled to retrieve this specialized data. Contact your
    * Gracenote Global Services and Support representative with any questions about this enhanced functionality.
    */
    kLookupDataPlaylist,
    
    /**
    * Indicates whether a response should include external IDs (third-party IDs).
    * <p><b>Remarks:</b></p>
    * External IDs are third-party IDs associated with the results (such as an Amazon ID),
    *	configured specifically for your application.
    * An application's client ID must be entitled to retrieve this specialized data. Contact your
    * Gracenote Global Services and Support representative with any questions about this enhanced functionality.
    * External IDs can be retrieved from applicable query response objects.
    */
    kLookupDataExternalIds,
    
    /**
    * Indicates whether a response should include global IDs.
    */
    kLookupDataGlobalIds,
    
    /**
    * Indicates whether a response should include additional credits.
    */
    kLookupDataAdditionalCredits,
    
    /**
    * Indicates whether a response should include sortable data for names and titles
    */
    kLookupDataSortable
    
} ;


/***************************************
* GnThreadPriority
*/
typedef NS_ENUM(NSInteger,GnThreadPriority)
{
    kThreadPriorityInvalid = 0,
    
    /**
    * Use of default thread priority.
    */
    kThreadPriorityDefault,
    
    /**
    * Use idle thread priority.
    */
    kThreadPriorityIdle,
    
    /**
    * Use low thread priority (default).
    */
    kThreadPriorityLow,
    
    /**
    * Use normal thread priority.
    */
    kThreadPriorityNormal,
    
    /**
    * Use high thread priority.
    */
    kThreadPriorityHigh
    
} ;


/***************************************
* GnFingerprintType
*/
typedef NS_ENUM(NSInteger,GnFingerprintType)
{
    /**
    * Invalid fingerprint type
    */
    kFingerprintTypeInvalid = 0,
    
    /**
    * Specifies a fingerprint data type for generating fingerprints used with MusicID-File.
    * <p><b>Remarks:</b></p>
    * A MusicID-File fingerprint is a fingerprint of the beginning 16 seconds of the file.
    * <p><b>Note:</b></p>
    * Do not design your application to submit only 16 seconds of a file; the
    * application must submit data until GNSDK indicates it has received enough input.
    * Use this fingerprint type when identifying audio from a file source (MusicID-File).
    */
    kFingerprintTypeFile,
    
    /**
    *  Specifies a fingerprint used for identifying an ~3-second excerpt from an audio stream.
    *  Use this fingerprint type when identifying a continuous stream of audio data and when retrieving
    *  Track Match Position values. The fingerprint represents a
    *  specific point in time of the audio stream as denoted by the audio provided when the fingerprint
    *  is generated.
    *  <p><b>Note:</b></p>
    *  Do not design your application to submit only 3 seconds of audio data; the
    *  application must submit audio data until GNSDK indicates it has received enough input.
    *  You must use this fingerprint or its 6-second counterpart when generating results where match
    *  position is required.
    *  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries
    *  of this type will not succeed.
    */
    kFingerprintTypeStream3,
    
    /**
    *  Specifies a fingerprint used for identifying an ~6-second excerpt from and audio stream.
    *  This is the same as kFingerprintTypeStream3 but requires more audio data to generate
    *  but could be more accurate.
    *  For additional notes see kFingerprintTypeStream3.
    */
    kFingerprintTypeStream6,
    
    /**
    * @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
    *      Use kFingerprintTypeFile instead.
    */
    kFingerprintTypeCMX,
    
    /**
    * @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
    *      Use kFingerprintTypeStream3 or kFingerprintTypeStream6 instead.
    */
    kFingerprintTypeGNFPX
    
} ;


/***************************************
* GnStatus
*/
typedef NS_ENUM(NSInteger,GnStatus)
{
    /** @internal kStatusUnknown @endinternal
    * Status unknown.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusUnknown = 0,
    
    /* Basic messages */
    
    /** @internal kStatusBegin @endinternal
    * Issued once per application function call, at the beginning of the call; percent_complete = 0.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusBegin,
    
    /** @internal kStatusProgress @endinternal
    * Issued roughly 10 times per application function call; percent_complete values between 1-100.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusProgress,
    
    /** @internal kStatusComplete @endinternal
    * Issued once per application function call, at the end of the call; percent_complete = 100.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusComplete,
    
    /** @internal kStatusErrorInfo @endinternal
    * Issued when an error is encountered. If sent, call #gnsdk_manager_error_info().
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusErrorInfo,
    
    /* Advanced messages */
    
    /** @internal kStatusConnecting @endinternal
    * Issued when connecting to network.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusConnecting,
    
    /** @internal kStatusSending @endinternal
    * Issued when uploading.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusSending,
    
    /** @internal kStatusReceiving @endinternal
    * Issued when downloading.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusReceiving,
    
    /** @internal kStatusDisconnected @endinternal
    * Issued when disconnected from network.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusDisconnected,
    
    /** @internal kStatusReading @endinternal
    * Issued when reading from storage.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusReading,
    
    /** @internal kStatusWriting @endinternal
    * Issued when writing to storage.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusWriting,            /* issued whenever writing to storage. */
    
    /** @internal gnsdk_status_cancelled @endinternal
    * Issued when transaction/query is cancelled
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusCancelled
    
} ;


/***************************************
* GnLanguage
*/
typedef NS_ENUM(NSInteger,GnLanguage)
{
    kLanguageInvalid = 0,
    
    kLanguageArabic,
    kLanguageBulgarian,
    kLanguageChineseSimplified,
    kLanguageChineseTraditional,
    kLanguageCroatian,
    kLanguageCzech,
    kLanguageDanish,
    kLanguageDutch,
    kLanguageEnglish,
    kLanguageFarsi,
    kLanguageFinnish,
    kLanguageFrench,
    kLanguageGerman,
    kLanguageGreek,
    kLanguageHungarian,
    kLanguageIndonesian,
    kLanguageItalian,
    kLanguageJapanese,
    kLanguageKorean,
    kLanguageNorwegian,
    kLanguagePolish,
    kLanguagePortuguese,
    kLanguageRomanian,
    kLanguageRussian,
    kLanguageSerbian,
    kLanguageSlovak,
    kLanguageSpanish,
    kLanguageSwedish,
    kLanguageThai,
    kLanguageTurkish,
    kLanguageVietnamese
} ;


/***************************************
* GnRegion
*/
typedef NS_ENUM(NSInteger,GnRegion)
{
    /** Default region. A region will be selected based on what's available. */
    kRegionDefault = 0,
    
    /** Global region */
    kRegionGlobal,
    
    /** United States region */
    kRegionUS,
    
    /** Japan region */
    kRegionJapan,
    
    /** China region */
    kRegionChina,
    
    /** Taiwan region */
    kRegionTaiwan,
    
    /** Korea region */
    kRegionKorea,
    
    /** Europe region */
    kRegionEurope,
    
    /** Deprecated, will be removed in a future release, use kRegionUS. */
    kRegionNorthAmerica,
    
    /** Latin America region */
    kRegionLatinAmerica,
    
    /** India region */
    kRegionIndia
} ;


/***************************************
* GnDescriptor
*/
typedef NS_ENUM(NSInteger,GnDescriptor)
{
    kDescriptorDefault = 0,
    
    kDescriptorSimplified,
    kDescriptorDetailed
} ;


/***************************************
* GnContentType
*/
typedef NS_ENUM(NSInteger,GnContentType)
{
    kContentTypeNull = 0,
    kContentTypeUnknown = 1,
    
    kContentTypeImageCover,
    kContentTypeImageArtist,
    kContentTypeImageVideo,
    kContentTypeImageLogo,
    kContentTypeBiography,
    kContentTypeReview,
    kContentTypeNews,
    kContentTypeArtistNews,
    kContentTypeListenerComments,
    kContentTypeReleaseComments
} ;


/***************************************
* GnImageSize
*/
typedef NS_ENUM(NSInteger,GnImageSize)
{
    kImageSizeUnknown = 0,
    
    kImageSize75,
    kImageSize110,
    kImageSize170,
    kImageSize220,
    kImageSize300,
    kImageSize450,
    kImageSize720,
    kImageSize1080,
    
    /* Size aliases */
    kImageSizeThumbnail = kImageSize75,
    kImageSizeSmall     = kImageSize170,
    kImageSizeMedium    = kImageSize450,
    kImageSizeLarge     = kImageSize720,
    kImageSizeXLarge    = kImageSize1080
    
} ;


/***************************************
* GnLicenseInputMode
*/
typedef NS_ENUM(NSInteger,GnLicenseInputMode)
{
    kLicenseInputModeInvalid = 0,
    
    /**
    * Submit license content as string
    */
    kLicenseInputModeString,
    
    /**
    * Submit license content in file
    */
    kLicenseInputModeFilename,
    
    /**
    * Submit license content from stdin
    */
    kLicenseInputModeStandardIn
} ;


/***************************************
* GnUserRegisterMode
*/
typedef NS_ENUM(NSInteger,GnUserRegisterMode)
{
    /**
    * Register a user via a netowrk connection with Gracenote Service. A user
    * must be registered online before any online queries can be made against
    * Gracenote Service.
    */
    kUserRegisterModeOnline = 1,
    
    /**
    * Register a user for local use only. User's registered locally can only
    * perform queries against local databases and not against Gracenote
    * Service.
    */
    kUserRegisterModeLocalOnly
} ;


/***************************************
* GnAcrAudioAlgorithm
*/
typedef NS_ENUM(NSInteger,GnAcrAudioAlgorithm)
{
    /**
    *   Audio: 3-second blocks, very low quality (mobile audio).
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioAlgorithmLowQuality = 1,
    
    /**
    *   Audio: 3-second blocks, medium quality (media monitoring).
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioAlgorithmMediumQuality,
    
    
    /**
    *   Audio: 3-second blocks, high quality (media monitoring).
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioAlgorithmHighQuality,
    
    
    /**
    *   Audio: 3-second blocks, very high quality (media monitoring).
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioAlgorithmVeryHighQuality
    
} ;


/***************************************
* GnAcrAudioSampleFormat
*/
typedef NS_ENUM(NSInteger,GnAcrAudioSampleFormat)
{
    /**
    * Signed 8-bit PCM samples.
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioSampleFormatPcm8,
    
    /**
    *   Signed 16-bit PCM samples.
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioSampleFormatPcm16
    
} ;


/***************************************
* GnAcrAudioFPQueryMode
*/
typedef NS_ENUM(NSInteger,GnAcrAudioFPQueryMode)
{
    /**
    * Manually triggerred fingerprint queries.
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioFPQueryManual,
    
    /**
    * Automatic triggered non music fingerprint queries
    * @ingroup Acr_TypesEnums
    */
    kAcrAudioFPQueryAutomatic
    
} ;


/***************************************
* GnAcrStatusType
*/
typedef NS_ENUM(NSInteger,GnAcrStatusType)
{
    /**
    * ACR status type of debug, for reporting debug information.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusDebug                    = 0,
    
    /**
    * ACR query process is beginning.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusQueryBegin               = 10,
    
    /**
    * Connecting to the Gracenote Service.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusConnecting               = 20,
    
    /**
    * Sending ACR query data to the Gracenote Service.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusSending                  = 30,
    
    /**
    * Receiving ACR result data from the Gracenote Service.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusReceiving                = 40,
    
    /**
    * ACR audio fingerprint generation has started.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusAudioFpStarted           = 45,
    
    /**
    * ACR audio fingerprint generation has completed.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusAudioFpGenerated         = 50,
    
    /**
    * Silence is detected
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusAudioSilent              = 70,
    
    /**
    * Silence to sound ratio
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusSilenceRatio             = 80,
    
    /**
    * Percentage of audio over the last several seconds that is non pitched
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusNonPitched               = 81,
    
    /**
    * Percentage of audio over the last several seconds that is music
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusMusic                    = 82,
    
    /**
    * Percentage of audio over the last several seconds that is speech
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusSpeech                   = 83,
    
    /**
    * ACR local query processing is complete.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusQueryCompleteLocal       = 100,
    
    /**
    * ACR online query processing is complete.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusQueryCompleteOnline      = 110,
    
    /**
    * The SDK has switched out of No Match Mode
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusNormalMatchMode          = 200,
    
    /**
    *   There have been enough no matches that the SDK has switched
    *   into "No Match" mode, where it does lookups less frequently.
    *   This mode is disabled when a match happens or a manual
    *   lookup is requested.
    *   When this callback is sent, the "value1" parameter will contain
    *   the current no match delay in seconds.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusNoMatchMode              = 210,
    
    /**
    *   ACR error.
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusError                    = 600,
    
    /**
    *   Audio transition detected
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusTransition               = 700,
    
    /**
    *   An ACR batch query for EPG and Video metadata has begun
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusBatchBeginOnlineVideo    = 900,
    
    /**
    *   An ACR batch online query for EPG and Video metadata has completed
    * @ingroup Acr_TypesEnums
    */
    kAcrStatusBatchCompleteOnlineVideo = 910
    
} ;


/***************************************
* GnAcrOptimizationType
*/
typedef NS_ENUM(NSInteger,GnAcrOptimizationType)
{
    /**
    *   Default is optimizing for accuracy.
    * @ingroup Acr_TypesEnums
    */
    kAcrOptimizationTypeDefault = 1,
    
    /**
    *   Optimize for accuracy (default); this can result in slightly slower, but more accurate, responses.
    * @ingroup Acr_TypesEnums
    */
    kAcrOptimizationTypeAccuracy,
    
    /**
    *   Optimize for speed; this can result in slightly faster, but less accurate, responses.
    * @ingroup Acr_TypesEnums
    */
    kAcrOptimizationTypeSpeed,
    
    /**
    * Adaptive automatically optimizes match rate, precision, and battery consumption under current environmental
    * conditions (e.g. audio level and quality, ambient noise, etc.). Generally, it works best in noisy environments
    * and under most circumstances, but may not give you the speed or accuracy of the other modes. Support for this mode
    * is limited. Please consult with Gracenote Support Services before using this mode.
    * @ingroup Acr_TypesEnums
    */
    kAcrOptimizationTypeAdaptive
    
} ;


/***************************************
* GnAcrMatchSourceType
*/
typedef NS_ENUM(NSInteger,GnAcrMatchSourceType)
{
    /**
    * Fingerprint not matched.
    * @ingroup Acr_TypesEnums
    */
    kAcrMatchSourceNone = 0,
    
    /**
    * Match result from an online video lookup
    * @ingroup Acr_TypesEnums
    */
    kAcrMatchSourceOnline,
    
    /**
    * Match result from an online music lookup
    * @ingroup Acr_TypesEnums
    */
    kAcrMatchSourceOnlineMusic,
    
    /**
    * Match result from local lookup
    * @ingroup Acr_TypesEnums
    */
    kAcrMatchSourceLocal
    
} ;


/***************************************
* GnAcrLookupSourceType
*/
typedef NS_ENUM(NSInteger,GnAcrLookupSourceType)
{
    /**
    * Indicates a query to only the local database
    * @ingroup Acr_TypesEnums
    */
    kAcrLookupSourceLocalOnly = 1,
    
    /**
    * Indicates a query to only the Gracenote Service
    * @ingroup Acr_TypesEnums
    */
    kAcrLookupSourceOnlineOnly,
    
    /**
    * Indicates a query to the local database and the Gracenote Service in parallel
    * @ingroup Acr_TypesEnums
    */
    kAcrLookupSourceLocalAndOnlineParallel,
    
    /**
    * Indicates a sequential query to the local database first and, if no match is found, a query to the Gracenote Service is performed
    * @ingroup Acr_TypesEnums
    */
    kAcrLookupSourceLocalAndOnlineSerial
} ;


/***************************************
* GnDspFeatureQuality
*/
typedef NS_ENUM(NSInteger,GnDspFeatureQuality)
{
    kDspFeatureQualityUnknown = 0,
    
    kDspFeatureQualityStandard,
    kDspFeatureQualityShort,
    kDspFeatureQualitySilent
} ;


/***************************************
* GnDspFeatureType
*/
typedef NS_ENUM(NSInteger,GnDspFeatureType)
{
    kDspFeatureTypeInvalid = 0,
    
    kDspFeatureTypeAFX3,
    kDspFeatureTypeChroma,
    kDspFeatureTypeCantametrixQ,
    kDspFeatureTypeCantametrixR,
    kDspFeatureTypeFEXModule,
    kDspFeatureTypeFraunhofer,
    kDspFeatureTypeFAPIQ3sVLQ,
    kDspFeatureTypeFAPIQ3sLQ,
    kDspFeatureTypeFAPIQ3sMQ,
    kDspFeatureTypeFAPIQ3sHQ,
    kDspFeatureTypeFAPIQ3sVHQ,
    kDspFeatureTypeFAPIR,
    kDspFeatureTypeNanoFAPIQ,
    kDspFeatureTypeMicroFAPIQ
} ;


/***************************************
* GnEpgPostalCodeCountry
*/
typedef NS_ENUM(NSInteger,GnEpgPostalCodeCountry)
{
    kEpgPostalCodeCountryUnknown = 0,
    
    kEpgPostalCodeCountryUsa,
    kEpgPostalCodeCountryCanada
} ;


/***************************************
* GnImagePreferenceType
*/
typedef NS_ENUM(NSInteger,GnImagePreferenceType)
{
    /**
    * Retrieve exact size as specified by GnImageSize
    */
    kImagePreferenceExact = 1,
    
    /**
    * Retrieve exact or smaller size as specified by GnImageSize
    */
    kImagePreferenceLargest,
    
    /**
    * Retrieve exact or larger size as specified by GnImageSize
    */
    kImagePreferenceSmallest
    
} ;


/***************************************
* GnLinkContentType
*/
typedef NS_ENUM(NSInteger,GnLinkContentType)
{
    /** @internal kLinkContentUnknown @endinternal
    *
    *   Indicates an invalid content type.
    * @ingroup Link_TypesEnums
    */
    kLinkContentUnknown = 0,
    
    /** @internal kLinkContentCoverArt @endinternal
    *
    *   Retrieves cover artwork; this is Album-level and Video Product-level
    *   content.
    *
    *   Use with #GNSDK_GDO_TYPE_ALBUM and #GNSDK_GDO_TYPE_VIDEO_PRODUCT.
    *
    *   Do not use with #GNSDK_GDO_TYPE_VIDEO_WORK,
    *   #GNSDK_GDO_TYPE_VIDEO_SERIES, #GNSDK_GDO_TYPE_VIDEO_SEASON, or
    *   #GNSDK_GDO_TYPE_CONTRIBUTOR.
    * @ingroup Link_TypesEnums
    */
    kLinkContentCoverArt,
    
    /** @internal kLinkContentGenreArt @endinternal
    *
    *   Retrieves artwork for the object's primary genre; this is Album-level
    *   and Track-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentGenreArt,
    
    /** @internal kLinkContentReview @endinternal
    *
    *   Retrieves a review for the object; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentReview,
    
    /** @internal kLinkContentBiography @endinternal
    *
    *   Retrieves a biography for the object; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentBiography,
    
    /** @internal kLinkContentArtistNews @endinternal
    *
    *   Retrieves news for the artist; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentArtistNews,
    
    /** @internal kLinkContentLyricXML @endinternal
    *
    *   Retrieves lyrics in XML form; this is Lyric-level and Track-level
    *   data.
    * @ingroup Link_TypesEnums
    */
    kLinkContentLyricXML,
    
    /** @internal kLinkContentLyricText @endinternal
    *
    *   Retrieves lyrics in plain text form; this is Lyric-level and
    *   Track-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentLyricText,
    
    /** @internal kLinkContentDspData @endinternal
    *
    *   Retrieves DSP content; this is Track-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentDspData,
    
    /** @internal kLinkContentCommentsListener @endinternal
    *
    *   Retrieves listener comments; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentCommentsListener,
    
    /** @internal kLinkContentCommentsRelease @endinternal
    *
    *   Retrieves new release comments; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentCommentsRelease,
    
    /** @internal kLinkContentNews @endinternal
    *
    *   Retrieves news for the object; this is Album-level content.
    * @ingroup Link_TypesEnums
    */
    kLinkContentNews,
    
    /** @internal kLinkContentImage @endinternal
    *
    *   Retrieves an image for specific Video types.
    *
    *   Use with #GNSDK_GDO_TYPE_VIDEO_WORK, #GNSDK_GDO_TYPE_VIDEO_SERIES,
    *   #GNSDK_GDO_TYPE_VIDEO_SEASON, and video #GNSDK_GDO_TYPE_CONTRIBUTOR.
    *
    *   Do not use with #GNSDK_GDO_TYPE_VIDEO_PRODUCT.
    *
    *   Note: At the time of this guide's publication, support for Video
    *   Explore Seasons and Series image retrieval through Seasons, Series, and
    *   Works queries is limited. Contact your Gracenote Professional Services
    *   representative for updates on the latest supported images.
    * @ingroup Link_TypesEnums
    */
    kLinkContentImage,
    
    /** @internal kLinkContentImageArtist @endinternal
    * Retrieves an artist image for the object; this can be album-level or contributor-level content.
    * Use with #GNSDK_GDO_TYPE_ALBUM or #GNSDK_GDO_TYPE_CONTRIBUTOR.
    * There are three ways to retrieve an artist image:
    * <ul><li>If the GDO is the result of an album match, you can retrieve the artist image from the album GDO.</li>
    * <li>If the GDO is the result of an album match, you can retrieve a contributor GDO from the album GDO,
    * and then retrieve the artist image from the contributor GDO.</li>
    * <li>If the GDO is the result of a contributor match, which can only come from a local text query,
    * you can use the GDO to retrieve the artist image from the local image database.
    * However, you cannot retrieve the artist image from the online database using this GDO.</li></ul>
    *
    * The GDO used to retrieve an artist image can be the full object or a recently deserialized object.
    *
    *   Note: At the time of this guide's publication, the available Album
    *   artist images are limited. Contact your Gracenote Professional Services
    *   representative for updates on the latest supported images.
    * @ingroup Link_TypesEnums
    */
    kLinkContentImageArtist
    
} ;


/***************************************
* GnLinkDataType
*/
typedef NS_ENUM(NSInteger,GnLinkDataType)
{
    /** @internal kLinkDataUnknown @endinternal
    *
    *   Indicates an invalid data type.
    * @ingroup Link_TypesEnums
    */
    kLinkDataUnknown     = 0,
    
    /** @internal kLinkDataTextPlain @endinternal
    *
    *   Indicates the content buffer contains plain text data (null terminated).
    * @ingroup Link_TypesEnums
    */
    kLinkDataTextPlain   = 1,
    
    /** @internal kLinkDataTextXML @endinternal
    *
    *   Indicates the content buffer contains XML data (null terminated).
    * @ingroup Link_TypesEnums
    */
    kLinkDataTextXML     = 2,
    
    /** @internal kLinkDataNumber @endinternal
    *
    *   Indicates the content buffer contains a numerical value
    *   (gnsdk_uint32_t). Unused.
    * @ingroup Link_TypesEnums
    */
    kLinkDataNumber      = 10,
    
    /** @internal kLinkDataImageJpeg @endinternal
    *
    *   Indicates the content buffer contains jpeg image data.
    * @ingroup Link_TypesEnums
    */
    kLinkDataImageJpeg   = 20,
    
    
    /** @internal kLinkDataImagePng @endinternal
    *
    *   Indicates the content buffer contains png image data.
    * @ingroup Link_TypesEnums
    */
    kLinkDataImagePng    = 30,
    
    
    /** @internal kLinkDataImageBinary @endinternal
    *
    *   Indicates the content buffer contains externally defined binary data.
    * @ingroup Link_TypesEnums
    */
    kLinkDataImageBinary = 100
    
} ;


/***************************************
* GnListType
*/
typedef NS_ENUM(NSInteger,GnListType)
{
    kListTypeInvalid = 0,
    
    /**
    * This list contains languages that are supported by Gracenote, and are typically used to indicate
    * the original language of an item.
    */
    kListTypeLanguages,
    
    /**
    * This list contains scripts that are supported by Gracenote
    */
    kListTypeScripts,
    
    /**
    * The list of supported music genres.
    * <p><b>Remarks:</b></p>
    * The genre list contains a hierarchy of genres available from Gracenote strictly for music data.
    */
    kListTypeGenres,
    
    /**
    * The list of supported geographic origins for artists.
    */
    kListTypeOrigins,
    
    /**
    * The list of supported music era categories.
    */
    kListTypeEras,
    
    /**
    * The list of supported artist type categories.
    */
    kListTypeArtistTypes,
    
    /**
    * This list contains role list elements supported Gracenote for album data, such as Vocalist and Bass Guitar.
    */
    kListTypeRoles,
    
    /**
    *  This list contains a hierarchy of genre list elements available from Gracenote, strictly for
    * video data.
    */
    kListTypeGenreVideos,
    
    /**
    * This list contains movie rating list elements supported by Gracenote.
    */
    kListTypeRatings,
    
    /**
    * This list contains film content rating list elements supported by Gracenote.
    */
    kListTypeRatingTypes,
    
    /**
    * This list contains contributor role list elements available from Gracenote, such as Actor or
    * Costume Design. These apply to video data.
    */
    kListTypeContributors,
    
    /**
    * The list of supported feature types for video data.
    */
    kListTypeFeatureTypes,
    
    /**
    *  The list of supported video regions.
    */
    kListTypeVideoRegions,
    
    /**
    * The list of supported video types, such as Documentary, Sporting Event, or Motion Picture.
    */
    kListTypeVideoTypes,
    
    /**
    * The list of supported media types for music and video, such as Audio CD, Blu-ray, DVD, or HD DVD.
    */
    kListTypeMediaTypes,
    
    /**
    * The list of supported video serial types, such as Series or Episode.
    */
    kListTypeVideoSerialTypes,
    
    /**
    * The list of supported work types for video data, such as Musical or Image.
    */
    kListTypeWorkTypes,
    
    /**
    * The list of supported media spaces for video data, such as Music, Film, or Stage.
    */
    kListTypeMediaSpaces,
    
    /**
    * The list of supported moods for music data. Moods are categorized into levels, from more general
    * (Level 1, such as Blue) to more specific (Level 2, such as Gritty/Earthy/Soulful).
    */
    kListTypeMoods,
    
    /**
    * The list of supported tempos for music data, has three levels of granularity.
    * The tempos are categorized in levels in increasing order of granularity.
    * Level 1: The meta level, such as Fast Tempo.
    * Level 2: The sub tempo level, such as Very Fast.
    * Level 3: The micro level, which may be displayed as a numeric tempo range, such as 240-249, or a
    * descriptive phrase.
    */
    kListTypeTempos,
    
    /**
    * The list of supported composition forms for classical music.
    */
    kListTypeCompostionForm,
    
    /**
    * The list of supported instrumentation for classical music.
    */
    kListTypeInstrumentation,
    
    /**
    * The list of supported overall story types for video data, such as Love Story.
    * It includes general theme classifications such as such as Love Story, Family Saga, Road Trip,
    * and Rags to Riches.
    */
    kListTypeVideoStoryType,
    
    /**
    * The list of supported audience types for video data.
    * It includes general audience classifications by age, ethnicity, gender, and spiritual beliefs,
    * such as Kids & Family, African-American, Female, Gay & Lesbian, and Buddhist.
    */
    kListTypeVideoAudience,
    
    /**
    * The list of supported moods for video data, such as Offbeat.
    * It includes general classifications such as such as Offbeat, Uplifting, Mystical, and Sarcastic.
    */
    kListTypeVideoMood,
    
    /**
    * The list of supported film reputation types for video data, such as Classic.
    * It includes general classifications such as such as Classic, Chick Flick, and Cult.
    */
    kListTypeVideoReputation,
    
    /**
    * The list of supported scenarios for video data. It
    * includes general classifications such as such as Action, Comedy, and Drama.
    */
    kListTypeVideoScenario,
    
    /**
    * The language of the list is determined by the language value given to
    */
    kListTypeVideoSettingEnv,
    
    /**
    * The list of supported historical time settings for video data, such as Elizabethan Era,
    * 1558-1603, or Jazz Age, 1919-1929.
    */
    kListTypeVideoSettingPeriod,
    
    /**
    * The list of supported story concept sources for video data, such as Fairy Tales & Nursery Rhymes.
    * It includes story source classifications such as Novel, Video Game, and True Story.
    */
    kListTypeVideoSource,
    
    /**
    * The list of supported film style types for video data, such as Film Noir.It
    * includes general style classifications such as Art House, Film Noir, and Silent.
    */
    kListTypeVideoStyle,
    
    /**
    * The list of supported film topics for video data, such as Racing or Teen Angst. It includes a diverse
    * range of film topics, such as Politics, Floods, Mercenaries, Surfing, and Adventure. It also includes
    * some list elements that can be considered sub-topics of a broader topic. For example, the list element Aliens (the broad topic),
    * and Nice Aliens and Bad Aliens (the more defined topics).
    */
    kListTypeVideoTopic,
    
    /**
    * The list of supported viewing types for EPG data, such as live and rerun.
    */
    kListTypeEpgViewingTypes,
    
    /**
    * The list of supported audio types for EPG data, such as stereo and dolby.
    */
    kListTypeEpgAudioTypes,
    
    /**
    * The list of supported video types for EPG data, such as HDTV and PAL30.
    */
    kListTypeEpgVideoTypes,
    
    /**
    * The list of supported video types for EPG data, such as closed caption.
    */
    kListTypeEpgCaptionTypes,
    
    /**
    * The list of supported categories for IPG data, such as movie and TV series.
    */
    kListTypeIpgCategoriesL1,
    
    /**
    * The list of supported categories for IPG data, such as action and adventure.
    */
    kListTypeIpgCategoriesL2,
    
    /**
    * The list of supported production types for EPG data, such as news and documentary.
    */
    kListTypeEpgProductionTypes,
    
    /**
    * The list of supported device types for EPG data.
    */
    kListTypeEpgDeviceTypes
} ;


/***************************************
* GnListRenderFlags
*/
typedef NS_ENUM(NSInteger,GnListRenderFlags)
{
    kRenderDefault,
    
    /**
    * Minimal information included.
    */
    kRenderMinimal,
    
    /**
    * All information included.
    */
    kRenderFull
    
} ;


/***************************************
* GnLocaleGroup
*/
typedef NS_ENUM(NSInteger,GnLocaleGroup)
{
    /**
    * Invalid locale group
    */
    kLocaleGroupInvalid = 0,
    
    /**
    * Locale group for the GNSDK music products. Set this when creating a locale used with the MusicID and MusicID -File libraries.
    */
    kLocaleGroupMusic,
    
    /**
    * Locale group for the GNSDK video products. Set this when creating a locale used with the VideoID or Video Explore libraries (or both).
    */
    kLocaleGroupVideo,
    
    /**
    * Locale group for the GNSDK Playlist product. Set this when creating a locale used with the Playlist library.
    */
    kLocaleGroupPlaylist,
    
    /**
    * Locale group for the GNSDK EPG product. Set this when creating a locale used with the EPG library.
    */
    kLocaleGroupEpg,
    
    /**
    * Locale group for the GNSDK ACR products. Set this when creating a locale used with the ACR library.
    * Additionally, this will set the locale value for the MusicID, VideoID, VideoExplore and EPG libraries
    * since those libraries are used by the ACR product.
    *
    * <p><b>Remarks:</b></p>
    * If kLocaleGroupAcr is set <i>after</i> kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set, then kLocaleGroupAcr
    * will override any previous locale settings used with the MusicID, VideoID/VideoExplore and EPG libraries, and set the locale
    * for all of those libraries to the same locale value.
    *
    * If kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set <i>after</i> kLocaleGroupAcr is set, then it will override
    * the locale value previously set by kLocaleGroupAcr for the MusicID, VideoID/VideoExplore or EPG libraries, respectively.
    */
    kLocaleGroupAcr
} ;


/***************************************
* GnLogMessageType
*/
typedef NS_ENUM(NSInteger,GnLogMessageType)
{
    kLoggingMessageTypeInvalid = 0,
    
    kLoggingMessageTypeError,
    kLoggingMessageTypeWarning,
    kLoggingMessageTypeInfo,
    kLoggingMessageTypeDebug
    
} ;


/***************************************
* GnLogPackageType
*/
typedef NS_ENUM(NSInteger,GnLogPackageType)
{
    kLogPackageAll = 1,
    kLogPackageAllGNSDK,
    
    kLogPackageManager,
    kLogPackageMusicID,
    kLogPackageMusicIDFile,
    kLogPackageMusicIDStream,
    kLogPackageMusicIdMatch,
    kLogPackageVideoID,
    kLogPackageLink,
    kLogPackageDsp,
    kLogPackageAcr,
    kLogPackageEPG,
    kLogPackageSubmit,
    kLogPackageTaste,
    kLogPackageRhythm,
    kLogPackagePlaylist,
    kLogPackageStorageSqlite,
    kLogPackageStorageQNX,
    kLogPackageLookupLocal,
    kLogPackageLookupFPLocal,
    kLogPackageLookupLocalStream,
    kLogPackageLookupLocalStream2,
    kLogPackageEDBInstall,
    kLogPackageMoodGrid,
    kLogPackageCorrelates,
    kLogPackageInternal,
    kLogPackageRadio
} ;


/***************************************
* GnVideoSearchType
*/
typedef NS_ENUM(NSInteger,GnVideoSearchType)
{
    /**
    *   Unknown search type; the default state.
    */
    kSearchTypeUnknown = 0,
    
    /**
    *   Anchored text search, used for product title and suggestion searches.
    *   Retrieves results that begin with the same characters as exactly
    *   specified; for example, entering <i>dar</i>, <i>dark</i>, <i>dark k</i>,
    *   or <i>dark kni</i> retrieves the title <i>Dark Knight,</i> but entering<i>
    *   knight</i> will not retrieve<i> Dark Knight</i>. Note that this search
    *   type recognizes both partial and full words.
    */
    kSearchTypeAnchored,
    
    /**
    *   Normal keyword filter search for contributor, product, and work title
    *   searches; for example, a search using a keyword of <i>dark</i>, <i>knight</i>,
    *   or <i>dark knight </i>retrieves the title <i>Dark Knight</i>. Note that
    *   this search type recognizes only full words, not partial words; this
    *   means that entering only <i>dar</i> for <i>dark</i> is not recognized.
    */
    kSearchTypeDefault
    
} ;


/***************************************
* GnVideoSearchField
*/
typedef NS_ENUM(NSInteger,GnVideoSearchField)
{
    /**
    *  Contributor name search field.
    */
    kSearchFieldContributorName = 1,
    
    /**
    *  Character name search field.
    */
    kSearchFieldCharacterName,
    
    /**
    *  Work franchise search field.
    */
    kSearchFieldWorkFranchise,
    
    /**
    *  Work series search field.
    */
    kSearchFieldWorkSeries,
    
    /**
    *  Work title search field.
    */
    kSearchFieldWorkTitle,
    
    /**
    *
    *  Product title search field.
    */
    kSearchFieldProductTitle,
    
    /**
    *
    *  Series title search field.
    */
    kSearchFieldSeriesTitle,
    
    /**
    *  Comprehensive search field.
    *  <p><b>Remarks:</b></p>
    *  This option searches all relevant search fields and returns any
    *  data found. Note, however, that you cannot use this search field for
    *  suggestion search queries.
    */
    kSearchFieldAll
    
} ;


/***************************************
* GnVideoTOCFlag
*/
typedef NS_ENUM(NSInteger,GnVideoTOCFlag)
{
    /**
    *  Generally recommended flag to use when setting a video TOC.
    *  <p><b>Remarks:</b></p>
    *  Use this flag for the TOC flag parameter that is set with the
    *  FindProducts() API, for all general cases; this includes when using the Gracenote
    *  Video Thin Client component to produce TOC strings.
    *  For cases when other VideoID TOC flags seem necessary, contact Gracenote for guidance on setting
    *  the correct flag.
    */
    kTOCFlagDefault = 0,
    
    /**
    *  Flag to indicate a given simple video TOC is from a PAL (Phase Alternating Line) disc.
    *  <p><b>Remarks:</b></p>
    *  Use this flag only when directed to by Gracenote. Only special video TOCs that are provided by
    *  Gracenote and external to the
    *  GNSDK may require this flag.
    */
    kTOCFlagPal,
    
    /**
    *  Flag to indicate a given simple video TOC contains angle data.
    *  <p><b>Remarks:</b></p>
    *  Use this flag only if Gracenote directs you to. Only special video TOCs that Gracenote provides
    *  and that are external to the GNSDK may require this flag.
    */
    kTOCFlagAngles
    
} ;


/***************************************
* GnVideoListElementFilterType
*/
typedef NS_ENUM(NSInteger,GnVideoListElementFilterType)
{
    /**
    *  List-based filter to include/exclude genres.
    */
    kListElementFilterGenre = 1,
    
    /**
    *  List-based filter to include/exclude production types.
    */
    kListElementFilterProductionType,
    
    /**
    *  List-based filter to include/exclude serial types.
    */
    kListElementFilterSerialType,
    
    /**
    *  List-based filter to include/exclude origin.
    */
    kListElementFilterOrigin
    
} ;


/***************************************
* GnVideoFilterType
*/
typedef NS_ENUM(NSInteger,GnVideoFilterType)
{
    /**
    *  Filter for Season numbers; not list-based.
    */
    kFilterSeasonNumber = 1,
    
    /**
    *  Filter for season episode numbers; not list-based.
    */
    kFilterSeasonEpisodeNumber,
    
    /**
    *  Filter for series episode numbers; not list-based.
    */
    kFilterSeriesEpisodeNumber
    
} ;


/***************************************
* GnVideoExternalIdType
*/
typedef NS_ENUM(NSInteger,GnVideoExternalIdType)
{
    /**
    *  Sets a Universal Product Code (UPC) value as an external ID for a Products query.
    *  <p><b>Remarks:</b></p>
    *  Use as the external ID type parameter set with the ExternalIdTypeSet() API when
    *  providing a video UPC value for identification.
    */
    kExternalIdTypeUPC = 1,
    
    /**
    *
    *  Sets a International Standard Audiovisual Number (ISAN) code as an external ID for a Works
    *  query.
    *  <p><b>Remarks:</b></p>
    *  Use as the external ID Type parameter set with the ExternalIdTypeSet() API when
    *   providing a video ISAN value for identification.
    */
    kExternalIdTypeISAN
    
} ;


/***************************************
* GnDataLevel
*/
typedef NS_ENUM(NSInteger,GnDataLevel)
{
    kDataLevelInvalid = 0,
    
    kDataLevel_1      = 1,  /* least granular */
    kDataLevel_2,
    kDataLevel_3,
    kDataLevel_4            /* most granular */
    
} ;


#endif /* _GNENUMS_H_ */

