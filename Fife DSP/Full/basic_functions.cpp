/*

Fife DSP

Jacob Fifield 
10-24-2021

Fife Electronics, LLC Digital Signal Processing Library

This DSP library is meant to be used for embedded environments, it is important to try and be as generic as 
possible when defining core functions.

A big goal of this library is READABILITY!! 

~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~Basic Collection~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~

This is a collection of basic DSP algorithms. These functions are meant to operate directly on a AudioBufferF struct. 
Because of this, they can potentially be destructive, and require a pointer to an AudioBufferF struct. 
This is done to minimize stack usage, since constantly creating new structs bloats memory. 

*/

#ifndef BASIC_FUNCTIONS_CPP
#define BASIC_FUNCTIONS_CPP

#include "core.h"

// Gain Control takes a pointer to AudioBufferF type and applys a multiplicitive gain.
// Lower gain < 1 (Unity) < Higher Gain
// Gain of 0 cancels out all signal.

void GainControl(AudioBufferF input, float gain){
    for(int frame =0; frame< input.buffer.size(); frame++){
        input.buffer.at(frame)= input.buffer.at(frame) * gain;
    }
}

#endif