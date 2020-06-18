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
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener

{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider *slider) override;
    
    void drawEnvelopeBox(int x, int y, int width, int hight, Graphics& g);
    
    
    
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
    
    //declaration of labels
    

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
};
