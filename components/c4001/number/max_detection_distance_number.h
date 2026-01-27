#pragma once

#include "esphome/components/number/number.h"
#include "../c4001.h"

namespace esphome::c4001
{

    class MaxDetectionDistanceNumber : public number::Number, public Parented<C4001Component>
    {
    public:
        MaxDetectionDistanceNumber() = default;

    protected:
        void control(float value) override;
    };

} // namespace esphome::c4001