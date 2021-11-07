#pragma once
#ifndef BASIC_DSP_H
#define BASIC_DSP_H

void GainControl(AudioBufferF* input, float gain);
float FindPeak(AudioBufferF* input);
inline void ScaleToOne(AudioBufferF* input);

#endif
