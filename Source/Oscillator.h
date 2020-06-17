//
//  Oscillator.h
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#ifndef Oscillator_h
#define Oscillator_h
#include "Pulse.h"
#include "sine.h"

class Oscillator
{
    double lastSampleRate;
public:
    Oscillator();
    ~Oscillator();
    
    void setFrequency(float frequency);
    float getFrequency();
    
    void setAmplitude(float amplitude);
    float getAmplitude();
    
    void setWaveform(int);
    char getWaveform();
    
    void tick();
    float getSample();
    
    static double samplerate;
    static void setup(double);
    
private:
    
    float frequency;
    float sample;
    
    Sine *sine;
    Pulse *pulse;
    int waveform;
    
};

class nickOsc
{
    double output;
    double frequency;
public:
    nickOsc();
    double sineWave(double);
    
private:
    Sine sine;
};

#endif /* Oscillator_h */
