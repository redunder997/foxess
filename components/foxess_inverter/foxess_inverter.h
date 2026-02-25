#pragma once
#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace foxess {

class FoxessComponent : public PollingComponent, public esphome::uart::UARTDevice {
 public:
  FoxessComponent(uart::UARTComponent *parent)
      : PollingComponent(600), UARTDevice(parent) {}

  // ===== Sensors =====
  esphome::sensor::Sensor *grid_power{nullptr};
  esphome::sensor::Sensor *generation_power{nullptr};
  esphome::sensor::Sensor *loads_power{nullptr};

  esphome::sensor::Sensor *grid_voltage_r{nullptr};
  esphome::sensor::Sensor *grid_current_r{nullptr};
  esphome::sensor::Sensor *grid_frequency_r{nullptr};
  esphome::sensor::Sensor *grid_power_r{nullptr};

  esphome::sensor::Sensor *grid_voltage_s{nullptr};
  esphome::sensor::Sensor *grid_current_s{nullptr};
  esphome::sensor::Sensor *grid_frequency_s{nullptr};
  esphome::sensor::Sensor *grid_power_s{nullptr};

  esphome::sensor::Sensor *grid_voltage_t{nullptr};
  esphome::sensor::Sensor *grid_current_t{nullptr};
  esphome::sensor::Sensor *grid_frequency_t {nullptr};
  esphome::sensor::Sensor *grid_power_t{nullptr};

  esphome::sensor::Sensor *pv1_voltage{nullptr};
  esphome::sensor::Sensor *pv1_current{nullptr};
  esphome::sensor::Sensor *pv1_power{nullptr};

  esphome::sensor::Sensor *pv2_voltage{nullptr};
  esphome::sensor::Sensor *pv2_current{nullptr};
  esphome::sensor::Sensor *pv2_power{nullptr};

  esphome::sensor::Sensor *pv3_voltage{nullptr};
  esphome::sensor::Sensor *pv3_current{nullptr};
  esphome::sensor::Sensor *pv3_power{nullptr};

  esphome::sensor::Sensor *pv4_voltage{nullptr};
  esphome::sensor::Sensor *pv4_current{nullptr};
  esphome::sensor::Sensor *pv4_power{nullptr};

  esphome::sensor::Sensor *boost_temperature{nullptr};
  esphome::sensor::Sensor *inverter_temperature{nullptr};
  esphome::sensor::Sensor *ambient_temperature{nullptr};

  esphome::sensor::Sensor *today_yield{nullptr};
  esphome::sensor::Sensor *generation_total{nullptr};

 esphome::sensor::Sensor *inverter_state{nullptr};

  void setup() override;
  void update() override;

 private:
  unsigned long millis_lastmessage = 0;
  const long inverter_timeout = 300000;
  int inverter_mode = 99;

  std::vector<uint8_t> bytes;

  typedef union {
    uint8_t Byte[2];
    int16_t Int16;
    uint16_t UInt16;
  } TwoByte;
};

}  
}