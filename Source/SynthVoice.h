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
#include "Filter.h"
#include "maximilian.h"
#include "math.h"

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
    
    void getFilEnvelopeParams(float* attack, float* decay, float* sustain, float* release){
        filterEnv.setAttack(*attack);
        filterEnv.setDecay(*decay);
        filterEnv.setSustain(*sustain);
        filterEnv.setRelease(*release);
    };
    
    
    
    //=====================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override{
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
            double osc1Wave = osc1.sineWave(frequency*getOctaveOne()) * level;
            double osc1Env = ampEnv.adsr(osc1Wave, ampEnv.trigger) * level;
            double filterEnvFollower = filterEnv.adsr(osc1Env, ampEnv.trigger);
            
            
            
            //lowpass[0]->setBiquad(0, lowpassFreq / sampleRate, 1, 0);
            
            
            
            float osc1Filt = lowpassOsc1.processAudio(filterEnvFollower, filterFreq, 1, maxiSettings::sampleRate);
            
            double osc2Wave = osc2.sineWave(frequency*getOctaveTwo()) * level;
            double osc2Env = ampEnv.adsr(osc2Wave, ampEnv.trigger) * level;
            double osc2Filt = lowpassOsc2.processAudio(osc2Env, 100, 1, maxiSettings::sampleRate);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels() ; channel++) {
                outputBuffer.addSample(channel, startSample, osc1Filt);
            }
            ++startSample;
            //std::cout << osc1Filt << std::endl;
        }
            
            
    }
    
    //=====================================================================
    
    void setOctaveOne(double multiplier_){
        octaveOscOne = multiplier_;
        
    }
    
    //=====================================================================
    
    double getOctaveOne(){
        return octaveOscOne;
    }
    
    //=====================================================================
    
    void setOctaveTwo(double multiplier_){
        octaveOscTwo = multiplier_;
        
    }
    
    //=====================================================================
    
    double getOctaveTwo(){
        return octaveOscTwo;
    }
    
    //=====================================================================
    
    void setFilterFrequency(float* filterFreq_){
        filterFreq = *filterFreq_;
        
    }
    
    void setFilterHight(float* filterHight_){
        filterHight = *filterHight_;
    }
    
    double octaveOscOne;
    double octaveOscTwo;
    
private:
    double frequency;
    double level;
    
    double filterFreq;
    double filterHight;
        
    nickOsc osc1;
    nickOsc osc2;
    
    Filter lowpassOsc1;
    Filter lowpassOsc2;
        
    maxiEnv ampEnv;
    maxiEnv filterEnv;
    
    
};
