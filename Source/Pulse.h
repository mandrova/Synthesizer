//
//  Pulse.h
//  SynthVST
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Pulse_h
#define Pulse_h

#include "Maximilian/maximilian.h"
#include "Oscillator.h"

class Pulse : public Oscillator{
    
    
public:
    Pulse();
    ~Pulse();
    
    void tick();
    
private:
    float phase;
};

#endif /* Pulse_h */
