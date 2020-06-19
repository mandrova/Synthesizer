//
//  Delay.cpp
//  Delay
//
//  Created by Nick Verbeek on 04-05-18.
//

#include "Delay.h"
#include <iostream>
#include "Effect.h"



Delay::Delay(){
    
}

Delay::Delay(int numChannels){
    
}

Delay::~Delay(){
    //destructor of delay
}

void Delay::init(int numChannels){
    delayTime = (1000/sampleRate) * 500;
    
    //Creating instances of Biquad
    lowpass[0] = new Biquad();
    lowpass[1] = new Biquad();
    highpass[0] = new Biquad();
    highpass[1] = new Biquad();
    
    //settingup the filters for stereo
    lowpass[0]->setBiquad(0, lowpassFreq / sampleRate, 1, 0);
    lowpass[1]->setBiquad(0, lowpassFreq / sampleRate, 1, 0);
    highpass[0]->setBiquad(1, highpassFreq / sampleRate, 0.707, 0);
    highpass[1]->setBiquad(1, highpassFreq / sampleRate, 0.707, 0);
    
    //Init delayBuffer
    for(int channel=0; channel <numChannels; channel++){
        for(int sample=0; sample<sampleRate; sample++){
            delayBuffer[channel][sample] = 0;
        }
    }
}

//Set delay time
void Delay::setDelayTime(double delay){
    //calculate x samples of delay
    this->delayTime = (sampleRate / 1000) * delay;
}

//Set feedback
void Delay::setFeedback(float feedback){
    this->feedback = feedback;
}

//Set drypanning
void Delay::setDrySignalPanning(float dryPan){
    this->drySignalPan = dryPan;
}

//Set wet panning
void Delay::setWetSignalPanning(float wetPan){
    this->wetSignalPan = wetPan;
}

//Set dry level
void Delay::setDryLevel(float dryLevel){
    this->dryLevel = dryLevel;
}

//set wet level
void Delay::setWetLevel(float wetLevel){
    this->wetLevel = wetLevel;
}

//set frequency of lowpass filters
void Delay::setLowpassFilter(int freq){
    lowpass[0]->setFc(freq/sampleRate);
    lowpass[1]->setFc(freq/sampleRate);
}

//set frequency of highpassfilters
void Delay::setHighpassFilter(int freq){
    highpass[0]->setFc(freq/sampleRate);
    highpass[1]->setFc(freq/sampleRate);
}

//set samplerate
void Delay::setSampleRate(double SampleRate){
    this->sampleRate = SampleRate;
}

//get delaytime
float Delay::getDelayTime(){
    return delayTime;
}

//process function of delay
//this function has stereo processing. So every piece is created twice so that it can calculate the channels independen of eachother
float Delay::process(int channel, const float inputSignal){
    float output[2];
    float input;
    
    float dryPan[2];
    float wetPan[2];
    
    //calculate dry panning value
    if(drySignalPan < 0){
        dryPan[0] = (100 - (drySignalPan * -1)) / 100;
        dryPan[1] = 1.0;
    } else {
        dryPan[1] = (100 - drySignalPan) / 100;
        dryPan[0] = 1.0;
    }
    
    //calcualte wet panning value
    if(wetSignalPan < 0){
        wetPan[0] = (100 - (wetSignalPan * -1)) / 100;
        wetPan[1] = 1.0;
    } else {
        wetPan[1] = (100 - wetSignalPan) / 100;
        wetPan[0] = 1.0;
    }
    
    //multiply inputsingal with the desired input level
    input = inputSignal * getInputLevel();
    
    //calculate delayLine
    delayLine[channel] = feedback * delayBuffer[channel][delayStep[channel]];
    
    //do panning based on which channel is active
    if(channel == 0){
        output[channel] = 0.50 * (dryPan[1] * (dryLevel * input)) + wetPan[1] * (wetLevel * delayLine[channel]);
    } else {
        output[channel] = 0.50 * (dryPan[0] * (dryLevel * input)) + wetPan[0] * (wetLevel * delayLine[channel]);
    }
    
    //send data through lowpass filter
    lowpassSignal[channel] = lowpass[channel]->process(input + delayLine[channel]);
    
    //send data through highpass filter
    highpassSignal[channel] = highpass[channel]->process(lowpassSignal[channel]);
    
    //put everything into a delay buffer
    delayBuffer[channel][delayStep[channel]] = highpassSignal[channel];
    
    //count the steps for selecting delayed samples
    delayStep[channel]++;
    delayStep[channel] %= delayTime;
    
    //returning the output
    return output[channel];
}
