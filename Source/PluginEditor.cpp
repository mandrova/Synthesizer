/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);
    
    freqSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
    freqSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    freqSlider.setRange(200, 1000);
    freqSlider.setValue(500);
    freqSlider.addListener(this);
    addAndMakeVisible(&freqSlider);
    
    
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("midistuff", getLocalBounds(), Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    freqSlider.setBounds(100, getHeight() - (getHeight() - 20), 40, getHeight() - 60);
    //processor.lblConsole->setBounds(200, 50, 200, 100);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &freqSlider){
        processor.osc1->setFrequency(freqSlider.getValue());
    }
    //std::cout << "Sine frequency is: " << processor.osc1->getFrequency() << std::endl;
}
