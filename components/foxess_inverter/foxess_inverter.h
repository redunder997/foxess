#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "esphome/core/hal.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/number/number.h"
#include "esphome/components/button/button.h"
#include "esphome/components/select/select.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/preferences.h"
#include <vector>

// #include "esphome/components/sensor/sensor.h"
// #include "esphome/core/component.h"
// #include "esphome/core/log.h"
// #include "esphome/components/uart/uart.h"

namespace esphome {
namespace foxess {

class FoxessComponent : public PollingComponent, public uart::UARTDevice {
 public:
  FoxessComponent(uart::UARTComponent *parent)
      : PollingComponent(600), UARTDevice(parent) {}

  // Sensors as pointers
  sensor::Sensor *grid_power{nullptr};
  sensor::Sensor *generation_power{nullptr};
  sensor::Sensor *loads_power{nullptr};

  sensor::Sensor *grid_voltage_r{nullptr};
  sensor::Sensor *grid_current_r{nullptr};
  sensor::Sensor *grid_frequency_r{nullptr};
  sensor::Sensor *grid_power_r{nullptr};

  sensor::Sensor *grid_voltage_s{nullptr};
  sensor::Sensor *grid_current_s{nullptr};
  sensor::Sensor *grid_frequency_s{nullptr};
  sensor::Sensor *grid_power_s{nullptr};

  sensor::Sensor *grid_voltage_t{nullptr};
  sensor::Sensor *grid_current_t{nullptr};
  sensor::Sensor *grid_frequency_t{nullptr};
  sensor::Sensor *grid_power_t{nullptr};

  sensor::Sensor *pv1_voltage{nullptr};
  sensor::Sensor *pv1_current{nullptr};
  sensor::Sensor *pv1_power{nullptr};

  sensor::Sensor *pv2_voltage{nullptr};
  sensor::Sensor *pv2_current{nullptr};
  sensor::Sensor *pv2_power{nullptr};

  sensor::Sensor *pv3_voltage{nullptr};
  sensor::Sensor *pv3_current{nullptr};
  sensor::Sensor *pv3_power{nullptr};

  sensor::Sensor *pv4_voltage{nullptr};
  sensor::Sensor *pv4_current{nullptr};
  sensor::Sensor *pv4_power{nullptr};

  sensor::Sensor *boost_temperature{nullptr};
  sensor::Sensor *inverter_temperature{nullptr};
  sensor::Sensor *ambient_temperature{nullptr};

  sensor::Sensor *today_yield{nullptr};
  sensor::Sensor *generation_total{nullptr};

  sensor::Sensor *inverter_state{nullptr};

  void setup() override;
  void update() override;

 private:
  unsigned long millis_lastmessage{0};
  const long inverter_timeout{300000};
  int inverter_mode{99};
  std::vector<uint8_t> bytes;

  typedef union {
    uint8_t Byte[2];
    int16_t Int16;
    uint16_t UInt16;
  } TwoByte;
};

}  // namespace foxess
}  // namespace esphome