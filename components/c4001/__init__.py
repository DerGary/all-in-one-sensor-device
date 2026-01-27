from esphome import automation
from esphome.automation import maybe_simple_id
import esphome.codegen as cg
from esphome.components import uart
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]
MULTI_CONF = True

c4001_ns = cg.esphome_ns.namespace("c4001")
C4001Component = c4001_ns.class_(
    "C4001Component", cg.Component, uart.UARTDevice
)

CONF_C4001_ID = "c4001_id"
CONF_DISTANCE_MIN = "min_distance"
CONF_DISTANCE_MAX = "max_distance"
CONF_LATENCY_ON = "on_latency"
CONF_LATENCY_OFF = "off_latency"
CONF_TRIGGER_RANGE = "trigger_range"
CONF_SUSTAIN_SENSITIVITY = "sustain_sensitivity"
CONF_TRIGGER_SENSITIVITY = "trigger_sensitivity"

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(C4001Component),
        }
    ).extend(uart.UART_DEVICE_SCHEMA)
    .extend(cv.COMPONENT_SCHEMA)
)

FINAL_VALIDATE_SCHEMA = uart.final_validate_device_schema(
    "c4001",
    require_tx=True,
    require_rx=True,
    parity="NONE",
    stop_bits=1,
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)