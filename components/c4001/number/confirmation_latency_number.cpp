#include "confirmation_latency_number.h"

namespace esphome::c4001
{

    void ConfirmationLatencyNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_confirmation_latency();
    }

} // namespace esphome::c4001