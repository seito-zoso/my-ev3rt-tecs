/*
 * Sensor.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: liyixiao
 */

#include "ev3api__Sensor.hpp"

#include <kernel.h>
#include <t_syslog.h>

namespace EV3 {

Sensor::Sensor(SensorPort port) : _port(port) {
    assert(port >= Port1 && port < TNUM_SENSOR);
    assert(ev3->_sensors[port] == NULL);

    ev3->_sensors[port] = this;
}

}
