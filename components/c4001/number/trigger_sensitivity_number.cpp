#include "trigger_sensitivity_number.h"

namespace esphome::c4001
{

    void TriggerSensitivityNumber::control(float value)
    {
        this->publish_state(value);
        // this->parent_->set_trigger_sensitivity();
    }

} // namespace esphome::c4001