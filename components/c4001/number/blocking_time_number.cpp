#include "blocking_time_number.h"

namespace esphome::c4001
{

    void BlockingTimeNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_blocking_time();
    }

} // namespace esphome::c4001