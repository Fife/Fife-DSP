#include "stdint.h"
#define BUFFER_SIZE 256
#define on_each_frame for(int frame=0; frame<BUFFER_SIZE; frame++)

/*
Fife DSP

Jacob Fifield 
Project Start: 10-23-2021

Fife Electronics, LLC Digital Signal Processing Library

This DSP library is meant to be used for embedded environments, it is important to try and be as generic as 
possible when defining core functions.

A big goal of this library is READABILITY!! 
*/


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Data Structs~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
typedef struct AudioBufferU AudioBufferU;
typedef struct AudioBufferF AudioBufferF;

//Atomic audio buffer data structure. All members are unsigned INTs so you can pass the buffer from this struct directly into a DAC
struct AudioBufferU{
    int biased;
    uint32_t bias;
    uint32_t buffer[BUFFER_SIZE];
};
//Float based audio buffer data structure. This is meant to be a mathmatical representation centered around zero. 

struct AudioBufferF{
    int biased;
    float bias;
    float buffer[BUFFER_SIZE];
};

//Derived Stereo Buffers
struct StereoBufferU{
    AudioBufferU left;
    AudioBufferU right;
};

struct StereoBufferF{
    struct AudioBufferF left;
    struct AudioBufferF right;
};



AudioBufferF RemoveBias(struct AudioBufferU input){
    struct AudioBufferF fp_buffer;
    on_each_frame {
        input.buffer[frame] -= input.bias;
    }
    input.biased = 0;
    return fp_buffer;
};




AudioBufferU AddBias(struct AudioBufferU input){
    on_each_frame {
        input.buffer[frame] += input.bias;
    }
    input.biased = 1;
    return input;
};





