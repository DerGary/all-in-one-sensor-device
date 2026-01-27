#include "save_config_button.h"

namespace esphome::c4001
{

    void SaveConfigButton::press_action()
    {
        this->parent_->saveConfig();
    }

} // namespace esphome::ld2410