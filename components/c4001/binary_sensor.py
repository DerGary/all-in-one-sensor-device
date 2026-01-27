import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import (
    CONF_HAS_TARGET,
    DEVICE_CLASS_OCCUPANCY,
    ICON_ACCOUNT,
)

from . import CONF_C4001_ID, C4001Component

DEPENDENCIES = ["c4001"]

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_C4001_ID): cv.use_id(C4001Component),
    cv.Optional(CONF_HAS_TARGET): binary_sensor.binary_sensor_schema(
        device_class=DEVICE_CLASS_OCCUPANCY,
        filters=[{"settle": cv.TimePeriod(milliseconds=1000)}],
        icon=ICON_ACCOUNT,
    ),
}


async def to_code(config):
    c4001_component = await cg.get_variable(config[CONF_C4001_ID])
    if has_target_config := config.get(CONF_HAS_TARGET):
        sens = await binary_sensor.new_binary_sensor(has_target_config)
        cg.add(c4001_component.set_target_binary_sensor(sens))