/*
  ==============================================================================

    Triangle.h
    Created: 27 Jun 2020 1:18:36pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
#include "Oscillator.h"
class Triangle : public Oscillator{
    
    
public:
    Triangle();
    ~Triangle();
    
    void tick();
    
private:
    float phase;
};
