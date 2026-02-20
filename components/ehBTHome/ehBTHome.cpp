#include "ehBTHome.h"

#define DEVICE_NAME "ESP32-BT"  // The name of the sensor

namespace esphome {
	namespace BTHomeAdv {
		static const char *TAG = "BLE BTHome component";
		static char passKey[BIND_KEY_LEN * 2 + 1] = {};

		/*
		 * // Esphome component override functions
		 * void setup() override;
		 * void loop() override;
		 * void dump_config() override;
		 */
		void ehBTHome::setup() {
			begin(dev_name.length() ? dev_name : DEVICE_NAME,
				true,
				passKey,
				false);

			BLEDevice::setPower(ESP_PWR_LVL_P9);

			ESP_LOGCONFIG(TAG, "BTHome device: %s", dev_name.c_str());
		}

		void ehBTHome::loop() {}

		void ehBTHome::dump_config() {
		    ESP_LOGCONFIG(TAG, "ehBTHome Component");
		}

		// Set encryption key as per Esphome component "passkey"
		void ehBTHome::set_passkey(const  char *data) {
		        memcpy(passKey, data, BIND_KEY_LEN * 2);
		}


	}
}
