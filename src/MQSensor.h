#ifndef MQLIB_MQSENSOR_H
#define MQLIB_MQSENSOR_H

#include <Arduino.h>

class MQSensor {
public:
    MQSensor(uint8_t analogPin, float rl = 10.0f, float adcResolution = 1023.0f);

    void setRO(float ro);
    float getRO() const;

    // Calibrates sensor in clean air and stores Ro. Returns calculated Ro.
    float calibrate(uint8_t samples = 10, unsigned long intervalMs = 50);

    // Reads raw ADC value from the analog pin.
    int readRaw() const;

    // Reads sensor resistance Rs using current ADC value.
    float readResistance() const;

    // Reads Rs/Ro ratio using current ADC value.
    float readRatio() const;

    // Estimates gas concentration in PPM using given slope (a) and intercept (b)
    // with formula: log10(ppm) = a * log10(Rs/Ro) + b
    float readPPM(float a, float b) const;

private:
    uint8_t _analogPin;
    float _rl; // load resistance in kilo ohms
    float _ro; // sensor resistance in clean air
    float _adcResolution;
};

#endif // MQLIB_MQSENSOR_H
