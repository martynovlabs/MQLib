#include "MQSensor.h"

MQSensor::MQSensor(uint8_t analogPin, float rl, float adcResolution)
    : _analogPin(analogPin), _rl(rl), _ro(10.0f), _adcResolution(adcResolution) {}

void MQSensor::setRO(float ro) { _ro = ro; }

float MQSensor::getRO() const { return _ro; }

float MQSensor::calibrate(uint8_t samples, unsigned long intervalMs) {
    float rs = 0.0f;
    for (uint8_t i = 0; i < samples; ++i) {
        rs += readResistance();
        delay(intervalMs);
    }
    _ro = rs / samples;
    return _ro;
}

int MQSensor::readRaw() const { return analogRead(_analogPin); }

float MQSensor::readResistance() const {
    int raw = readRaw();
    if (raw == 0) raw = 1; // prevent division by zero
    return (_adcResolution - raw) * _rl / raw;
}

float MQSensor::readRatio() const {
    if (_ro == 0) return 0;
    return readResistance() / _ro;
}

float MQSensor::readPPM(float a, float b) const {
    float ratio = readRatio();
    if (ratio <= 0) return 0;
    float logPPM = a * log10(ratio) + b;
    return pow(10, logPPM);
}
