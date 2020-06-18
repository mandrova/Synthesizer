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
#include "Oscillator.h"
#include "maximilian.h"

class synthVoice :  public SynthesiserVoice
{
public:
    
    
    bool canPlaySound(SynthesiserSound *sound) override{
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=====================================================================
    
    void getAmpEnvelopeParams(float* attack, float* decay, float* sustain, float* release){
        ampEnv.setAttack(*attack);
        ampEnv.setDecay(*decay);
        ampEnv.setSustain(*sustain);
        ampEnv.setRelease(*release);
    };
    
    //=====================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
        ampEnv.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }
    
    //=====================================================================
    
    void stopNote(float velocity, bool allowTailOff){
        ampEnv.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0){
            clearCurrentNote();
        }
    }
    
    //=====================================================================
    
    void pitchWheelMoved(int newPitchWheelValue){
        
    }
    
    //=====================================================================
    
    void controllerMoved(int controllerNumber, int newControllerValue){
        
    }
    
    //=====================================================================
    
    virtual void renderNextBlock(AudioBuffer <float> &outputBuffer, int startSample, int numSamples){
        
        for (int sample = 0; sample < numSamples ; sample++){
            double theWave = osc2.sineWave(frequency) * level;
            double theSound = ampEnv.adsr(theWave, ampEnv.trigger) * level;
            for (int channel = 0; channel < outputBuffer.getNumChannels() ; channel++) {
                outputBuffer.addSample(channel, startSample, theSound);
            }
            ++startSample;
        }
            
            
    }
    
    //=====================================================================
    
private:
        double frequency;
        double level;
        
        maxiOsc osc1;
        nickOsc osc2;
        
        maxiEnv ampEnv;
    
    
};
