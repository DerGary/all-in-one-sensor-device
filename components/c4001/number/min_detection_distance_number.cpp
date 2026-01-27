#include "min_detection_distance_number.h"

namespace esphome::c4001
{

    void MinDetectionDistanceNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_min_detection_distance();
    }

} // namespace esphome::c4001