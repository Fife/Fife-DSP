/*
Fife DSP

Jacob Fifield 
Project Start: 10-23-2021

Fife Electronics, LLC Digital Signal Processing Library

This DSP library is meant to be used for embedded environments, it is important to try and be as generic as 
possible when defining core functions.

A big goal of this library is READABILITY!! 
*/
#ifndef CORE_H
#define CORE_H

#include <vector>
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
    int bit_depth;
    int bias;
    std::vector<int> buffer;
};

//Float based audio buffer data structure. This is meant to be a mathmatical representation centered around zero with range -1 to 1. *

struct AudioBufferF{
    std::vector<float> buffer;
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
    for(int frame=0; frame<input.buffer.size(); frame++){
        output.buffer.push_back(2*((float)input.buffer.at(frame)-input.bias)
                                / input.bit_depth);
    }
    return output;
}

//Function to convert Float buffer to U_INT_32 buffer for writing to ADCs 
AudioBufferU ToUnsigned(AudioBufferF input, int bias, int bit_depth){
    AudioBufferU output;
    output.bit_depth = bit_depth;
    output.bias = bias;
    for(int frame=0; frame< input.buffer.size(); frame++){
        output.buffer.push_back(((1 + input.buffer.at(frame)) 
                                * output.bit_depth)
                                / 2);

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

        output.buffer.at(frame) = (bit_depth * (output.buffer.at(frame) >= bit_depth))
                                + (output.buffer.at(frame) * (output.buffer.at(frame) < bit_depth && output.buffer.at(frame) >= 0));                               
    }
    return output;
}

//Stereo Counterparts to "ToFloat" and "ToUnsigned"
StereoBufferF StereoToFloat(StereoBufferU input){
    StereoBufferF output;
    output.left = ToFloat(input.left);
    output.right = ToFloat(input.right);
    return output;
}

StereoBufferU StereoToUnsigned(StereoBufferF input, int bias, int bit_depth){
    StereoBufferU output;
    output.left = ToUnsigned(input.left, bias, bit_depth);
    output.right = ToUnsigned(input.right, bias, bit_depth);
    return output;
}

#endif