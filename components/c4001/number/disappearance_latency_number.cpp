#include "disappearance_latency_number.h"

namespace esphome::c4001
{

    void DisappearanceLatencyNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_disappearance_latency();
    }

} // namespace esphome::c4001