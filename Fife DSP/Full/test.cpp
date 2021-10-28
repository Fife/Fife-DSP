#include "core.cpp"
#include "basic_functions.cpp"
#include "basic_waveforms.cpp"
#include <iostream>

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){
    f_buff = GenerateSinWave(128);
    u_buff = ToUnsigned(f_buff,2048 ,4096);
    DSPFunction test; 

    test.function_ptr = GainControl;

    test.function_ptr(f_buff, 2);

    return 0;
}

