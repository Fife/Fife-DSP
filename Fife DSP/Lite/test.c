#include "core.h"
#include "basic_functions.c"
#include "basic_waveforms.c"

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){

    f_buff = GenerateTriangleWave();
    f_buff = GenerateSineWave();
    f_buff = GenerateSawtoothWave();
    u_buff = ToUnsigned(f_buff,2048 ,4096);
    return 0;
}
