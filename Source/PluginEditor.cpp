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
    setSize(1000, 500);
    
    //================================================================================================================
    
    ampEnvAttSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    ampEnvAttSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> ampEnvAttackRange;
    ampEnvAttackRange.setStart(1);
    ampEnvAttackRange.setEnd(5000);
    
    ampEnvAttSlider.setRange(ampEnvAttackRange, 1);
    ampEnvAttSlider.setValue(2000);
    ampEnvAttSlider.addListener(this);
    addAndMakeVisible(&ampEnvAttSlider);
    
    ampEnvAttackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "ampEnvAtt", ampEnvAttSlider);
    
    //================================================================================================================
    
    ampEnvDecSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    ampEnvDecSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> ampEnvDecayRange;
    ampEnvDecayRange.setStart(1);
    ampEnvDecayRange.setEnd(5000);
    
    ampEnvDecSlider.setRange(ampEnvDecayRange, 1);
    ampEnvDecSlider.setValue(2000);
    ampEnvDecSlider.addListener(this);
    addAndMakeVisible(&ampEnvDecSlider);
    
    ampEnvDecaySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "ampEnvDec", ampEnvDecSlider);
    
    //================================================================================================================
    
    ampEnvSusSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    ampEnvSusSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> ampEnvSustainRange;
    ampEnvSustainRange.setStart(1);
    ampEnvSustainRange.setEnd(5000);
    
    ampEnvSusSlider.setRange(ampEnvSustainRange, 1);
    ampEnvSusSlider.setValue(2000);
    ampEnvSusSlider.addListener(this);
    addAndMakeVisible(&ampEnvSusSlider);
    
    ampEnvSustainSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "ampEnvSus", ampEnvSusSlider);
    
    //================================================================================================================
    
    ampEnvRelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    ampEnvRelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> ampEnvReleaseRange;
    ampEnvReleaseRange.setStart(1);
    ampEnvReleaseRange.setEnd(5000);
    
    ampEnvRelSlider.setRange(ampEnvReleaseRange, 1);
    ampEnvRelSlider.setValue(2000);
    ampEnvRelSlider.addListener(this);
    addAndMakeVisible(&ampEnvRelSlider);
    
    ampEnvReleaseSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "ampEnvRel", ampEnvRelSlider);

    //================================================================================================================
    
    filEnvAttSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filEnvAttSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> filEnvAttackRange;
    filEnvAttackRange.setStart(1);
    filEnvAttackRange.setEnd(5000);
    
    filEnvAttSlider.setRange(filEnvAttackRange, 1);
    filEnvAttSlider.setValue(2000);
    filEnvAttSlider.addListener(this);
    addAndMakeVisible(&filEnvAttSlider);
    
    filEnvAttackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filEnvAtt", filEnvAttSlider);
    
    //================================================================================================================
    
    filEnvDecSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filEnvDecSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> filEnvDecayRange;
    filEnvDecayRange.setStart(1);
    filEnvDecayRange.setEnd(5000);
    
    filEnvDecSlider.setRange(filEnvDecayRange, 1);
    filEnvDecSlider.setValue(2000);
    filEnvDecSlider.addListener(this);
    addAndMakeVisible(&filEnvDecSlider);
    
    filEnvDecaySliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filEnvDec", filEnvDecSlider);
    
    //================================================================================================================
    
    filEnvSusSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filEnvSusSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> filEnvSustainRange;
    filEnvSustainRange.setStart(1);
    filEnvSustainRange.setEnd(5000);
    
    filEnvSusSlider.setRange(filEnvSustainRange, 1);
    filEnvSusSlider.setValue(2000);
    filEnvSusSlider.addListener(this);
    addAndMakeVisible(&filEnvSusSlider);
    
    filEnvSustainSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filEnvSus", filEnvSusSlider);
    
    //================================================================================================================
    
    filEnvRelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    filEnvRelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> filEnvReleaseRange;
    filEnvReleaseRange.setStart(1);
    filEnvReleaseRange.setEnd(5000);
    
    filEnvRelSlider.setRange(filEnvReleaseRange, 1);
    filEnvRelSlider.setValue(2000);
    filEnvRelSlider.addListener(this);
    addAndMakeVisible(&filEnvRelSlider);
    
    filEnvReleaseSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filEnvRel", filEnvRelSlider);
    
    //================================================================================================================
    
    filterFreq.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterFreq.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 50);
    
    Range<double> filterFreqRange;
    filterFreqRange.setStart(20);
    filterFreqRange.setEnd(20000);
    
    filterFreq.setRange(filterFreqRange, 1);
    filterFreq.setValue(20000);
    filterFreq.addListener(this);
    addAndMakeVisible(&filterFreq);
    
    filterFreqSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filterFreq", filterFreq);
    
    btnOsc1Min2.setButtonText("-2");
    btnOsc1Min2.addListener(this);
    addAndMakeVisible(&btnOsc1Min2);
    
    btnOsc1Min1.setButtonText("-1");
    btnOsc1Min1.addListener(this);
    addAndMakeVisible(&btnOsc1Min1);
    
    btnOsc1Zero.setButtonText("<0>");
    btnOsc1Zero.addListener(this);
    addAndMakeVisible(&btnOsc1Zero);
    
    btnOsc1Plus1.setButtonText("+1");
    btnOsc1Plus1.addListener(this);
    addAndMakeVisible(&btnOsc1Plus1);
    
    btnOsc1Plus2.setButtonText("+2");
    btnOsc1Plus2.addListener(this);
    addAndMakeVisible(&btnOsc1Plus2);
    
    //================================================================================================================
    
    btnOsc2Min2.setButtonText("-2");
    btnOsc2Min2.addListener(this);
    addAndMakeVisible(&btnOsc2Min2);
    
    btnOsc2Min1.setButtonText("-1");
    btnOsc2Min1.addListener(this);
    addAndMakeVisible(&btnOsc2Min1);
    
    btnOsc2Zero.setButtonText("<0>");
    btnOsc2Zero.addListener(this);
    addAndMakeVisible(&btnOsc2Zero);
    
    btnOsc2Plus1.setButtonText("+1");
    btnOsc2Plus1.addListener(this);
    addAndMakeVisible(&btnOsc2Plus1);
    
    btnOsc2Plus2.setButtonText("+2");
    btnOsc2Plus2.addListener(this);
    addAndMakeVisible(&btnOsc2Plus2);
    
    //================================================================================================================
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
    
    
    //==============================================================================
    
    //draw text for amp envelope
    g.setFont(Font::plain);
    g.setFont(15.0f);
    
    g.drawFittedText("Attack", 10, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Decay", 70, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Sustain", 130, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Release", 190, 90, 50, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw title for amp envelope block
    g.setFont(Font::bold);
    g.setFont(20.0f);
    g.drawFittedText("Amp Envelope", 10, 65, 250, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw text for filter envelope
    g.setFont(Font::plain);
    g.setFont(15.0f);
    
    g.drawFittedText("Attack", 390, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Decay", 450, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Sustain", 510, 90, 50, 15, Justification::centred, 1);
    g.drawFittedText("Release", 570, 90, 50, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw title for amp envelope block
    g.setFont(Font::bold);
    g.setFont(20.0f);
    g.drawFittedText("Filter Envelope", 390, 65, 250, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //setcolor for interface lines
    g.setColour(Colour::fromRGB(87, 91, 96));
    
    //draw rectangle for amp en filter envelopes
    g.drawRect(5, 60, 240, 195);
    g.drawRect(385, 60, 240, 195);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    int x = 10;
    int spaceBetweenObjects = 60;
    int envelopeY = 100;
    
    ampEnvAttSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvDecSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvSusSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvRelSlider.setBounds(x, envelopeY, 50, 150);
    
    x += 200;
    
    filEnvAttSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvDecSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvSusSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvRelSlider.setBounds(x, envelopeY, 50, 150);
    
    int btnY = 35;
    int btnWidth = 30;
    spaceBetweenObjects = 40;
    x = 112;
    
    x -= spaceBetweenObjects * 2;
    btnOsc1Min2.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Min1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Zero.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Plus1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Plus2.setBounds(x, btnY, btnWidth, 15);
    
    x += 200;
    
    btnOsc2Min2.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Min1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Zero.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Plus1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Plus2.setBounds(x, btnY, btnWidth, 15);
    
    filterFreq.setBounds(650, 300, 150,150);
    filterHight.setBounds(850, 300, 150,150);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    
}



void NewProjectAudioProcessorEditor::buttonClicked(Button* button){
    if (button == &btnOsc1Min2){
        //processor.myVoice->setOctave(0.25);
        setStandardButtonText(1);
        btnOsc1Min2.setButtonText("<-2>");
        
        setDefaultButtonStates(1);
        processor.boolOtave1BtnMin2 = true;
    } else if (button == &btnOsc1Min1){
        //processor.myVoice->setOctave(0.5);
        setStandardButtonText(1);
        btnOsc1Min1.setButtonText("<-1>");
        
        setDefaultButtonStates(1);
        processor.boolOtave1BtnMin1 = true;
    } else if (button == &btnOsc1Zero){
        //processor.myVoice->setOctave(1);
        setStandardButtonText(1);
        btnOsc1Zero.setButtonText("<0>");
        
        setDefaultButtonStates(1);
        processor.boolOtave1BtnZero = true;
    } else if (button == &btnOsc1Plus1){
        //processor.myVoice->setOctave(2);
        setStandardButtonText(1);
        btnOsc1Plus1.setButtonText("<+1>");
        
        setDefaultButtonStates(1);
        processor.boolOtave1BtnPlus1 = true;
    } else if (button == &btnOsc1Plus2){
        //processor.myVoice->setOctave(4);
        setStandardButtonText(1);
        btnOsc1Plus2.setButtonText("<+2>");
        
        setDefaultButtonStates(1);
        processor.boolOtave1BtnPlus2 = true;
    } else if (button == &btnOsc2Min2){
        //processor.myVoice->setOctave(0.25);
        setStandardButtonText(2);
        btnOsc2Min2.setButtonText("<-2>");
        
        setDefaultButtonStates(2);
        processor.boolOtave2BtnMin2 = true;
    } else if (button == &btnOsc2Min1){
        //processor.myVoice->setOctave(0.5);
        setStandardButtonText(2);
        btnOsc2Min1.setButtonText("<-1>");
        
        setDefaultButtonStates(2);
        processor.boolOtave2BtnMin1 = true;
    } else if (button == &btnOsc2Zero){
        //processor.myVoice->setOctave(1);
        setStandardButtonText(2);
        btnOsc2Zero.setButtonText("<0>");
        
        setDefaultButtonStates(2);
        processor.boolOtave2BtnZero = true;
    } else if (button == &btnOsc2Plus1){
        //processor.myVoice->setOctave(2);
        setStandardButtonText(2);
        btnOsc2Plus1.setButtonText("<+1>");
        
        setDefaultButtonStates(2);
        processor.boolOtave2BtnPlus1 = true;
    } else if (button == &btnOsc2Plus2){
        //processor.myVoice->setOctave(4);
        setStandardButtonText(2);
        btnOsc2Plus2.setButtonText("<+2>");
        
        setDefaultButtonStates(2);;
        processor.boolOtave2BtnPlus2 = true;
    }
}


void NewProjectAudioProcessorEditor::setStandardButtonText(int oscillator){
    if (oscillator == 1){
        btnOsc1Min2.setButtonText("-2");
        btnOsc1Min1.setButtonText("-1");
        btnOsc1Zero.setButtonText("0");
        btnOsc1Plus1.setButtonText("+1");
        btnOsc1Plus2.setButtonText("+2");
    } else{
        btnOsc2Min2.setButtonText("-2");
        btnOsc2Min1.setButtonText("-1");
        btnOsc2Zero.setButtonText("0");
        btnOsc2Plus1.setButtonText("+1");
        btnOsc2Plus2.setButtonText("+2");
    }
}

void NewProjectAudioProcessorEditor::setDefaultButtonStates(int oscillator){
    if (oscillator == 1){
        processor.boolOtave1BtnMin2 = false;
        processor.boolOtave1BtnMin1 = false;
        processor.boolOtave1BtnZero = false;
        processor.boolOtave1BtnPlus1 = false;
        processor.boolOtave1BtnPlus2 = false;
    } else{
        processor.boolOtave2BtnMin2 = false;
        processor.boolOtave2BtnMin1 = false;
        processor.boolOtave2BtnZero = false;
        processor.boolOtave2BtnPlus1 = false;
        processor.boolOtave2BtnPlus2 = false;
    }
}
