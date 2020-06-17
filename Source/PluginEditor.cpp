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
    
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> attackRange;
    attackRange.setStart(1);
    attackRange.setEnd(5000);
    
    attackSlider.setRange(attackRange, 1);
    attackSlider.setValue(2000);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);
    
    sliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "attack", attackSlider);
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
    attackSlider.setBounds(10, 10, 50, 150);
    
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &attackSlider){
        processor.attackTime = attackSlider.getValue();
    }
    //std::cout << "Sine frequency is: " << processor.osc1->getFrequency() << std::endl;
}
