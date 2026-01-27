#include "max_detection_distance_number.h"

namespace esphome::c4001
{

    void MaxDetectionDistanceNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_max_detection_distance();
    }

} // namespace esphome::c4001