#pragma once

#include "esphome/components/number/number.h"
#include "../c4001.h"

namespace esphome::c4001
{

    class MaxTriggerDistanceNumber : public number::Number, public Parented<C4001Component>
    {
    public:
        MaxTriggerDistanceNumber() = default;

    protected:
        void control(float value) override;
    };

} // namespace esphome::c4001