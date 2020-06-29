#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "Oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
    Sine();
    ~Sine();

  //go to next sample
    void tick();

private:
    float phase;
    //float sample;
    //float samplerate;
    ;
};

#endif
