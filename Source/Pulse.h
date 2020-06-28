//
//  Pulse.h
//  SynthVST
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Pulse_h
#define Pulse_h

#include "Maximilian/maximilian.h"

class Pulse{
    
    
public:
    Pulse();
    ~Pulse();
    
    void tick(double, float);
    float getSample();
    
    
private:
    float samplerate;
    float phase;
    float sample;
    float frequency;
};

#endif /* Pulse_h */
