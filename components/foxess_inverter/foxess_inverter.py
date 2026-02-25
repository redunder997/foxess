import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]

foxess_ns = cg.esphome_ns.namespace("foxess")
FoxessComponent = foxess_ns.class_(
    "FoxessComponent", cg.PollingComponent, uart.UARTDevice
)

CONF_UART_ID = "uart_id"

# Optional sensors
SENSOR_TYPES = [
    "grid_power", "generation_power", "loads_power",
    "grid_voltage_r", "grid_current_r", "grid_frequency_r", "grid_power_r",
    "grid_voltage_s", "grid_current_s", "grid_frequency_s", "grid_power_s",
    "grid_voltage_t", "grid_current_t", "grid_frequency_t", "grid_power_t",
    "pv1_voltage", "pv1_current", "pv1_power",
    "pv2_voltage", "pv2_current", "pv2_power",
    "pv3_voltage", "pv3_current", "pv3_power",
    "pv4_voltage", "pv4_current", "pv4_power",
    "boost_temperature", "inverter_temperature", "ambient_temperature",
    "today_yield", "generation_total",
    "inverter_state",
]

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(FoxessComponent),
        cv.Required(CONF_UART_ID): cv.use_id(uart.UARTComponent),
        **{cv.Optional(name): sensor.sensor_schema() for name in SENSOR_TYPES},
    }
).extend(cv.polling_component_schema("10s"))

async def to_code(config):
    uart_component = await cg.get_variable(config[CONF_UART_ID])
    var = cg.new_Pvariable(config[CONF_ID], uart_component)
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)

    for name in SENSOR_TYPES:
        if name in config:
            await sensor.new_sensor(config[name])