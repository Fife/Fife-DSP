#include "core.cpp"
#include "basic_functions.cpp"
#include "basic_waveforms.cpp"
#include <iostream>

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){

    //Test Envelope generation by loading a sinwave into an audio buffer 
    f_buff = GenerateSquareWave(128);
    f_buff = GenerateTriangleWave(128);
    f_buff = GenerateSinWave(128);
    u_buff = ToUnsigned(f_buff,2048 ,4096);

    GainControl(f_buff, 2.0);

    return 0;
}

