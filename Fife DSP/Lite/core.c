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

#include "core.h"
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~Core Functions~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Function to convert U_INT_32 Buffer to Float buffer for DSP Algorithms 
inline AudioBufferF ToFloat(AudioBufferU input){
    AudioBufferF output;
    on_each_frame{
        output.buffer[frame] = 2*((float)input.buffer[frame]-input.bias)
                                / input.bit_depth;
    }
    return output;
}

//Function to convert Float buffer to U_INT_32 buffer for writing to ADCs 
inline AudioBufferU ToUnsigned(AudioBufferF input, uint32_t bias, uint32_t bit_depth){
    AudioBufferU output;
    output.bit_depth = bit_depth;
    output.bias = bias;
    on_each_frame{
        output.buffer[frame] = ((1 + input.buffer[frame]) 
                                * output.bit_depth)
                                / 2;

        /*
        A Branchless Lesson:

        This next portion is an example of a branchless choice function. The idea is we can optimize away choice statements (if/else) that might cause excessive jumping in the 
        compiled assembly file. It is done by multiplying each branch condition by the resulting number and adding all the resultant branches together.
        
        Like so:

        result = (result_of_branch_1 * (branch_1_condition))
                 + (result_of_branch_2 * (branch_2_condition))
                 ...etc 

        It is important to note that this only works if the branches are independent of each other. 
        This structure should be chosen over if/else statements when dealing with simple numerical choice operations, such as checking to see if the
        returned buffer is within the bit depth range:
        */

        output.buffer[frame] = (bit_depth * (output.buffer[frame] >= bit_depth))
                                + (output.buffer[frame] * (output.buffer[frame] < bit_depth && output.buffer[frame] >= 0));                               
    }
    return output;
}

inline AudioBufferF AddBuffersF(AudioBufferF input1, AudioBufferF input2 ) {
    AudioBufferF output;
    on_each_frame{
        output.buffer[frame] = input1.buffer[frame] + input2.buffer[frame];
    }
    return output;
}

inline StereoBufferF AddStereoBuffersF(StereoBufferF input1, StereoBufferF input2) {
    StereoBufferF output;
    output.left = AddBuffersF(input1.left, input2.left);
    output.right = AddBuffersF(input1.right, input2.right);
    return output;
}

//Stereo Counterparts to "ToFloat" and "ToUnsigned"
inline StereoBufferF StereoToFloat(StereoBufferU input){
    StereoBufferF output;
    output.left = ToFloat(input.left);
    output.right = ToFloat(input.right);
    return output;
}

inline StereoBufferU StereoToUnsigned(StereoBufferF input, uint32_t bias, uint32_t bit_depth){
    StereoBufferU output;
    output.left = ToUnsigned(input.left, bias, bit_depth);
    output.right = ToUnsigned(input.right, bias, bit_depth);
    return output;
}

inline void ShiftBufferU(AudioBufferU* input) {
    for (int i = BUFFER_SIZE - 1; i > 0; i--) {
        input->buffer[i] = input->buffer[i-1];
    }
    input->buffer[0] = 0;
}
inline void UpdateBufferU(AudioBufferU* input, float newSample) {
    ShiftBuffer(input);
    input->buffer[0] = newSample;
}

#endif