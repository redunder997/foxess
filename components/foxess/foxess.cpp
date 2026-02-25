#include "foxess.h"

namespace esphome {
namespace foxess {

static const char *TAG = "foxess";

void FoxessComponent::setup() {
  ESP_LOGI(TAG, "FoxESS component setup, pointer = %p", this);
  if (inverter_state)
    ESP_LOGI(TAG, "inverter_state sensor pointer = %p", inverter_state);
}

void FoxessComponent::update() {
  // Example: publish dummy states if sensors exist
  if (grid_power)
    grid_power->publish_state(123.4);
  if (generation_power)
    generation_power->publish_state(567.8);
}

}  // namespace foxess
}  // namespace esphome