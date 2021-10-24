/*
Fife DSP

Jacob Fifield 
Project Start: 10-23-2021

Fife Electronics, LLC Digital Signal Processing Library

This DSP library is meant to be used for embedded environments, it is important to try and be as generic as 
possible when defining core functions.

A big goal of this library is READABILITY!! 
*/

#ifndef CORE_C
#define CORE_C

#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>
#define BUFFER_SIZE 256
#define on_each_frame for(int frame=0; frame<BUFFER_SIZE; frame++)

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Data Structs~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
typedef struct AudioBufferU AudioBufferU;
typedef struct AudioBufferF AudioBufferF;
typedef struct StereoBufferU StereoBufferU;
typedef struct StereoBufferF StereoBufferF;

//Atomic audio buffer data structure. All members are unsigned INTs so you can pass the buffer from this struct directly into a DAC
struct AudioBufferU{
    uint32_t bit_depth;
    uint32_t bias;
    uint32_t buffer[BUFFER_SIZE];
};

//Float based audio buffer data structure. This is meant to be a mathmatical representation centered around zero with range -1 to 1. *

struct AudioBufferF{
    float buffer[BUFFER_SIZE];
};

//Derived Stereo Buffer structures from AudioBufferF and AudioBufferU
struct StereoBufferU{
    AudioBufferU left;
    AudioBufferU right;
};

struct StereoBufferF{
    AudioBufferF left;
    AudioBufferF right;
};


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~Core Functions~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Function to convert U_INT_32 Buffer to Float buffer for DSP Algorithms 
AudioBufferF ToFloat(AudioBufferU input){
    AudioBufferF output;
    on_each_frame{
        output.buffer[frame] = 2*((float)input.buffer[frame]-input.bias)
                                / input.bit_depth;
    }
    return output;
}

//Function to convert Float buffer to U_INT_32 buffer for writing to ADCs 
AudioBufferU ToUnsigned(AudioBufferF input, uint32_t bias, uint32_t bit_depth){
    AudioBufferU output;
    output.bit_depth = bit_depth;
    output.bias = bias;
    on_each_frame{
        output.buffer[frame] = (1 + input.buffer[frame]) 
                                * output.bit_depth
                                / 2;

        /*
        A Branchless Lesson:

        This next portion is an example of a branchless choice function. The idea is we can optimize away choice statements that might cause excessive jumping in the 
        compiled assembly file. It is done by multiplying each branch condition by the resulting number and adding all the resultant branches together.
        
        Like so:

        result = (result_of_branch_1 * (branch_1_condition))
                 + (result_of_branch_2* (branch_2_condition))
                 ...etc 

        It is important to note that this only works if the branches are independent of each other. 
        This structure should be chosen over if/else statements when dealing with simple numerical choice operations, such as checking to see if the
        returned buffer is within the bit depth range:
        */

        output.buffer[frame] = (bit_depth * (output.buffer[frame] > bit_depth))
                                + (output.buffer[frame] * (output.buffer[frame] < bit_depth && output.buffer[frame] >= 0));                               
    }
    return output;
}

/*
//Stereo Counterparts to "ToFloat" and "ToUnsigned"
StereoBufferF ToFloat(StereoBufferU input){
    StereoBufferF output;
    output.left = ToFloat(input.left);
    output.right = ToFloat(input.right);
    return output;
}

StereoBufferU ToUnsigned(StereoBufferF input, uint32_t bias, uint32_t bit_depth){
    StereoBufferU output;
    output.left = ToUnsigned(input.left, bias, bit_depth);
    output.right = ToUnsigned(input.right, bias, bit_depth);
    return output;
}
*/
#endif