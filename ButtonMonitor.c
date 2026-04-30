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
#include "ButtonMonitor.h"

void ButtonMonitor_Run(const EventManager_t *const eventManager)
{
    /* Counts how many times the function has been executed. */
    static uint32_t runCounter = 0UL;

    runCounter++;

    /* If the function is called 1000 times, simulate a button press, by sending the
       corresponding event. */
    if (runCounter == 1000UL)
    {
        EventManager_Notify(eventManager, EVENT_BUTTON_PRESSED);
    }

    /* If the function is called 2000 times, simulate a button release, by sending the
       corresponding event. */
    if (runCounter == 2000UL)
    {
        EventManager_Notify(eventManager, EVENT_BUTTON_RELEASED);
    }
}
