/*
 * Sensor.hpp
 *
 *  Created on: Oct 9, 2013
 *      Author: liyixiao
 */

#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include "EV3.hpp"

namespace EV3 {

class Sensor {
public:
    Sensor(SensorPort port);

protected:
    SensorPort _port;
};

}

#endif /* SENSOR_HPP_ */
