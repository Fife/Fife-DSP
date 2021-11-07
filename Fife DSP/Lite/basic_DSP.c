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
This is done to minimize stack/heap usage, since constantly creating new structs bloats memory. 

*/

#ifndef BASIC_DSP_C
#define BASIC_DSP_C

#include "core.h"
#include "basic_DSP.h"

// Gain Control takes a pointer to AudioBufferF type and applys a multiplicitive gain.
// Lower gain < 1 (Unity) < Higher Gain
// Gain of 0 cancels out all signal.

void GainControl(AudioBufferF* input, float gain){
    on_each_frame{
        input->buffer[frame] = input->buffer[frame] * gain;
    }
}

float FindPeak(AudioBufferF* input) {
    float peak, min, max;
    min = 0;
    max = 0;

    //Find the maximum and minimum peaks
    on_each_frame{
        if (input->buffer[frame] > max) { 
            max = input->buffer[frame];
        }
        if (input->buffer[frame] < min) {
            min = input->buffer[frame];
        }
    }
    
    //Minimum peaks will be negative, flip the sign 
    min = min * (-1.0);

    //Use a branchless statement to compare the peaks to get the higher one. 
    peak = max * (max >= min) 
         + min * (min > max);

    return peak;
}


//This function scales an Audio Buffer that overshoots 1 or -1 by finding the amount of gain adjustment the signal needs to bring the peaks down to exactly 1 or -1.
//If the signal does not peak at above 1 this function does not do anything

void ScaleToOne(AudioBufferF* input) {
    // Find maximum or absolute value of minimum, whichever is higher. Call this number peak
    float peak, v_diff, inter_prop, gain_adjust;
    peak = FindPeak(input);

    //Find gain adjustment by finding the proportion of the difference in the signal strength.
    //Then dividing that number by the peak and subtracting from 1.

    v_diff = peak - 1.0;

    if (v_diff > 0); {
        inter_prop = v_diff / peak;
        gain_adjust = 1 - inter_prop;
        GainControl(input, gain_adjust);
    }
}

#endif