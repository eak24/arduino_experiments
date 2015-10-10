/*
//
// Created by Ethan Keller on 10/10/15.
//

#ifndef ARDUINOEXPERIMENTATION1_DS2321_H
#define ARDUINOEXPERIMENTATION1_DS2321_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


// Uncomment to enable printing out nice debug messages.
//#define DHT_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef DS2321_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
  #define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

class DS2321 {
public:
    DS2321(uint8_t pin, uint8_t type, uint8_t count=6);
    void begin(void);
    float readTemperature(bool S=false, bool force=false);
    float convertCtoF(float);
    float convertFtoC(float);
    float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=true);
    float readHumidity(bool force=false);
    boolean read(bool force=false);

private:
    uint8_t data[5];
    uint8_t _pin, _type, _bit, _port;
    uint32_t _lastreadtime, _maxcycles;
    bool _lastresult;

    uint32_t expectPulse(bool level);

};

class InterruptLock {
public:
    InterruptLock() {
        noInterrupts();
    }
    ~InterruptLock() {
        interrupts();
    }

};

#endif
*/
