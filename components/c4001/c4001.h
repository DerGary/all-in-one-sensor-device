#pragma once

#include "esphome/core/defines.h"
#include "esphome/core/component.h"
#ifdef USE_BINARY_SENSOR
#include "esphome/components/binary_sensor/binary_sensor.h"
#endif
#ifdef USE_BUTTON
#include "esphome/components/button/button.h"
#endif
#ifdef USE_NUMBER
#include "esphome/components/number/number.h"
#endif
#include "esphome/components/uart/uart.h"
#include "esphome/core/helpers.h"
#include <vector>

#define START_SENSOR "sensorStart"
#define STOP_SENSOR "sensorStop"
#define SAVE_CONFIG "saveConfig"
#define RECOVER_SENSOR "resetCfg"  ///< factory data reset
#define RESET_SENSOR "resetSystem" ///< RESET_SENSOR
#define SPEED_MODE "setRunApp 1"
#define EXIST_MODE "setRunApp 0"
#define SET_RANGE "setRange"
#define GET_RANGE "getRange"
#define SET_TRIGGER_RANGE "setTrigRange"
#define GET_TRIGGER_RANGE "getTrigRange"
#define SET_SENSITIVITY "setSensitivity"
#define GET_SENSITIVITY "getSensitivity"
#define SET_LATENCY "setLatency"
#define GET_LATENCY "getLatency"
#define SET_INHIBIT "setInhibit"
#define GET_INHIBIT "getInhibit"
#define SET_UART_OUTPUT "setUartOutput"
#define DONE "Done"
#define ERROR "Error"
#define RESPONSE "Response"
#define SET_LED_MODE "setLedMode"

namespace esphome::c4001
{

  class C4001Component : public Component, public uart::UARTDevice
  {
#ifdef USE_BINARY_SENSOR
    SUB_BINARY_SENSOR(target)
#endif
#ifdef USE_NUMBER
    SUB_NUMBER(blocking_time)
    SUB_NUMBER(confirmation_latency)
    SUB_NUMBER(disappearance_latency)
    SUB_NUMBER(hold_sensitivity)
    SUB_NUMBER(trigger_sensitivity)
    SUB_NUMBER(max_detection_distance)
    SUB_NUMBER(min_detection_distance)
    SUB_NUMBER(max_trigger_distance)
#endif
#ifdef USE_BUTTON
    SUB_BUTTON(save_config)
#endif
    std::vector<uint8_t> buffer_data;

  public:
    void setup() override;
    void dump_config() override;
    void loop() override;
    bool readLine(int readch);
    void interpretLine(std::string line);
    std::string getLineWithoutCRLF();
    bool waitForDoneOr(bool error, uint32_t timeout_ms = 2000);
    void setConfig(const char *config);
    std::vector<std::string> queryConfig(const char *config);
    std::vector<std::string> waitForResponse(uint32_t timeout_ms = 2000);
    std::vector<std::string> split(const std::string &s, char delim);
    void saveConfig();
    void readConfig();
  };
} // namespace esphome::c4001
