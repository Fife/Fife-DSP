#include "core.c"
#include "basic_functions.c"

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;
int main(){
    on_each_frame{
        f_buff.buffer[frame] = 1;
    }

    GainControl(&f_buff,2);

    return 0;
}
