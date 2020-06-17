/*
  ==============================================================================

    SynthVoice.h
    Created: 16 Jun 2020 10:56:25am
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "maximilian.h"

class synthVoice :  public SynthesiserVoice
{
public:
    
    //SynthVoice();
    //~SynthVoice();
    
    bool canPlaySound(SynthesiserSound *sound);
    
    //=====================================================================
    
    void getPeram(float* attack);
    
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition);
    
    //=====================================================================
    
    void stopNote(float velocity, bool allowTailOff);
    
    //=====================================================================
    
    void pitchWheelMoved(int newPitchWheelValue);
    
    //=====================================================================
    
    void controllerMoved(int controllerNumber, int newControllerValue);
    
    //=====================================================================
    
    virtual void renderNextBlock(AudioBuffer <float> &outputBuffer, int startSample, int numSamples);
    
    //=====================================================================
    
private:
    double frequency;
    double level;
    
    maxiOsc osc1;
    nickOsc osc2;
    maxiEnv env1;
    
    
};
