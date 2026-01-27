#include "c4001.h"
#include "esphome/core/application.h"

namespace esphome::c4001
{
    static const char *const TAG = "c4001";

    void C4001Component::dump_config()
    {
        ESP_LOGCONFIG(TAG, "C4001:");
#ifdef USE_BINARY_SENSOR
        ESP_LOGCONFIG(TAG, "Binary Sensors:");
        LOG_BINARY_SENSOR("  ", "Target", this->target_binary_sensor_);
#endif
#ifdef USE_NUMBER
        ESP_LOGCONFIG(TAG, "Numbers:");
        LOG_NUMBER("  ", "Blocking Time", this->blocking_time_number_);
        LOG_NUMBER("  ", "Confirmation Latency", this->confirmation_latency_number_);
        LOG_NUMBER("  ", "Disappearance Latency", this->disappearance_latency_number_);
        LOG_NUMBER("  ", "Hold Sensitivity", this->hold_sensitivity_number_);
        LOG_NUMBER("  ", "Trigger Sensitivity", this->trigger_sensitivity_number_);
        LOG_NUMBER("  ", "Max Detection Distance", this->max_detection_distance_number_);
        LOG_NUMBER("  ", "Min Detection Distance", this->min_detection_distance_number_);
        LOG_NUMBER("  ", "Max Trigger Distance", this->max_trigger_distance_number_);
#endif
#ifdef USE_BUTTON
        ESP_LOGCONFIG(TAG, "Buttons:");
        LOG_BUTTON("  ", "Save Config", this->save_config_button_);
#endif
    }

    void C4001Component::setup()
    {
        delay(1000); // documentation says that after 1 second of powering on the sensor we can read data from it

        buffer_data.reserve(64); // reserve some space for our buffer

        ESP_LOGI(TAG, "starting setup");

        ESP_LOGI(TAG, "stopping sensor");
        this->write_str(STOP_SENSOR);
        waitForDoneOr(false);

        readConfig();

        ESP_LOGI(TAG, "start sensor");
        this->write_str(START_SENSOR);
        waitForDoneOr(false);
    }

    void C4001Component::saveConfig()
    {
        ESP_LOGI(TAG, "start saving Config");
        ESP_LOGI(TAG, "stopping sensor");
        this->write_str(STOP_SENSOR);
        waitForDoneOr(false);

        setConfig(EXIST_MODE);
        std::string cmd;
#ifdef USE_NUMBER
        if (this->max_detection_distance_number_->has_state() && this->min_detection_distance_number_->has_state())
        {
            cmd = str_sprintf("%s %.1f %.1f", SET_RANGE, this->min_detection_distance_number_->state, this->max_detection_distance_number_->state);
            setConfig(cmd.c_str());
        }
        if (this->max_trigger_distance_number_->has_state())
        {
            cmd = str_sprintf("%s %.1f", SET_TRIGGER_RANGE, this->max_trigger_distance_number_->state);
            setConfig(cmd.c_str());
        }
        if (this->hold_sensitivity_number_->has_state() && this->trigger_sensitivity_number_->has_state())
        {
            cmd = str_sprintf("%s %d %d", SET_SENSITIVITY, (uint8_t)this->hold_sensitivity_number_->state, (uint8_t)this->trigger_sensitivity_number_->state);
            setConfig(cmd.c_str());
        }
        if (this->confirmation_latency_number_->has_state() && this->disappearance_latency_number_->has_state())
        {
            cmd = str_sprintf("%s %.3f %.3f", SET_LATENCY, this->confirmation_latency_number_->state, this->disappearance_latency_number_->state);
            setConfig(cmd.c_str());
        }
        if (this->blocking_time_number_->has_state())
        {
            cmd = str_sprintf("%s %.1f", SET_INHIBIT, this->blocking_time_number_->state);
            setConfig(cmd.c_str());
        }
#endif

        // this is not documented
        // disable target output
        cmd = str_sprintf("%s %d %d", SET_UART_OUTPUT, 2, 0);
        setConfig(cmd.c_str());

        // this is not documented
        // enable presence output
        cmd = str_sprintf("%s %d %d", SET_UART_OUTPUT, 1, 1);
        setConfig(cmd.c_str());

        ESP_LOGI(TAG, "save config");
        this->write_str(SAVE_CONFIG);
        waitForDoneOr(true);

        ESP_LOGI(TAG, "start sensor");
        this->write_str(START_SENSOR);
        waitForDoneOr(false);
    }

    void C4001Component::setConfig(const char *config)
    {
        ESP_LOGI(TAG, "setting config: %s", config);
        this->write_str(config);
        waitForDoneOr(false);
    }

