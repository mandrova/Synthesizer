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

double Filter::adsr(double input, int trigger) {
    
    if (trigger==1 && attackphase!=1 && holdphase!=1 && decayphase!=1){
        holdcount=0;
        holdphase=0;
        decayphase=0;
        sustainphase=0;
        releasephase=0;
        attackphase=1;
        amplitude = 0;
    }

    if (attackphase==1) {
        releasephase=0;
        amplitude+=(1*attack);
        lastAmplitude = amplitude;
        output=input*amplitude;
        
        if (amplitude>=1) {
            amplitude=1;
            attackphase=0;
            decayphase=1;
        }
    }

    if (decayphase==1) {
        output=input*(amplitude*=decay);
        if (amplitude<=sustain) {
            decayphase=0;
            holdphase=1;
        }
    }

    if (holdcount<holdtime && holdphase==1) {
        output=input*amplitude;
        holdcount++;
    }

    if (holdcount>=holdtime && trigger==1) {
        output=input*amplitude;
    }

    if (holdcount>=holdtime && trigger!=1) {
        holdphase=0;
        releasephase=1;
    }

    if (releasephase==1 && amplitude>0.001) {
        
        
            
        output=input*(amplitude*=release);
    }

    return output;
}


void Filter::setAttack(double attackMS) {
    attack = 1-pow( 0.01, 1.0 / ( attackMS * maxiSettings::sampleRate * 0.001 ) );
}

void Filter::setRelease(double releaseMS) {
    release = pow( 0.01, 1.0 / ( releaseMS * maxiSettings::sampleRate * 0.001 ) );
}

void Filter::setSustain(double sustainL) {
    sustain = sustainL;
}

void Filter::setDecay(double decayMS) {
    decay = pow( 0.01, 1.0 / ( decayMS * maxiSettings::sampleRate * 0.001 ) );
}

float Filter:: processAudio(float sample_, float filterCutoff, float filterResonance, float sampleRate_){
    //proces audio in biquad. Check processing in biquad files
    biquad->setBiquad(0, filterCutoff / maxiSettings::sampleRate, 1, 0);
    output = biquad->process(sample_);
    
    return(output);
}
