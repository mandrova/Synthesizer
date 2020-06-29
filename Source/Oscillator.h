//
//  Oscillator.h
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Oscillator_h
#define Oscillator_h

#include "Maximilian/maximilian.h"

class Oscillator
{
    double lastSampleRate;
public:
    Oscillator();
    ~Oscillator();
    
    void setFrequency(float frequency);
    float getFrequency();
    
    float getSample();
    
    double sampleRate;
    double frequency;
    double sample;
    
private:
    
    
};



#endif /* Oscillator_h */
