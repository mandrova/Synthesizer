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
    synthVoice(){
        setOctaveOne(1);
        setOctaveTwo(1);
    }
    
    bool canPlaySound(SynthesiserSound *sound) override{
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=====================================================================
    
    void getAmpEnvelopeParams(float* attack, float* decay, float* sustain, float* release){
        for (int i = 0; i<2 ; i++){
            ampEnv[i].setAttack(*attack);
            ampEnv[i].setDecay(*decay);
            ampEnv[i].setSustain(*sustain);
            ampEnv[i].setRelease(*release);
        }
    };
    
    void getFilEnvelopeParams(float* attack, float* decay, float* sustain, float* release){
        lowpassOsc1.setAttack(*attack);
        lowpassOsc1.setDecay(*decay);
        lowpassOsc1.setSustain(*sustain);
        lowpassOsc1.setRelease(*release);
        
        lowpassOsc2.setAttack(*attack);
        lowpassOsc2.setDecay(*decay);
        lowpassOsc2.setSustain(*sustain);
        lowpassOsc2.setRelease(*release);
    };
    
    
    
    //=====================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override{
        ampEnv[0].trigger = 1;
        ampEnv[1].trigger = 1;
        lowpassOsc1.trigger = 1;
        lowpassOsc2.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        
    }
    
    //=====================================================================
    
    void stopNote(float velocity, bool allowTailOff) override{
        ampEnv[0].trigger = 0;
        ampEnv[1].trigger = 0;
        lowpassOsc1.trigger = 0;
        lowpassOsc2.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0){
            clearCurrentNote();
        }
    }
    
    //=====================================================================
    
    void pitchWheelMoved(int newPitchWheelValue) override{
        
    }
    
    //=====================================================================
    
    void controllerMoved(int controllerNumber, int newControllerValue) override{
        
    }
    
    //=====================================================================
    
    virtual void renderNextBlock(AudioBuffer <float> &outputBuffer, int startSample, int numSamples) override{
    
        for (int sample = 0; sample < numSamples ; sample++){
            
            
            //std::cout << "OSC1: " << osc1Wave << std::endl;
            
            //double osc1Wave = osc1.sineWave(frequency*getOctaveOne()) * level;
            
            
            
            for (int channel = 0; channel < outputBuffer.getNumChannels() ; channel++) {
                double osc1Wave;
                double osc2Wave;
                
                if (waveformOsc1 == 1){
                    osc1Wave = osc1.sineWave(frequency*getOctaveOne()) * level;
                } else if (waveformOsc1 == 2){
                    osc1Wave = osc1.pulseWave(frequency*getOctaveOne()) * level;
                } else if (waveformOsc1 == 3){
                    osc1Wave = osc1.sawWave(frequency*getOctaveOne()) * level;
                } else if (waveformOsc1 == 4){
                    osc1Wave = osc1.triangleWave(frequency*getOctaveOne()) * level;
                }
                
                if (waveformOsc2 == 1){
                    osc2Wave = osc2.sineWave(frequency*getOctaveTwo()) * level;
                } else if (waveformOsc2 == 2){
                    osc2Wave = osc2.pulseWave(frequency*getOctaveTwo()) * level;
                } else if (waveformOsc2 == 3){
                    osc2Wave = osc2.sawWave(frequency*getOctaveTwo()) * level;
                } else if (waveformOsc2 == 4){
                    osc2Wave = osc2.triangleWave(frequency*getOctaveTwo()) * level;
                }
                
                double osc1Env = ampEnv[0].adsr(osc1Wave, ampEnv[0].trigger) * level;
                double filterEnvFollower = lowpassOsc1.adsr(1, lowpassOsc1.trigger);
                double osc1Filt = lowpassOsc1.processAudio(osc1Env, filterFreq * filterEnvFollower, 1, maxiSettings::sampleRate);
                double osc1Output = osc1Filt * osc1Volume;
                
                double osc2Env = ampEnv[1].adsr(osc2Wave, ampEnv[1].trigger) * level;
                double filterEnvFollower2 = lowpassOsc2.adsr(1, lowpassOsc1.trigger);
                double osc2Filt = lowpassOsc2.processAudio(osc2Env, filterFreq * filterEnvFollower2, 1, maxiSettings::sampleRate);
                double osc2Output = osc2Filt * osc2Volume;
                
                outputBuffer.addSample(channel, startSample, (osc1Output + osc2Output) * 0.8);
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
    
    void setOsc1Volume(float* volume_){
        osc1Volume = *volume_;
    }
    
    void setOsc2Volume(float* volume_){
        osc2Volume = *volume_;
    }
    
    void setWaveformOsc1(int waveform_){
        waveformOsc1 = waveform_;
    }
    
    void setWaveformOsc2(int waveform_){
        waveformOsc2 = waveform_;
    }
    
    double octaveOscOne;
    double octaveOscTwo;
    
private:
    double frequency;
    double level;
    
    double filterFreq;
    
    float osc1Volume;
    float osc2Volume;
        
    nickOsc osc1;
    nickOsc osc2;
    
    Filter lowpassOsc1;
    Filter lowpassOsc2;
        
    maxiEnv ampEnv[2];
    
    
    int waveformOsc1;
    int waveformOsc2;
    
};
