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

AudioBufferF GenerateTriangleWave(){
    AudioBufferF triwave;
    on_each_frame{
         triwave.buffer[frame] = ((frame/(BUFFER_SIZE*0.25)))*(frame<=((int)BUFFER_SIZE*0.25))
                                +(1 - ((frame-(BUFFER_SIZE*0.25))/(BUFFER_SIZE*0.25)))*(frame>(BUFFER_SIZE*0.25) && frame<=(BUFFER_SIZE*0.75))
                                +((frame - (BUFFER_SIZE*0.75))/(BUFFER_SIZE*0.25) - 1)*(frame>(BUFFER_SIZE*0.75));
    }
    return triwave;
}
#endif