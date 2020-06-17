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
    
    void getPeram(float* attack){
        env1.setAttack(*attack);
    };
    
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){

        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        //std::cout << "midiNoteNumber is: " << midiNoteNumber << std::endl;
        
    }
    
    //=====================================================================
    
    void stopNote(float velocity, bool allowTailOff){
        env1.trigger = 0;
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
        //env1.setAttack(2000);
        env1.setDecay(200);
        env1.setSustain(0.5);
        env1.setRelease(2000);
        
        for (int sample = 0; sample < numSamples ; sample++){
            double theWave = osc2.sineWave(frequency) * level;
            double theSound = env1.adsr(theWave, env1.trigger) * level;
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
        
        maxiEnv env1;
    
    
};
