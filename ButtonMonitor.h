/*
 * Copyright (c) 2026 Embeddmo
 *
 * This file is part of an example application demonstrating the usage
 * of the Embeddmo EventManager library.
 *
 * The Embeddmo EventManager library is proprietary and is not included in this
 * repository.
 *
 * This example code is provided for demonstration purposes only.
 * Redistribution and modification are permitted with attribution.
 *
 * For more information: https://embeddmo.com
 */
#ifndef _BUTTON_MONITOR_H
#define _BUTTON_MONITOR_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "EventManager.h"

/* Event which is sent when a button press is detected. */
#define EVENT_BUTTON_PRESSED  (0U)
/* Event which is sent when a button release is detected. */
#define EVENT_BUTTON_RELEASED (1U)

/* Example function to check for button press/release. */
void ButtonMonitor_Run(const EventManager_t *const eventManager);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BUTTON_MONITOR_H */
