/*
 * UltrasonicSensor.hpp
 *
 *  Created on: Oct 17, 2013
 *      Author: liyixiao
 */

#ifndef ULTRASONICSENSOR_HPP_
#define ULTRASONICSENSOR_HPP_

namespace EV3 {

class UltrasonicSensor : UARTSensor {
public:
    UltrasonicSensor(SensorPort port);
};

} /* namespace EV3 */

#endif /* ULTRASONICSENSOR_HPP_ */
