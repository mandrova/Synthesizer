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

double Oscillator::samplerate = 44100;

Oscillator::Oscillator(){

    
    //sine = new Sine(frequency, samplerate);
    //pulse = new Pulse(samplerate, frequency);
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
    //pulse->tick(samplerate);
    //sample = pulse->getSample();
}

float Oscillator::getSample(){
    return sample;
}

float Oscillator::getFrequency(){
    return frequency;
}

void Oscillator::setup(double sampleRate_){
    samplerate = sampleRate_;
}

nickOsc::nickOsc(){
    
}

double nickOsc::sineWave(double frequency_){
    double sRate = Oscillator::samplerate;
    output = sine.getSample();
    sine.tick(sRate, frequency_);
    return output;
}

double nickOsc::pulseWave(double frequency_){
    double sRate = Oscillator::samplerate;
    output = pulse.getSample();
    pulse.tick(sRate, frequency_);
    return output;
}

double nickOsc::sawWave(double frequency_){
    double sRate = Oscillator::samplerate;
    output = saw.getSample();
    saw.tick(sRate, frequency_);
    return output;
}

double nickOsc::triangleWave(double frequency_){
    double sRate = Oscillator::samplerate;
    output = triangle.getSample();
    triangle.tick(sRate, frequency_);
    return output;
}
