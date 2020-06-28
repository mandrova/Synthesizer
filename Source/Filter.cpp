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
            //std::cout << "Attack Output: " << output << std::endl;
        
        
        if (amplitude>=1) {
            amplitude=1;
            attackphase=0;
            decayphase=1;
        }
    }


    if (decayphase==1) {
        output=input*(amplitude*=decay);
        //std::cout << "Decay Output: " << output << std::endl;
        if (amplitude<=sustain) {
            decayphase=0;
            holdphase=1;
        }
    }

    if (holdcount<holdtime && holdphase==1) {
        output=input*amplitude;
        holdcount++;
        //std::cout << "Hold Count Output: " << output << std::endl;
    }

    if (holdcount>=holdtime && trigger==1) {
        output=input*amplitude;
        //std::cout << "Hold Count 2 Output: " << output << std::endl;
    }

    if (holdcount>=holdtime && trigger!=1) {
        holdphase=0;
        releasephase=1;
    }

    if (releasephase==1 && amplitude>0.001) {
        
        
            
            output=input*(amplitude*=release);
            //std::cout << "Release Output: " << output << std::endl;
    }
    
    //std::cout << "Filter envelope Output: " << output << std::endl;

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
    biquad->setBiquad(0, filterCutoff / maxiSettings::sampleRate, 1, 0);
    output1 = biquad->process(sample_);
    //output = biquad->process(sample_);
    
    return(output1);
}
