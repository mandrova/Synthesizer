/*
  ==============================================================================

    Filter.h
    Created: 19 Jun 2020 8:36:45am
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once

#include "Biquad.h"
#define TWOPI 6.283185307179586476925286766559

class Filter{
public:
    Filter();
    ~Filter();
    
    //void setFrequency(double filterFrequency);
    //void setResonance(double filterResonance);
    
    float processAudio(float sample_, float filterCutoff, float filterResonance, float sampleRate);
    
private:
    float sample;
    float cutoff;
    float sampleRate;
    float x;//speed
    float y;//pos
    float z;//pole
    float c;//filter coefficient
    float output;
    
    Biquad *biquad;
};
