############################
#
# Massimiliano Pinto 2024
#
# massimiliano.pinto@gmail.com
#
# BTHome component class for ESPHome, configuration
# 

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

empty_component_ns = cg.esphome_ns.namespace('BTHomeAdv')
EmptyComponent = empty_component_ns.class_('ehBTHome', cg.Component)

def validate_key_len(value):
    if len(value) != 32 :
        raise cv.Invalid(f"'passkey' should be 32 chars")
    return value

CONF_PASSKEY = "passkey"
CONF_DEVICE_NAME = "device_name"
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(EmptyComponent),
    cv.Required(CONF_PASSKEY): validate_key_len,
    cv.Optional(CONF_DEVICE_NAME) : cv.string,
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    cg.add(var.set_passkey(config[CONF_PASSKEY]))
    cg.add(var.setDeviceName(config[CONF_DEVICE_NAME]))
    yield cg.register_component(var, config)