    void C4001Component::readConfig()
    {
        std::vector<std::string> result;
#ifdef USE_NUMBER
        result = queryConfig(GET_RANGE);
        if (result.size() == 2)
        {
            auto min = parse_number<float>(result[0]);
            if (min.has_value())
            {
                this->min_detection_distance_number_->publish_state(min.value_or(0));
            }
            auto max = parse_number<float>(result[1]);
            if (max.has_value())
            {
                this->max_detection_distance_number_->publish_state(max.value_or(0));
            }
        }
        else
        {
            ESP_LOGE(TAG, "Error getting max/min detection distance config");
        }
        result = queryConfig(GET_TRIGGER_RANGE);
        if (result.size() == 1)
        {
            auto val = parse_number<float>(result[0]);
            if (val.has_value())
            {
                this->max_trigger_distance_number_->publish_state(val.value_or(0));
            }
        }
        else
        {
            ESP_LOGE(TAG, "Error getting trigger range config");
        }
        result = queryConfig(GET_SENSITIVITY);
        if (result.size() == 2)
        {
            auto hold = parse_number<float>(result[0]);
            auto trigger = parse_number<float>(result[1]);
            if (hold.has_value())
            {
                this->hold_sensitivity_number_->publish_state(hold.value_or(0));
            }
            if (trigger.has_value())
            {
                this->trigger_sensitivity_number_->publish_state(trigger.value_or(0));
            }
        }
        else
        {
            ESP_LOGE(TAG, "Error getting sensitivity config");
        }
        result = queryConfig(GET_LATENCY);
        if (result.size() == 2)
        {
            auto confirmation = parse_number<float>(result[0]);
            auto disappearance = parse_number<float>(result[1]);
            if (confirmation.has_value())
            {
                this->confirmation_latency_number_->publish_state(confirmation.value_or(0));
            }
            if (disappearance.has_value())
            {
                this->disappearance_latency_number_->publish_state(disappearance.value_or(0));
            }
        }
        else
        {
            ESP_LOGE(TAG, "Error getting latency config");
        }
        result = queryConfig(GET_INHIBIT);
        if (result.size() == 1)
        {
            auto val = parse_number<float>(result[0]);
            if (val.has_value())
            {
                this->blocking_time_number_->publish_state(val.value_or(0));
            }
        }
        else
        {
            ESP_LOGE(TAG, "Error getting blocking time config");
        }
#endif
    }

    std::vector<std::string> C4001Component::queryConfig(const char *config)
    {
        ESP_LOGI(TAG, "query config: %s", config);
        this->write_str(config);
        return waitForResponse();
    }

    std::vector<std::string> C4001Component::waitForResponse()
    {
        bool done = false;
        bool response = false;
        std::vector<std::string> result;
        do
        {
            if (!readLine(read()))
            {
                continue;
            }

            std::string line = getLineWithoutCRLF();
            if (line.find(RESPONSE) == 0)
            {
                ESP_LOGV(TAG, "Found Response %s", line.c_str());
                response = true;
                result = split(line, ' ');
                if (!result.empty())
                {
                    result.erase(result.begin());
                }
                for (uint8_t i = 0; i < result.size(); i++)
                {
                    ESP_LOGV(TAG, "Response Value %d %s", i, result[i].c_str());
                }
            }
            if (line.find(DONE) == 0 && response)
            {
                done = true;
            }
            if (line.find(ERROR) == 0)
            {
                ESP_LOGE(TAG, "Encountered Error while waiting for response from C4001 Sensor");
            }
        } while (!done);
        return result;
    }

    void C4001Component::waitForDoneOr(bool error)
    {
        bool done = false;
        do
        {
            if (!readLine(read()))
            {
                continue;
            }

            std::string line = getLineWithoutCRLF();
            if (line.find(DONE) == 0)
            {
                done = true;
            }
            if (line.find(ERROR) == 0)
            {
                if (error)
                {
                    done = true;
                }
                else
                {
                    ESP_LOGE(TAG, "Encountered Error while waiting for response from C4001 Sensor");
                }
            }
        } while (!done);
    }

    std::vector<std::string> C4001Component::split(const std::string &s, char delim)
    {
        std::vector<std::string> result;
        uint8_t startIndex = 0;
        for (uint8_t i = 0; i < s.size(); i++)
        {
            if (s[i] == delim)
            {
                result.push_back(s.substr(startIndex, i - startIndex));
                startIndex = ++i;
            }
        }
        result.push_back(s.substr(startIndex, s.size() - startIndex));

        return result;
    }

    void C4001Component::loop()
    {
        while (available())
        {
            if (readLine(read()))
            {
                interpretLine(getLineWithoutCRLF());
            }
        }
    }

    bool C4001Component::readLine(int readch)
    {
        if (readch < 0)
        {
            return false; // no data
        }

        buffer_data.push_back(readch);
        if (buffer_data.size() < 2)
        {
            return false; // not enough data to interpret
        }

        int lastChar = buffer_data.size() - 1;
        if (buffer_data[lastChar - 1] != '\r' || buffer_data[lastChar] != '\n')
        {
            return false; // line ending not reached
        }

        if (buffer_data.size() == 2)
        {
            buffer_data.clear();
            return false; // empty line
        }
        ESP_LOGV(TAG, "UART: %s", reinterpret_cast<const char *>(buffer_data.data()));
        return true;
    }

    std::string C4001Component::getLineWithoutCRLF()
    {
        std::string msg(
            reinterpret_cast<const char *>(buffer_data.data()),
            buffer_data.size() - 2);
        buffer_data.clear();
        return msg;
    }

    void C4001Component::interpretLine(std::string line)
    {
        std::vector<std::string> result;
        if (line.find("$DFHPD") == 0) // presence mode
        {
            result = split(line, ',');
            ESP_LOGV(TAG, "Encountered Data Package Presence Mode");
            if (result[1] == "0")
            {
                ESP_LOGI(TAG, "No one present");
#ifdef USE_BINARY_SENSOR
                this->target_binary_sensor_->publish_state(false);
#endif
            }
            else if (result[1] == "1")
            {
                ESP_LOGI(TAG, "Someone present");
#ifdef USE_BINARY_SENSOR
                this->target_binary_sensor_->publish_state(true);
#endif
            }
        }
        if (line.find("$DFDMD") == 0) // distance and speed mode
        {
            ESP_LOGW(TAG, "Encountered Data Package Distance and Speed Mode, which is currently not supported by this library");
        }
    }
}