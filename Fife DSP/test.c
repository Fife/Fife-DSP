#include "core.c"

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){
    on_each_frame{
        f_buff.buffer[frame] = -1;
    }
    u_buff = ToUnsigned(f_buff, 2047, 4095);
    return 0;
}
