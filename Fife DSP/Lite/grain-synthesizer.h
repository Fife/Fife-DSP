
//Granular Synthesizer
//Jacob Fifield
//Nov 24th 2021

//This is a module that takes an AudioBufferF containing with a granular sample
//and plays it back at different rates.

//This program will need a few things:
//Take in a user input to set the frequency desired
//Set phase accumulator to the desired frequency
//Step through the buffer accordingly at each interval

//These buffers will be larger than the typical buffer, since a "grain" of
//audio is from 1-10ms. At 44100 sampling rate, that is appox. 22.676us of
//time between samples.
//This means that a granular sample buffer size should be anywhere between 44 and 440 samples long.

//Another feature that is synthesizer should have is the ability to  upload your own samples.
//This means that the buffer should be able to be dynamically allocated.
#include <"core.h">

class GranularSynth{
public:
	GranularSynth();
	~GranularSynth();
	void setFrequency(float frequency);
	void setSampleRate(float sample_rate);
	void incrementBuffer();
	void loadBuffer(std::vector<float> input_buffer);
	void clearBuffer();
private:
	int phase_acc;
	AudioBufferF = audio_buffer;
	int sample_rate;
	float frequency, acc_update_rate;
}
