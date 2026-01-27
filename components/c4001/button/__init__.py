import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    ENTITY_CATEGORY_CONFIG,
    ICON_BRIEFCASE_DOWNLOAD,
)

from .. import CONF_C4001_ID, C4001Component, c4001_ns

SaveConfigButton = c4001_ns.class_("SaveConfigButton", button.Button)

CONF_SAVE_CONFIG = "save_config"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_ID): cv.declare_id(cg.EntityBase),
    cv.GenerateID(CONF_C4001_ID): cv.use_id(C4001Component),
    cv.Optional(CONF_SAVE_CONFIG): button.button_schema(
        SaveConfigButton,
        entity_category=ENTITY_CATEGORY_CONFIG,
        icon=ICON_BRIEFCASE_DOWNLOAD,
    ),
}

async def to_code(config):
    c4001_component = await cg.get_variable(config[CONF_C4001_ID])

    if save_config_config := config.get(CONF_SAVE_CONFIG):
        b = await button.new_button(save_config_config)
        await cg.register_parented(b, config[CONF_C4001_ID])
        cg.add(c4001_component.set_save_config_button(b))