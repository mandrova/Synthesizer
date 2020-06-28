/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener, public Button::Listener

{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider *slider) override;
    void buttonClicked (Button *button) override;
    
    void setStandardButtonText(int oscillator);
    void setDefaultButtonStates(int oscillator);
    
    void setDefaultOscStates(int oscNum);
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor& processor;
    
    //declaration of sliders
    Slider ampEnvAttSlider;
    Slider ampEnvDecSlider;
    Slider ampEnvSusSlider;
    Slider ampEnvRelSlider;
    
    Slider filEnvAttSlider;
    Slider filEnvDecSlider;
    Slider filEnvSusSlider;
    Slider filEnvRelSlider;
    
    Slider filterFreq;
    
    Slider osc1Volume;
    Slider osc2Volume;
    
    //declaration of buttons
    TextButton btnOsc1Min2;
    TextButton btnOsc1Min1;
    TextButton btnOsc1Zero;
    TextButton btnOsc1Plus1;
    TextButton btnOsc1Plus2;
    
    TextButton btnOsc2Min2;
    TextButton btnOsc2Min1;
    TextButton btnOsc2Zero;
    TextButton btnOsc2Plus1;
    TextButton btnOsc2Plus2;
    
    TextButton btnOsc1Sine;
    TextButton btnOsc1Pulse;
    TextButton btnOsc1Saw;
    TextButton btnOsc1Triangle;
    
    TextButton btnOsc2Sine;
    TextButton btnOsc2Pulse;
    TextButton btnOsc2Saw;
    TextButton btnOsc2Triangle;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
public:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ampEnvAttackSliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ampEnvDecaySliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ampEnvSustainSliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ampEnvReleaseSliderValue;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filEnvAttackSliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filEnvDecaySliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filEnvSustainSliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filEnvReleaseSliderValue;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterFreqSliderValue;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> osc1VolumeSliderValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> osc2VolumeSliderValue;
};
