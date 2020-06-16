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

class SynthVoice :  public SynthesiserVoice
{
public:
    bool canPlaySound(SynthesiserSound *sound){
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=====================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << "midiNoteNumber is: " << midiNoteNumber << std::endl;
    }
    
    //=====================================================================
    
    void stopNote(float velocity, bool allowTailOff){
        clearCurrentNote();
    }
    
    //=====================================================================
    
    void pitchWheelMoved(int newPitchWheelValue){
        
    }
    
    //=====================================================================
    
    void controllerMoved(int controllerNumber, int newControllerValue){
        
    }
    
    //=====================================================================
    
    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples){
        
    }
    
    //=====================================================================
    
private:
    double frequency;
    double velocity;
    
    
};
