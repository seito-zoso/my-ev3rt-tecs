
/*
 * UARTSensor.cpp
 *
 *  Created on: Oct 17, 2013
 *      Author: liyixiao
 */

extern "C" {
#include "d_uart.h"
}
#include "../ev3api__UARTSensor.hpp"

namespace EV3 {

UARTSensor::UARTSensor(SensorPort port) : Sensor(port) {
    config_uart_sensor(port, 0);
}

} /* namespace EV3 */
