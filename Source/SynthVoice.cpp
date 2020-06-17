/*
  ==============================================================================

    SynthVoice.cpp
    Created: 16 Jun 2020 2:42:19pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "SynthVoice.h"

//SynthVoice::SynthVoice(){
    
//}

//SynthVoice::~SynthVoice(){
    
//}

bool synthVoice::canPlaySound(SynthesiserSound *sound){
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}

//=====================================================================

void synthVoice::getPeram(float* attack){
    env1.setAttack(float(*attack));
}

void synthVoice::startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition){
    
    env1.trigger = 1;
    level = velocity;
    frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    //std::cout << "midiNoteNumber is: " << midiNoteNumber << std::endl;
    
}

//=====================================================================

void synthVoice::stopNote(float velocity, bool allowTailOff){
    env1.trigger = 0;
    allowTailOff = true;
    
    if (velocity == 0){
        clearCurrentNote();
    }
    
    
}

//=====================================================================

void synthVoice::pitchWheelMoved(int newPitchWheelValue){
    
}

//=====================================================================

void synthVoice::controllerMoved(int controllerNumber, int newControllerValue){
    
}

//=====================================================================

void synthVoice::renderNextBlock(AudioBuffer <float> &outputBuffer, int startSample, int numSamples){
    env1.setAttack(2000);
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
