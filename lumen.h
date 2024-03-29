/*
Name: Sergio Satyabrata
Date: April 14, 2023 
Class: CPSC-3200
Revision History: Revised
Platform: MacBook Pro (OSX)

Lumen.h is the header file for the Lumen class, which represents a light source 
with customizable properties such as brightness, size, and power. 
The class provides methods to manipulate these properties and simulate the behavior of 
the light source in different conditions. The Lumen class is responsible for maintaining 
the state of the light source and providing methods to query its current state and modify it 
accordingly. This header file contains the declarations of the Lumen class's member 
functions and variables, ensuring proper encapsulation and separation of concerns in the program.
*/

#ifndef LUMEN_H
#define LUMEN_H

#include <stdexcept>

class Lumen {
public:
    Lumen(int input_brightness, int input_size, int input_power);

    int glow();
    void reset();
    void recharge();
    bool isActive();
    bool isErratic();
    bool resetRequest();

    int current_glow_value();
    int get_power();
    int get_powerT();
    bool isCharged();

private:
    int brightness;
    int size;
    int power;
    int brightness_copy;
    int power_copy;
    int glow_request;

    bool charged;

    static constexpr int INACTIVE_STATE = 0;
    static constexpr int reset_threshold = 5;

    int dimming_value;
    int power_threshold;

    int ErraticValue();
};

#endif // LUMEN_H


/*
Class invariants for Lumen:

- brightness, size, and power must always be non-negative integer values.
- brightness_copy and power_copy must hold the original brightness and power values, respectively.
- glow_request must be a non-negative integer value that counts the number of glow() calls.
- charged is a boolean that represents whether the Lumen has been recharged or not.
- INACTIVE_STATE and reset_threshold are constants with fixed values.
- dimming_value must always be calculated as 10% of the original brightness.
- power_threshold must always be calculated as 20% of the original power.
*/