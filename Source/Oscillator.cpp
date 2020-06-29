//
//  Oscillator.cpp
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#include <stdio.h>
#include "Oscillator.h"



Oscillator::Oscillator(){
    sampleRate = maxiSettings::sampleRate;
    
}

Oscillator::~Oscillator(){
    
}

void Oscillator::setFrequency(float frequency){
    this->frequency = frequency;
}

float Oscillator::getSample(){
    return sample;
}

float Oscillator::getFrequency(){
    return frequency;
}
