#include "core.h"
#include "basic_functions.cpp"
#include "basic_waveforms.cpp"
#include <iostream>

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){

    f_buff = GenerateSinWave(128);
    u_buff = ToUnsigned(f_buff,2048 ,4096);
    for (int i=0; i<f_buff.buffer.size();i++){
        std::cout<<f_buff.buffer.at(i)<<"\n";
    }
    return 0;
}
