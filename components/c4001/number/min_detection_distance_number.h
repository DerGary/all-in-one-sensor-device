#pragma once

#include "esphome/components/number/number.h"
#include "../c4001.h"

namespace esphome::c4001
{

    class MinDetectionDistanceNumber : public number::Number, public Parented<C4001Component>
    {
    public:
        MinDetectionDistanceNumber() = default;

    protected:
        void control(float value) override;
    };

} // namespace esphome::c4001