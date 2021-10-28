#include "channel.h"

Channel::Channel(){

};
Channel::~Channel(){

};
Channel::Channel(std::vector<void(*)()> function_list, IO_Block io_input, IO_Block io_output, AudioBufferU input, AudioBufferU output){
    
};
void Channel::AddDSPToList(DSPFunction function){

};
void Channel::RemoveDSPToList(DSPFunction function){

};
void Channel::ToggleDSP(std::string id){

};
void Channel::PrintChannelStrip(){

};
