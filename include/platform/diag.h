/*
 *  Copyright (c) 2016, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief
 *   This file defines the platform diag interface.
 *
 */

#ifndef DIAG_H_
#define DIAG_H_

#include <stdint.h>
#include <stddef.h>

#include <platform/radio.h>

#include <openthread-types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup diag Diag
 * @ingroup platform
 *
 * @brief
 *   This module includes the platform abstraction for diagnostics features.
 *
 * @{
 *
 */

/**
 * Process the platform specific diagnostics features.
 *
 * @param[in]   aInstance       The OpenThread instance for current request.
 * @param[in]   argc            The argument counter of diagnostics command line.
 * @param[in]   argv            The argument vector of diagnostics command line.
 * @param[out]  aOutput         The diagnostics execution result.
 * @param[in]   aOutputMaxLen   The output buffer size.
 */
void otPlatDiagProcess(otInstance *aInstance, int argc, char *argv[], char *aOutput, size_t aOutputMaxLen);

/**
 * Set diagnostics mode.
 */
void otPlatDiagModeSet(bool aMode);

/**
 * Get diagnostics mode.
 */
bool otPlatDiagModeGet(void);

/**
 * Set diagnostics channel.
 */
void otPlatDiagChannelSet(uint8_t aChannel);

/**
 * Set diagnostics tx power.
 */
void otPlatDiagTxPowerSet(int8_t aTxPower);

/**
 * Process the platform specific received frame parsing.
 *
 * @param[in]   aInstance   The OpenThread instance for current request.
 * @param[in]   aFrame      The received radio frame.
 * @param[in]   aError      The received radio frame status.
 */
void otPlatDiagRadioReceived(otInstance *aInstance, RadioPacket *aFrame, ThreadError aError);

/**
 * Process the platform specific alarm callback.
 *
 * @param[in]   aInstance   The OpenThread instance for current request.
 */
void otPlatDiagAlarmCallback(otInstance *aInstance);

#ifdef __cplusplus
}  // end of extern "C"
#endif

#endif
