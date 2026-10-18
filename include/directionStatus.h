#ifndef DIRECTION_STATUS_H
#define DIRECTION_STATUS_H

#include <stdint.h>

// Display freshness only; this does not change PDC motor-control behavior
constexpr uint32_t PDC_DIRECTION_STATUS_TIMEOUT_MS = 500;

inline const char* directionStatusText(bool status_received, uint32_t last_received_ms,
                                      uint32_t current_time_ms, bool commanded_reverse,
                                      bool requested_reverse) {
    if (!status_received || uint32_t(current_time_ms - last_received_ms) > PDC_DIRECTION_STATUS_TIMEOUT_MS) {
        return "Direction unavailable";
    }
    if (commanded_reverse != requested_reverse) {
        return commanded_reverse ? "Rev -> Fwd requested" : "Fwd -> Rev requested";
    }
    return commanded_reverse ? "Rev" : "Fwd";
}

#endif
