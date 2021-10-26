/*
Fife DSP
Basic Waveforms

Jacob Fifield 
10-24-2021

Fife Electronics, LLC Digital Signal Processing Library

This DSP library is meant to be used for embedded environments, it is important to try and be as generic as 
possible when defining core functions.

A big goal of this library is READABILITY!! 
*/
#ifndef BASIC_WAVEFORMS_C
#define BASIC_WAVEFORMS_C
#define _USE_MATH_DEFINES
#define PI 3.14159265358979323846

#include "core.c"
#include "math.h"

//This function generates a sinwave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateSinwave(){
    AudioBufferF sinwave;
    on_each_frame{
        sinwave.buffer[frame] = sin((2*PI) * ((float)frame/BUFFER_SIZE));
    }
    return sinwave;
}

//This function generates a triangle wave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateTriangleWave(){
    AudioBufferF triwave;
    on_each_frame{
         triwave.buffer[frame] = ((2/PI)*asin(sin(2*PI*((float)frame/BUFFER_SIZE))));
    }
    return triwave;
}
#endif