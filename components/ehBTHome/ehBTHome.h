/******
 *
 * ehBTHome
 *
 * https://bthome.io/
 *
 * https://bthome.io/format/
 *
 * https://bthome.io/encryption/
 *
 */

#include "Arduino.h"

// BLE includes
#include "NimBLEDevice.h"

// Esphome logs and components
#include "esphome/core/log.h"
#include "esphome/core/component.h"

#include "BTHome.h"

namespace esphome {
	namespace BTHomeAdv {
		class ehBTHome : public BTHome, public Component {
		public:
 			// Set encryption key as per Esphome component "passkey"
			void set_passkey(const char *data);

 			// Esphome component override functions
			void setup() override;
			void loop() override;
			void dump_config() override;

		private:
			String dev_name;
		};
	}
}
