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
#include <string>
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Type Definitions~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

typedef struct AudioBufferU AudioBufferU;
typedef struct AudioBufferF AudioBufferF;
typedef struct StereoBufferU StereoBufferU;
typedef struct StereoBufferF StereoBufferF;
typedef struct Channel Channel;

typedef void (*IO_Block)(AudioBufferF);
typedef struct DSPFunction DSPFunction;
typedef void (*Operation)(AudioBufferF a, float b);
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Atomic Structs~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


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

struct DSPFunction{
    //Declaration of function pointer called "function_ptr" that points to the math portion of a DSP function
    Operation function_ptr; 
    std::string id;
    //0 for off, 1 for on, and -1 for error.
    int status; 
};


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~Derived Structs~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//Derived Stereo Buffer structures from AudioBufferF and AudioBufferU
struct StereoBufferU{
    AudioBufferU left;
    AudioBufferU right;
};

struct StereoBufferF{
    AudioBufferF left;
    AudioBufferF right;
};

#endif

