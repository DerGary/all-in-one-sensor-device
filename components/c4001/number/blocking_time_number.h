#pragma once

#include "esphome/components/number/number.h"
#include "../c4001.h"

namespace esphome::c4001
{

    class BlockingTimeNumber : public number::Number, public Parented<C4001Component>
    {
    public:
        BlockingTimeNumber() = default;

    protected:
        void control(float value) override;
    };

} // namespace esphome::c4001