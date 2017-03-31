/****************************************************************************
 * arch/arm/src/sam34/lpc43_tc.h
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *            Alan Carvalho de Assis <acassis@gmail.com>
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

#ifndef __ARCH_ARM_SRC_LPC43_TMR_H
#define __ARCH_ARM_SRC_LPC43_TMR_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/timers/timer.h>

#include "chip.h"
#include "chip/lpc43_timer.h"
#include "chip/lpc43_ccu.h"

#ifdef CONFIG_TIMER

/****************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* Helpers **************************************************************************/

#define LPC43_TMR_SETMODE(d,mode)       ((d)->ops->setmode(d,mode))
#define LPC43_TMR_SETCLOCK(d,freq)      ((d)->ops->setclock(d,freq))
#define LPC43_TMR_SETPERIOD(d,period)   ((d)->ops->settimeout(d,period))
#define LPC43_TMR_GETCOUNTER(d)         ((d)->ops->getcounter(d))
#define LPC43_TMR_SETCHANNEL(d,ch,mode) ((d)->ops->setchannel(d,ch,mode))
#define LPC43_TMR_SETCOMPARE(d,ch,comp) ((d)->ops->setcompare(d,ch,comp))
#define LPC43_TMR_GETCAPTURE(d,ch)      ((d)->ops->getcapture(d,ch))
#define LPC43_TMR_SETISR(d,hnd,s)       ((d)->ops->setisr(d,hnd,s))
#define LPC43_TMR_ENABLEINT(d,s)        ((d)->ops->enableint(d,s))
#define LPC43_TMR_DISABLEINT(d,s)       ((d)->ops->disableint(d,s))
#define LPC43_TMR_ACKINT(d,s)           ((d)->ops->ackint(d,s))
#define LPC43_TMR_CHECKINT(d,s)         ((d)->ops->checkint(d,s))

/************************************************************************************
 * Public Types
 ************************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

struct lpc43_lowerhalf_s;

/************************************************************************************
 * Public Functions
 ************************************************************************************/

/* Power-up timer and get its structure */

FAR struct lpc43_lowerhalf_s *lpc43_tmr_init(int timer);

/* Power-down timer, mark it as unused */

int lpc43_tmr_deinit(FAR struct lpc43_lowerhalf_s * dev);

/****************************************************************************
 * Name: lpc43_tmrinitialize
 *
 * Description:
 *   Initialize the timer.  The timer is initialized and
 *   registers as 'devpath.  The initial state of the timer is
 *   disabled.
 *
 * Input Parameters:
 *   devpath - The full path to the timer.  This should be of the form
 *     /dev/timer0
 *   irq - irq associated with the timer
 * Returned Values:
 *   None
 *
 ****************************************************************************/

#if defined(CONFIG_LPC43_TMR0) || defined(CONFIG_LPC43_TMR1) || \
    defined(CONFIG_LPC43_TMR2) || defined(CONFIG_LPC43_TMR3)
void lpc43_tmrinitialize(FAR const char *devpath, int irq);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* CONFIG_TIMER */
#endif /* __ARCH_ARM_SRC_LPC43_TMR_H */
