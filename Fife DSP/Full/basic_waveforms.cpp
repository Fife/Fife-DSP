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
#ifndef BASIC_WAVEFORMS_CPP
#define BASIC_WAVEFORMS_CPP
#define PI 3.14159265358979323846

#include "core.h"
#include <math.h>

//This function generates a sinwave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateSinWave(int buffer_size){
    AudioBufferF sinwave;
    float fraction;
    for(int frame=0; frame< buffer_size; frame++){
        fraction = (float)(frame/(float)buffer_size);
        sinwave.buffer.push_back(sin(2*PI*fraction) );
    }
    return sinwave;
}

//This function generates a triangle wave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateTriangleWave(int buffer_size){
    AudioBufferF triwave;
    for(int frame=0; frame< buffer_size; frame++){

        triwave.buffer.push_back((float)((2/PI)*asin(sin(2*PI*((float)frame/buffer_size)))));
    }
    return triwave;
}
#endif