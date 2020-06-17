/*
  ==============================================================================

    SynthVoice.cpp
    Created: 16 Jun 2020 2:42:19pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "SynthVoice.h"

SynthVoice::SynthVoice(){
    
}

SynthVoice::~SynthVoice(){
    
}

bool SynthVoice::canPlaySound(SynthesiserSound *sound){
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}

//=====================================================================

void SynthVoice::startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
    level = velocity;
    frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    //std::cout << "midiNoteNumber is: " << midiNoteNumber << std::endl;
}

//=====================================================================

void SynthVoice::stopNote(float velocity, bool allowTailOff){
    level = 0;
    clearCurrentNote();
}

//=====================================================================

void SynthVoice::pitchWheelMoved(int newPitchWheelValue){
    
}

//=====================================================================

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue){
    
}

//=====================================================================

void SynthVoice::renderNextBlock(AudioBuffer <float> &outputBuffer, int startSample, int numSamples){
    
    
    for (int sample = 0; sample < numSamples ; sample++){
        double theWave = osc2.sineWave(frequency) * level;
        for (int channel = 0; channel < outputBuffer.getNumChannels() ; channel++) {
            outputBuffer.addSample(channel, startSample, theWave);
        }
        ++startSample;
    }
}
