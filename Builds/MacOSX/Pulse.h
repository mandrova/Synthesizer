//
//  Pulse.h
//  SynthVST
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Pulse_h
#define Pulse_h

#include "Waveform.h"

class Pulse : public Waveform{
    
    
public:
    Pulse(float sampleRate, float phase);
    ~Pulse();
    
    void tick(float);
    float getSample();
    
    
private:
    float samplerate;
    float phase;
    float sample;
    float frequency;
};

#endif /* Pulse_h */
