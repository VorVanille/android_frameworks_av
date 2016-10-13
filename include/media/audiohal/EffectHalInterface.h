/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_EFFECT_HAL_INTERFACE_H
#define ANDROID_HARDWARE_EFFECT_HAL_INTERFACE_H

#include <system/audio_effect.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>

namespace android {

class EffectHalInterface : public RefBase
{
  public:
    // Effect process function. Takes input samples as specified
    // in input buffer descriptor and output processed samples as specified
    // in output buffer descriptor.
    virtual status_t process(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) = 0;

    // Process reverse stream function. This function is used to pass
    // a reference stream to the effect engine.
    virtual status_t processReverse(audio_buffer_t *inBuffer, audio_buffer_t *outBuffer) = 0;

    // Send a command and receive a response to/from effect engine.
    virtual status_t command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData,
            uint32_t *replySize, void *pReplyData) = 0;

    // Returns the effect descriptor.
    virtual status_t getDescriptor(effect_descriptor_t *pDescriptor) = 0;

  protected:
    // Subclasses can not be constructed directly by clients.
    EffectHalInterface() {}

    // The destructor automatically releases the effect.
    virtual ~EffectHalInterface() {}
};

} // namespace android

#endif // ANDROID_HARDWARE_EFFECT_HAL_INTERFACE_H
