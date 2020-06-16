//
//  Oscillator.h
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Oscillator_h
#define Oscillator_h
#include "Pulse.h"
#include "sine.h"

class Oscillator
{
public:
    Oscillator(float, float);
    ~Oscillator();
    
    void setFrequency(float frequency);
    float getFrequency();
    
    void setAmplitude(float amplitude);
    float getAmplitude();
    
    void setWaveform(int);
    char getWaveform();
    
    void tick();
    float getSample();
    
private:
    float samplerate;
    float frequency;
    float sample;
    
    Sine *sine;
    Pulse *pulse;
    int waveform;
    
};

#endif /* Oscillator_h */
