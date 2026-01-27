import esphome.codegen as cg
from esphome.components import number
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_DISTANCE,
    DEVICE_CLASS_PRESENCE,
    ENTITY_CATEGORY_CONFIG,
    ICON_GAUGE,
    UNIT_SECOND,
    UNIT_METER,
)

from .. import CONF_C4001_ID, C4001Component, c4001_ns

MinDetectionDistanceNumber = c4001_ns.class_("MinDetectionDistanceNumber", number.Number)
MaxDetectionDistanceNumber = c4001_ns.class_("MaxDetectionDistanceNumber", number.Number)
MaxTriggerDistanceNumber = c4001_ns.class_("MaxTriggerDistanceNumber", number.Number)
HoldSensitivityNumber = c4001_ns.class_("HoldSensitivityNumber", number.Number)
TriggerSensitivityNumber = c4001_ns.class_("TriggerSensitivityNumber", number.Number)
ConfirmationLatencyNumber = c4001_ns.class_("ConfirmationLatencyNumber", number.Number)
DisappearanceLatencyNumber = c4001_ns.class_("DisappearanceLatencyNumber", number.Number)
BlockingTimeNumber = c4001_ns.class_("BlockingTimeNumber", number.Number)


CONF_MIN_DETECTION_DISTANCE = "min_detection_distance"
CONF_MAX_DETECTION_DISTANCE = "max_detection_distance"
CONF_MAX_TRIGGER_DISTANCE = "max_trigger_distance"
CONF_HOLD_SENSITIVITY = "hold_sensitivity"
CONF_TRIGGER_SENSITIVITY = "trigger_sensitivity"
CONF_CONFIRMATION_LATENCY = "confirmation_latency"
CONF_DISAPPEARANCE_LATENCY = "disappearance_latency"
CONF_BLOCKING_TIME = "blocking_time"
ICON_MAP_MARKER_DISTANCE = "mdi:map-marker-distance"
ICON_TIMER = "mdi:timer-cog-outline"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_ID): cv.declare_id(cg.EntityBase),
        cv.GenerateID(CONF_C4001_ID): cv.use_id(C4001Component),
        cv.Optional(CONF_MIN_DETECTION_DISTANCE): number.number_schema(
            MinDetectionDistanceNumber,
            unit_of_measurement=UNIT_METER,
            device_class=DEVICE_CLASS_DISTANCE,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_MAP_MARKER_DISTANCE,
        ),
        cv.Optional(CONF_MAX_DETECTION_DISTANCE): number.number_schema(
            MaxDetectionDistanceNumber,
            unit_of_measurement=UNIT_METER,
            device_class=DEVICE_CLASS_DISTANCE,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_MAP_MARKER_DISTANCE,
        ),
        cv.Optional(CONF_MAX_TRIGGER_DISTANCE): number.number_schema(
            MaxTriggerDistanceNumber,
            unit_of_measurement=UNIT_METER,
            device_class=DEVICE_CLASS_DISTANCE,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_MAP_MARKER_DISTANCE,
        ),
        
        cv.Optional(CONF_HOLD_SENSITIVITY): number.number_schema(
            HoldSensitivityNumber,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_GAUGE,
        ),
        cv.Optional(CONF_TRIGGER_SENSITIVITY): number.number_schema(
            TriggerSensitivityNumber,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_GAUGE,
        ),

        
        cv.Optional(CONF_CONFIRMATION_LATENCY): number.number_schema(
            ConfirmationLatencyNumber,
            unit_of_measurement=UNIT_SECOND,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_TIMER,
        ),
        cv.Optional(CONF_DISAPPEARANCE_LATENCY): number.number_schema(
            DisappearanceLatencyNumber,
            unit_of_measurement=UNIT_SECOND,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_TIMER,
        ),
        cv.Optional(CONF_BLOCKING_TIME): number.number_schema(
            BlockingTimeNumber,
            unit_of_measurement=UNIT_SECOND,
            entity_category=ENTITY_CATEGORY_CONFIG,
            icon=ICON_TIMER,
        ),
    }
)


async def to_code(config):
    c4001_component = await cg.get_variable(config[CONF_C4001_ID])


    if min_detection_distance := config.get(CONF_MIN_DETECTION_DISTANCE):
        n = await number.new_number(
            min_detection_distance, min_value=0.6, max_value=25, step=0.1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_min_detection_distance_number(n))

    if max_detection_distance := config.get(CONF_MAX_DETECTION_DISTANCE):
        n = await number.new_number(
            max_detection_distance, min_value=0.7, max_value=25, step=0.1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_max_detection_distance_number(n))

    if max_trigger_distance := config.get(CONF_MAX_TRIGGER_DISTANCE):
        n = await number.new_number(
            max_trigger_distance, min_value=0.0, max_value=25, step=0.1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_max_trigger_distance_number(n))

    if hold_sensitivity := config.get(CONF_HOLD_SENSITIVITY):
        n = await number.new_number(
            hold_sensitivity, min_value=0, max_value=9, step=1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_hold_sensitivity_number(n))

    if trigger_sensitivity := config.get(CONF_TRIGGER_SENSITIVITY):
        n = await number.new_number(
            trigger_sensitivity, min_value=0, max_value=9, step=1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_trigger_sensitivity_number(n))

    if confirmation_latency := config.get(CONF_CONFIRMATION_LATENCY):
        n = await number.new_number(
            confirmation_latency, min_value=0, max_value=100, step=0.001
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_confirmation_latency_number(n))

    if disappearance_latency := config.get(CONF_DISAPPEARANCE_LATENCY):
        n = await number.new_number(
            disappearance_latency, min_value=0, max_value=100, step=1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_disappearance_latency_number(n))

    if blocking_time := config.get(CONF_BLOCKING_TIME):
        n = await number.new_number(
            blocking_time, min_value=0.1, max_value=255, step=0.1
        )
        await cg.register_parented(n, config[CONF_C4001_ID])
        cg.add(c4001_component.set_blocking_time_number(n))
