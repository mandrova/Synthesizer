/*
  ==============================================================================

    Filter.cpp
    Created: 19 Jun 2020 8:36:45am
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "Filter.h"
#include "Maximilian/maximilian.h"
#include "math.h"



Filter::Filter(){
    biquad = new Biquad();
}

Filter::~Filter(){
    
}


float Filter:: processAudio(float sample_, float filterCutoff, float filterResonance, float sampleRate_){
    biquad->setBiquad(0, filterCutoff / maxiSettings::sampleRate, 1, 0);
    output = biquad->process(sample_);
    
    
    return(output);
}
