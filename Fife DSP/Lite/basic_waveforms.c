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

#define PI 3.141592653589

#include "core.h"
#include "math.h"
#include "basic_waveforms.h"

//This function generates a sinwave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateSineWave(float phase, float frequency){
    AudioBufferF sinwave;
    float fraction, phase_angle;
    phase_angle = (phase * (PI / 180.0));
    on_each_frame{
        fraction = (float)frame / BUFFER_SIZE;
        sinwave.buffer[frame] = sin(((2*PI) *frequency)/SAMPLE_RATE + phase_angle);
    }
    return sinwave;
}

//This function generates a triangle wave centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateTriangleWave(float phase, float frequency){
    AudioBufferF triwave;
    float fraction; 
    float phase_angle = (phase * (PI / 180.0));
    on_each_frame{
        fraction = (float)frame / BUFFER_SIZE;
        triwave.buffer[frame] = ((2/PI)*asin(sin((2*PI *frequency)/SAMPLE_RATE + phase_angle)));
    }
    return triwave;
}

//This function generates a square wave composed of sinwaves centered at 0 with an amplitude of 1 and returns is as an Audio Buffer 
AudioBufferF GenerateSquareWave(float phase, float frequency) {
    AudioBufferF squarewave;
    float fraction;
    float phase_angle = (phase * (PI / 180.0));
    on_each_frame{ 
        fraction = (float)frame / BUFFER_SIZE;
        squarewave.buffer[frame] =
            ((1 / 1.0) *  sin((2 * PI * 1 * frequency)/SAMPLE_RATE + phase_angle))
            + ((1 / 3.0) * sin((2 * PI * 3 * frequency)/SAMPLE_RATE + phase_angle))
            + ((1 / 5.0) * sin((2 * PI * 5 * frequency)/SAMPLE_RATE + phase_angle))
            + ((1 / 7.0) * sin((2 * PI * 7 * frequency)/SAMPLE_RATE + phase_angle))
            + ((1 / 9.0) * sin((2 * PI * 9 * frequency)/SAMPLE_RATE + phase_angle));
        }
    return squarewave;
}

//This function generates a sawtooth wave from the formula:
// (-2/PI) * arctan(cotangent((PI*x)/p)))

AudioBufferF GenerateSawtoothWave(float phase, float frequency) {
    AudioBufferF sawwave;
    float fraction;
    float inner_argument, cotangent;
    float phase_angle = (phase * (PI / 180.0));
    on_each_frame{
        inner_argument =  (frequency*PI)/(2*SAMPLE_RATE);
        cotangent = (cos(inner_argument + phase_angle)) / (sin(inner_argument + phase_angle));
        sawwave.buffer[frame] = (-2/PI)*((float)atan(cotangent));
    }
    return sawwave;
}
#endif