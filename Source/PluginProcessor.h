/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Oscillator.h"
#include "SynthSound.h"
#include "/Users/nickverbeek/NewProject/Source/SynthVoice.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    Oscillator *osc1;
    Label *lblConsole;
    
    //setting bools for button clicked
    bool boolOtave1BtnMin2;
    bool boolOtave1BtnMin1;
    bool boolOtave1BtnZero;
    bool boolOtave1BtnPlus1;
    bool boolOtave1BtnPlus2;
    
    bool boolOtave2BtnMin2;
    bool boolOtave2BtnMin1;
    bool boolOtave2BtnZero;
    bool boolOtave2BtnPlus1;
    bool boolOtave2BtnPlus2;
    
    AudioProcessorValueTreeState tree;
    
    synthVoice* myVoice;
    
    bool osc1States[4]{1,0,0,0};
    bool osc2States[4]{1,0,0,0};
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
    Synthesiser mySynth;
    
    
    double lastSampleRate;
    
};
