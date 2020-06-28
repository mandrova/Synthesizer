/*
  ==============================================================================

    Saw.h
    Created: 27 Jun 2020 1:18:42pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
#include "Maximilian/maximilian.h"

class Saw{
    
    
public:
    Saw();
    ~Saw();
    
    void tick(double, float);
    float getSample();
    
    
private:
    float samplerate;
    float phase;
    float sample;
    float frequency;
};


