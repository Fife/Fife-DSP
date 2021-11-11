#pragma once
#ifndef BASIC_DSP_H
#define BASIC_DSP_H

//Multiply entire buffer by some constant
void GainControl(AudioBufferF* input, float gain);


float FindPeak(AudioBufferF* input);
void ScaleToOne(AudioBufferF* input);

#endif
