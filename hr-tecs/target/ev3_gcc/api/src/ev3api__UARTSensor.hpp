/*
 * UARTSensor.hpp
 *
 *  Created on: Oct 17, 2013
 *      Author: liyixiao
 */

#ifndef UARTSENSOR_HPP_
#define UARTSENSOR_HPP_

#include "ev3api__Sensor.hpp"

namespace EV3 {

class UARTSensor: Sensor {
public:
    UARTSensor(SensorPort port);
};

} /* namespace EV3 */

#endif /* UARTSENSOR_HPP_ */
