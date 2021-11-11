#pragma once
#ifndef CORE_H
#define CORE_H

#include "stdint.h"
#include "stdbool.h"

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 256
#define on_each_frame for(int frame=0; frame<BUFFER_SIZE; frame++)


typedef struct AudioBufferU AudioBufferU;
typedef struct AudioBufferF AudioBufferF;
typedef struct StereoBufferU StereoBufferU;
typedef struct StereoBufferF StereoBufferF;


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Data Structs~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Atomic audio buffer data structure. All members are unsigned INTs so you can pass the buffer from this struct directly into a DAC
struct AudioBufferU {
    uint32_t bit_depth;
    uint32_t bias;
    uint32_t buffer[BUFFER_SIZE];
};

//Float based audio buffer data structure. This is meant to be a mathmatical representation centered around zero with range -1 to 1. *
struct AudioBufferF {
    float buffer[BUFFER_SIZE];
};

//Derived Stereo Buffer structures from AudioBufferF and AudioBufferU
struct StereoBufferU {
    AudioBufferU left;
    AudioBufferU right;
};
struct StereoBufferF {
    AudioBufferF left;
    AudioBufferF right;
};


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~Function Declaractions~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Buffer Type Conversions:
AudioBufferF ToFloat(AudioBufferU input);
AudioBufferU ToUnsigned(AudioBufferF input, uint32_t bias, uint32_t bit_depth);
StereoBufferF StereoToFloat(StereoBufferU input);
StereoBufferU StereoToUnsigned(StereoBufferF input, uint32_t bias, uint32_t bit_depth);


//Arithmetic Operations on Buffers:
AudioBufferF AddBuffersF(AudioBufferF input1, AudioBufferF input2);
StereoBufferF AddStereoBuffersF(StereoBufferF input1, StereoBufferF input2);

//Utility Functions
void ShiftBufferU(AudioBufferU* input);
void UpdateBufferU(AudioBufferU* input, float* newSample);

#endif