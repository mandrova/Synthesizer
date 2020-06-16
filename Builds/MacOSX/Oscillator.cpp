//
//  Oscillator.cpp
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#include <stdio.h>
#include "Oscillator.h"
#include "sine.h"
#include "Waveform.h"


Oscillator::Oscillator(float frequency, float samplerate){
    this->samplerate = samplerate;
    this->frequency = frequency;
    sine = new Sine(frequency, samplerate);
    pulse = new Pulse(samplerate, frequency);
}

Oscillator::~Oscillator(){
    
}

void Oscillator::setFrequency(float frequency){
    this->frequency = frequency;
}

void Oscillator::setWaveform(int wave){
    this->waveform = wave;
}

void Oscillator::tick(){
    //if (waveform == 1){
    //    sine->tick();
    //    sample = sine->getSample();
    //} else if (waveform == 2){
    //    pulse->tick(samplerate);
    //    sample = pulse->getSample();
    //}
    pulse->tick(samplerate);
}

float Oscillator::getSample(){
    return sample;
}

float Oscillator::getFrequency(){
    return frequency;
}
