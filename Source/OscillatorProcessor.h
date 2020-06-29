/*
  ==============================================================================

    OscillatorProcessor.h
    Created: 29 Jun 2020 7:01:16pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
#include "Pulse.h"
#include "sine.h"
#include "Saw.h"
#include "Triangle.h"
class OscillatorProcessor
{
    double output;
    double frequency;
public:
    OscillatorProcessor();
    double sineWave(double);
    double pulseWave(double);
    double sawWave(double);
    double triangleWave(double);
    
private:
    Sine sine;
    Pulse pulse;
    Saw saw;
    Triangle triangle;
};
