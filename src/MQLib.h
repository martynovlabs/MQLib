#ifndef MQLIB_H
#define MQLIB_H

#include "MQSensor.h"

// Convenience aliases for MQ5 and MQ7 sensors using typical parameters.
// The constants are based on common datasheet values but may need
// adjustment depending on your setup.

namespace MQLib {

static const float MQ5_RO_CLEAN_AIR_FACTOR = 6.5f;
static const float MQ7_RO_CLEAN_AIR_FACTOR = 27.0f;

class MQ5 : public MQSensor {
public:
    explicit MQ5(uint8_t analogPin)
        : MQSensor(analogPin) {}
};

class MQ7 : public MQSensor {
public:
    explicit MQ7(uint8_t analogPin)
        : MQSensor(analogPin) {}
};

} // namespace MQLib

#endif // MQLIB_H
