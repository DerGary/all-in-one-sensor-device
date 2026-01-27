#include "max_trigger_distance_number.h"

namespace esphome::c4001
{

    void MaxTriggerDistanceNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_max_trigger_distance();
    }

} // namespace esphome::c4001