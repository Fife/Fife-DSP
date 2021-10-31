#include "core.cpp"
#include "basic_functions.cpp"
#include "basic_waveforms.cpp"
#include <iostream>

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){


    //Test Envelope generation by loading a sinwave into an audio buffer 
    f_buff = GenerateSinWave(128);
    u_buff = ToUnsigned(f_buff,2048 ,4096);

    //Testing the DSP Function assignment by assigning it to gain control
    DSPFunction test; 
    test.function_ptr = GainControl;

    //Passing the audio buffer through the DSP function
    test.function_ptr(f_buff, 2);
    return 0;
}

