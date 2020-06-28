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
#include "Saw.h"
#include "Triangle.h"

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
    double pulseWave(double);
    double sawWave(double);
    double triangleWave(double);
    
private:
    Sine sine;
    Pulse pulse;
    Saw saw;
    Triangle triangle;
};

#endif /* Oscillator_h */
