#ifndef
#define DEFAULT_SIZE = 256
#include "grain-synthesizer.h"

//By default, the granular synth starts out with a 256 sample sinwave
GranularSynth(){
	for (int i = 0; i<DEFAULT_SIZE; i++){
		this->audioBuffer.push(sin(2*PI*(i/DEFAULT_SIZE));
	}
	this->sample_rate = 44100;
	this->phase_acc = 0;
	this->frequency = 1000;
	this->acc_update_rate = 1/(this->frequency * DEFAULT_SIZE);
}

~GranularSynth(){

}

void setFrequency(float frequency){

}

void incrementBuffer(float sample_rate){

}

void loadBuffer(std::vector<float> input_buffer){

}
void clearBuffer(){

}


#endif
