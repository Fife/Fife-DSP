#include "engine.h"

DSPEngine::DSPEngine() {
	/*
	Initialize Engine
	- Populate vector of channels
	- Populate vectors of DSP functions within channels
	- Assign Hardware Blocks to channels
	- Create and initialize Channel Buffers
	*/
};

DSPEngine::DSPEngine(int sample_rate, int buffer_size, int num_channels){
/*
Initialize Engine 
- Populate vector of channels 
- Populate vectors of DSP functions within channels
- Assign Hardware Blocks to channels
- Create and initialize Channel Buffers
*/
};
void DSPEngine::UpdateInputs(){
//Grab next sample from hardware input blocks
};
void DSPEngine::UpdateChannels(){
//perfom DSP on each channel
};
void DSPEngine::UpdateOutputs(){
//Update the hardware output blocks
};