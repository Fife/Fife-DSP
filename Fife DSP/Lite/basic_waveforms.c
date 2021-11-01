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

#define PI 3.14159265358979323846

#include "core.c"
#include "math.h"

//This function generates a sinwave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
inline AudioBufferF GenerateSineWave(){
    AudioBufferF sinwave;
    on_each_frame{
        sinwave.buffer[frame] = sin((2*PI) * ((float)frame/BUFFER_SIZE));
    }
    return sinwave;
}

//This function generates a triangle wave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
inline AudioBufferF GenerateTriangleWave(){
    AudioBufferF triwave;
    on_each_frame{
         triwave.buffer[frame] = ((2/PI)*asin(sin(2*PI*((float)frame/BUFFER_SIZE))));
    }
    return triwave;
}

//This function generates a square wave composed of sinwaves centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
inline AudioBufferF GenerateSquareWave(i) {
    AudioBufferF squarewave;
    on_each_frame{ 
        float fraction = (float)(frame / BUFFER_SIZE);
        squarewave.buffer[frame] =
            ((1 / 1) * 4 * sin(PI * fraction * 1)
            + (1 / 3) * 4 * sin(PI * fraction * 3)
            + (1 / 5) * 4 * sin(PI * fraction * 5)
            + (1 / 7) * 4 * sin(PI * fraction * 7)
            + (1 / 9) * 4 * sin(PI * fraction * 9));
        }
    return squarewave;
}
#endif