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
#include <stdio.h>

#include "ButtonMonitor.h"
#include "EventManager.h"

/* Callback function to be called when a button press event is detected.
   It should be as short as possible and it must not be blocking. */
static void ButtonPressCallback(void);
/* Callback function to be called when a button release event is detected.
   It should be as short as possible and it must not be blocking. */
static void ButtonReleaseCallback(void);

int main(void)
{
    int8_t retCode = 0;

    /* Create static buffer for the Event Manager. */
    static EventManagerBuffer_t eventManagerBuffer;
    /* Initialise the Event Manager object. */
    EventManager_t *eventManager = EventManager_Init(&eventManagerBuffer);

    /* Subscribe a callback for button press events. */
    retCode = EventManager_SubscribeCallback(eventManager, EVENT_BUTTON_PRESSED,
                                             &ButtonPressCallback);
    /* Verify if the callback is subscribed successfully. */
    if (retCode == EVENT_MANAGER_ERR_NONE)
    {
        printf("Successfully subscribed for button press events\n");
    }

    /* Subscribe a callback for button release events. */
    retCode = EventManager_SubscribeCallback(eventManager, EVENT_BUTTON_RELEASED,
                                             &ButtonReleaseCallback);
    /* Verify if the callback is subscribed successfully. */
    if (retCode == EVENT_MANAGER_ERR_NONE)
    {
        printf("Successfully subscribed for button release events\n");
    }

    /* Main loop of the application. Exit the loop after 5000 runs. */
    for (uint32_t loopCounter = 0UL; loopCounter < 5000UL; loopCounter++)
    {
        /* Run an example function to check for button press/release. It will send an
           event when any of these is detected. */
        ButtonMonitor_Run(eventManager);
    }

    /* Unsubscribe the callback for button press events. */
    retCode = EventManager_UnsubscribeCallback(eventManager, EVENT_BUTTON_PRESSED,
                                               &ButtonPressCallback);
    /* Verify if the callback is unsubscribed successfully. */
    if (retCode == EVENT_MANAGER_ERR_NONE)
    {
        printf("Successfully unsubscribed for button press events\n");
    }

    /* Unsubscribe the callback for button release events. */
    retCode = EventManager_UnsubscribeCallback(eventManager, EVENT_BUTTON_RELEASED,
                                               &ButtonReleaseCallback);
    /* Verify if the callback is unsubscribed successfully. */
    if (retCode == EVENT_MANAGER_ERR_NONE)
    {
        printf("Successfully unsubscribed for button release events\n");
    }
}

static void ButtonPressCallback(void)
{
    /* EVENT_BUTTON_PRESSED was sent. */
    printf("Button press detected\n");
}

static void ButtonReleaseCallback(void)
{
    /* EVENT_BUTTON_RELEASED was sent. */
    printf("Button release detected\n");
}
