#include "hold_sensitivity_number.h"

namespace esphome::c4001
{

    void HoldSensitivityNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_hold_sensitivity();
    }

} // namespace esphome::c4001