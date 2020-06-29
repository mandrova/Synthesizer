/*
  ==============================================================================

    Saw.h
    Created: 27 Jun 2020 1:18:42pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
#include "Oscillator.h"

class Saw : public Oscillator{
    
    
public:
    Saw();
    ~Saw();
    
    void tick();
    
private:
    float phase;
};


