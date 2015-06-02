/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

// This class requires that the application link to the Apple AudioToolbox Framework.
// Public header

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "GnAudioSourceDelegate.h"

/** @addtogroup ios iOS
 *  \brief iOS specific APIs
 *  @{
 */

/**
 *  Gracenote recording helper wrapper class, provides audio recording capability in your application.
 *  Using a GnMic you can
 *    - Record until user stops the recording.
 *    - Pause and resume a recording.
 */
@interface GnMic : NSObject <GnAudioSourceDelegate>

/**
 * Acquires audio input hardware resource and initializes it as specified by audioConfig.
 * @param sampleRate       Preferred Sample rate to be used for recording audio.
 * @param bitsPerChannel   The number of bits per channel to use for recording audio.
 * @param numberOfChannels The number of channels used for recording audio. For example: 2 for stereo; 1 for mono.
 * @param delegate         An instance of a class conforming to GnMicDelegate protocol.
 * @return GnMic*          A valid GnMic instance if audio configuration was valid and allocation was successful; nil otherwise.
 */
- (instancetype) initWithSampleRate:(Float64) sampleRate bitsPerChannel:(UInt32) bitsPerChannel numberOfChannels:(UInt32)  numberOfChannels;
@end

/** @} */ // end of ios
