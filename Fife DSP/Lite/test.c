#include "core.h"
#include "basic_DSP.h"
#include "basic_waveforms.h"

//Test Portion
AudioBufferU u_buff;
AudioBufferF f_buff;


//Working area for implementing a granular synthesizer 
float sample_rate = 44100;
float frequency, output_interrupt_rate;
float phase_interrupt_rate;
uint32_t adc_bit_depth = 4096;
uint32_t adc_bias = 2048;


int main(){
    frequency = 100;
    output_interrupt_rate = (1 / sample_rate);
    phase_interrupt_rate = (1 / (frequency * BUFFER_SIZE));

    //Generate grain buffer and convert it to unsigned with the adc bit depth and bias, in this case the bit depth is 12, and the bias is at 1/2 the bit depth
    f_buff = GenerateSineWave(0);
    u_buff = ToUnsigned(f_buff, adc_bias, adc_bit_depth);

    /*
    * Next steps:
        1. Set an interrupt timer to the phase interrupt time (calculated from the desired frequency) 
            and increment the phase accumulator for the unsigned buffer at each interval.

        2. Set another interrupt timer to output the current sample at the given sample rate

        3. While the interrupts are firing, grab the ADC input from the knob to control the frequency of the output.  

    Something like this:

    Timer1 = DAC_Output(uBuff.buffer[phase_accumulator]) @ sample_rate

    Timer2 = AccumulatePhase(phase_accumulator, phase_interrupt_rate) @ phase_interrupt_rate 

    phase_interrupt_rate = ADC_Read(some_adc_port)


    */
    return 0;
}
