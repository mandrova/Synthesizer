//
//  Pulse.cpp
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#include <stdio.h>
#include "Pulse.h"
#include "math.h"

Pulse::Pulse(float sampleRate, float frequency){
    this->samplerate = sampleRate;
    this->frequency = frequency;
}

Pulse::~Pulse(){
    
}

void Pulse::tick(float frequency){
    phase += frequency/samplerate;
    
    sample = 0;
    
    int x = 1;
    
    float less = 1.0;
    
    for (int i=0; i<25;i++)
    {
        sample = sample + less * 4/M_PI*1/x*sin(x*M_PI*phase);
        x += 2;
        less -= 0.05;
    }
        
        
    if (phase >= 1){
        phase = phase - 1;
    }
}

float Pulse::getSample(){
    return sample;
}
