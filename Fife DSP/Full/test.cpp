#include "core.h"
#include "basic_functions.cpp"
#include "basic_waveforms.cpp"
#include <iostream>

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){

    f_buff = GenerateSinWave(128);
    GainControl(f_buff, 2.0);
    u_buff = ToUnsigned(f_buff,2048 ,4096);
    return 0;
}
