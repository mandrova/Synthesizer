/*
  ==============================================================================

    OscillatorProcessor.cpp
    Created: 29 Jun 2020 7:01:16pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "OscillatorProcessor.h"

OscillatorProcessor::OscillatorProcessor(){
    
}

//everything below is used to create a sample
double OscillatorProcessor::sineWave(double frequency_){
    sine.setFrequency(frequency_);
    output = sine.getSample();
    sine.tick();
    return output;
}

double OscillatorProcessor::pulseWave(double frequency_){
    pulse.setFrequency(frequency_);
    output = pulse.getSample();
    pulse.tick();
    return output;
}

double OscillatorProcessor::sawWave(double frequency_){
    saw.setFrequency(frequency_);
    output = saw.getSample();
    saw.tick();
    return output;
}

double OscillatorProcessor::triangleWave(double frequency_){
    triangle.setFrequency(frequency_);
    output = triangle.getSample();
    triangle.tick();
    return output;
}
