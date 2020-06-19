//
//  Delay.h
//  Delay
//
//  Created by Nick Verbeek on 04-05-18.
//

#ifndef Delay_h
#define Delay_h

#include "Effect.h"
#include "Biquad.h"

class Delay : public Effect
{
public:
    Delay();
    Delay(int);
    ~Delay();
    
    void init(int);
    
    //plugin settings
    void setDelayTime(double);          //set delay time between delays
    void setFeedback(float);           //set the amount of feedback
    void setDrySignalPanning(float);    //set the panning of the dry signal
    void setWetSignalPanning(float);    //set the panning of the wet signal
    void setDryLevel(float);            //set the volume of the dry signal
    void setWetLevel(float);            //set the volume of the wet signal
    
    void setLowpassFilter(int freq);
    void setHighpassFilter(int freq);
    
    void setSampleRate(double);
    
    float getDelayTime();
    float process(int, float);
    
    
    
private:
    int delayTime;
    float feedback;
    float dryLevel;
    float wetLevel;
    float drySignalPan;
    float wetSignalPan;
    
    double sampleRate;
    
    float delayBuffer[2][192000];
    float delayLine[2];
    float lowpassSignal[2];
    float highpassSignal[2];
    int delayStep[2];
    
    Biquad *lowpass[2];
    Biquad *highpass[2];
    
    int lowpassFreq = 20000;
    int highpassFreq = 0;
};

#endif /* Delay_h */
