/*
   Copyright Beatific Angel
   
 */

#pragma once

struct SipClientEvent
{
    enum class Event
    {
        CALL_START,
        CALL_CANCELLED,
        CALL_END,
        BUTTON_PRESS,
    };

    enum class CancelReason
    {
        UNKNOWN,
        CALL_DECLINED,
        TARGET_BUSY,
    };

    Event event;
    char button_signal = ' ';
    uint16_t button_duration = 0;
    CancelReason cancel_reason = CancelReason::UNKNOWN;
};
