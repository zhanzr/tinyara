/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * arch/arm/src/armv7-r/mpcore.h
 * Generic Interrupt Controller Definitions
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Reference:
 *   Cortex™-A9 MPCore, Revision: r4p1, Technical Reference Manual, ARM DDI
 *   0407I (ID091612).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_ARMV7_R_MPCORE_H
#define __ARCH_ARM_SRC_ARMV7_R_MPCORE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "chip.h"				/* For CHIP_MPCORE_VBASE */

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* MPCore registers are memory mapped and accessed through a processor
 * specific private address space via the SCU.  The Cortex-A9 MCU chip.h
 * header file must provide the definition CHIP_MPCORE_VBASE to access this
 * the registers in this memory region.
 */

/* Peripheral Base Offsets **************************************************/

#define MPCORE_SCU_OFFSET  0x0000	/* 0x0000-0x00fc SCU registers */
#define MPCORE_ICC_OFFSET  0x2000	/* 0x0000-0x00FC Interrupt conroller interface */
#define MPCORE_GTM_OFFSET  0x0200	/* 0x0200-0x02ff Global timer */
/* 0x0300-0x05ff Reserved */
#define MPCORE_PTM_OFFSET  0x0600	/* 0x0600-0x06ff Private timers and watchdogs */
/* 0x0700-0x07ff Reserved */
#define MPCORE_ICD_OFFSET  0x1000	/* 0x1000-0x1fff Interrupt Distributor */

/* Peripheral Base Addresses ************************************************/

#define MPCORE_SCU_VBASE   (CHIP_MPCORE_VBASE+MPCORE_SCU_OFFSET)
#define MPCORE_ICC_VBASE   (CHIP_MPCORE_VBASE+MPCORE_ICC_OFFSET)
#define MPCORE_GTM_VBASE   (CHIP_MPCORE_VBASE+MPCORE_GTM_OFFSET)
#define MPCORE_PTM_VBASE   (CHIP_MPCORE_VBASE+MPCORE_PTM_OFFSET)
#define MPCORE_ICD_VBASE   (CHIP_MPCORE_VBASE+MPCORE_ICD_OFFSET)

#endif							/* __ARCH_ARM_SRC_ARMV7_R_MPCORE_H */
