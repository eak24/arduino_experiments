//
// Created by Ethan Keller on 10/11/15.
//

#ifndef ARDUINOEXPERIMENTATION1_DS2321_H
#define ARDUINOEXPERIMENTATION1_DS2321_H

#include "Arduino.h"
#include "Wire.h"

class DS2321 {
public:
    DS2321();
    void setTime(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year);
    void readTime(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year);
    void displayTime();

private:
    byte decToBcd(byte val);
    byte bcdToDec(byte val);
};


#endif //ARDUINOEXPERIMENTATION1_DS2321_H
