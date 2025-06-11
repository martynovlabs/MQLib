# MQLib

Simple Arduino library for MQ gas sensors. This repository now contains a
minimal implementation that allows working with MQ5 and MQ7 sensors.

## Features

- Basic calibration routine to obtain `Ro` in clean air.
- Reading sensor resistance and estimating gas concentration using a
  logarithmic curve.
- Convenience classes `MQLib::MQ5` and `MQLib::MQ7` for common sensors.

## Usage

```cpp
#include <MQLib.h>

MQLib::MQ5 mq5(A0);

void setup() {
  Serial.begin(9600);
  mq5.calibrate();
}

void loop() {
  float ratio = mq5.readRatio();
  Serial.println(ratio);
  delay(1000);
}
```

Adjust the calibration and curve parameters according to your application.
