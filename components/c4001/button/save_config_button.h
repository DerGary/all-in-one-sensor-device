#pragma once

#include "esphome/components/button/button.h"
#include "../c4001.h"

namespace esphome::c4001
{

    class SaveConfigButton : public button::Button, public Parented<C4001Component>
    {
    public:
        SaveConfigButton() = default;

    protected:
        void press_action() override;
    };

} // namespace esphome::c4001