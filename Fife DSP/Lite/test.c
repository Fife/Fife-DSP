#include "core.h"
#include "basic_DSP.c"
#include "basic_waveforms.c"

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){

    f_buff = GenerateSineWave(180);
    f_buff = GenerateTriangleWave(180);
    f_buff = GenerateSquareWave(180);
    f_buff = GenerateSawtoothWave(270);
    u_buff = ToUnsigned(f_buff,2048 ,4096);
    return 0;
}
