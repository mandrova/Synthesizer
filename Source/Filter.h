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
    
    
    
    double adsr(double input,int trigger);
    double input;
    double output;
    double attack;
    double decay;
    double sustain;
    double release;
    double amplitude;
    double lastAmplitude;
    bool trigger;

    void setAttack(double attackMS);
    void setRelease(double releaseMS);
    void setDecay(double decayMS);
    void setSustain(double sustainL);
    
    long holdtime=1;
    long holdcount;
    int attackphase,decayphase,sustainphase,holdphase,releasephase;
    
    float processAudio(float sample_, float filterCutoff, float filterResonance, float sampleRate);
    
private:
    float sample;
    float cutoff;
    float sampleRate;
    float x;//speed
    float y;//pos
    float z;//pole
    float c;//filter coefficient
    float output1;
    
    Biquad *biquad;
};
