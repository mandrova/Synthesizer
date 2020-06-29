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
    setSize(680, 270);
    
    //Do all the setting of components below
    //================================================================================================================
    
    //set style of slider
    ampEnvAttSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    //set the textbox style being used
    ampEnvAttSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    //create a range
    Range<double> ampEnvAttackRange;
    ampEnvAttackRange.setStart(1);
    ampEnvAttackRange.setEnd(5000);
    
    //set the range with usement of step increments
    ampEnvAttSlider.setRange(ampEnvAttackRange, 1);
    
    //add listener which is this
    ampEnvAttSlider.addListener(this);
    //make the object visible
    addAndMakeVisible(&ampEnvAttSlider);
    
    //setting a velue for the slider in the tree. The string value can be used to read the value.
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
    filEnvRelSlider.addListener(this);
    addAndMakeVisible(&filEnvRelSlider);
    
    filEnvReleaseSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filEnvRel", filEnvRelSlider);
    
    //================================================================================================================
    
    filterFreq.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterFreq.setTextBoxStyle(Slider::TextBoxBelow, true, 80, 15);
    
    Range<double> filterFreqRange;
    filterFreqRange.setStart(20);
    filterFreqRange.setEnd(20000);
    
    filterFreq.setRange(filterFreqRange, 1);
    filterFreq.setValue(20000);
    filterFreq.addListener(this);
    addAndMakeVisible(&filterFreq);
    
    filterFreqSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "filterFreq", filterFreq);
    
    osc1Volume.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    osc1Volume.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> osc1VolumeRange;
    osc1VolumeRange.setStart(0);
    osc1VolumeRange.setEnd(1);
    
    osc1Volume.setRange(osc1VolumeRange, 0.01);
    osc1Volume.setValue(1);
    filterFreq.addListener(this);
    addAndMakeVisible(&osc1Volume);
    
    osc1VolumeSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "osc1Volume", osc1Volume);
    
    osc2Volume.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    osc2Volume.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
    
    Range<double> osc2VolumeRange;
    osc2VolumeRange.setStart(0);
    osc2VolumeRange.setEnd(1);
    
    osc2Volume.setRange(osc2VolumeRange, 0.01);
    osc2Volume.setValue(1);
    filterFreq.addListener(this);
    addAndMakeVisible(&osc2Volume);
    
    osc2VolumeSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, "osc2Volume", osc2Volume);
    
    
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
    
    btnOsc1Sine.setButtonText("Sine");
    btnOsc1Sine.addListener(this);
    addAndMakeVisible(&btnOsc1Sine);
    
    btnOsc1Pulse.setButtonText("Pulse");
    btnOsc1Pulse.addListener(this);
    addAndMakeVisible(&btnOsc1Pulse);
    
    btnOsc1Saw.setButtonText("Saw");
    btnOsc1Saw.addListener(this);
    addAndMakeVisible(&btnOsc1Saw);
    
    btnOsc1Triangle.setButtonText("Triangle");
    btnOsc1Triangle.addListener(this);
    addAndMakeVisible(&btnOsc1Triangle);
    
    btnOsc2Sine.setButtonText("Sine");
    btnOsc2Sine.addListener(this);
    addAndMakeVisible(&btnOsc2Sine);
    
    btnOsc2Pulse.setButtonText("Pulse");
    btnOsc2Pulse.addListener(this);
    addAndMakeVisible(&btnOsc2Pulse);
    
    btnOsc2Saw.setButtonText("Saw");
    btnOsc2Saw.addListener(this);
    addAndMakeVisible(&btnOsc2Saw);
    
    btnOsc2Triangle.setButtonText("Triangle");
    btnOsc2Triangle.addListener(this);
    addAndMakeVisible(&btnOsc2Triangle);
    
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
    
    g.drawFittedText("Attack", 10, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Decay", 70, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Sustain", 130, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Release", 190, 100, 50, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw title for amp envelope block
    g.setFont(Font::bold);
    g.setFont(20.0f);
    g.drawFittedText("Amp Envelope", 10, 75, 250, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw text for filter envelope
    g.setFont(Font::plain);
    g.setFont(15.0f);
    
    g.drawFittedText("Attack", 440, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Decay", 500, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Sustain", 560, 100, 50, 15, Justification::centred, 1);
    g.drawFittedText("Release", 620, 100, 50, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw filter text
    g.drawFittedText("Frequency", 315, 35, 50, 15, Justification::centred, 1);
    
    //draw mixer text
    g.drawFittedText("Osc1 mix", 265, 170, 50, 15, Justification::centred, 1);
    g.drawFittedText("Osc2 mix", 365, 170, 50, 15, Justification::centred, 1);
    
    //draw title for amp envelope block
    g.setFont(Font::bold);
    g.setFont(20.0f);
    g.drawFittedText("Filter Envelope", 440, 75, 250, 15, Justification::centred, 1);
    
    //==============================================================================
    
    //draw title for filter
    g.drawFittedText("Filter", 250, 15, 180, 15, Justification::centred, 1);
    
    //setcolor for interface lines
    g.setColour(Colour::fromRGB(87, 91, 96));
    
    //draw rectangle for amp en filter envelopes
    g.drawRect(5, 70, 240, 195);
    g.drawRect(435, 70, 240, 195);
    
    //draw rectangle for Oscillator fields
    g.drawRect(5, 10, 240, 55);
    g.drawRect(435, 10, 240, 55);
    
    //draw rectangle filter field
    g.drawRect(250, 10, 180, 150);
    
    //draw rectangle mix field
    g.drawRect(250, 165, 180, 100);
}

void NewProjectAudioProcessorEditor::resized()
{
    //setbounds for all object
    int x = 10;
    int spaceBetweenObjects = 60;
    int envelopeY = 110;
    
    ampEnvAttSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvDecSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvSusSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    ampEnvRelSlider.setBounds(x, envelopeY, 50, 150);
    
    x += 250;
    
    filEnvAttSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvDecSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvSusSlider.setBounds(x, envelopeY, 50, 150);
    x += spaceBetweenObjects;
    filEnvRelSlider.setBounds(x, envelopeY, 50, 150);
    
    int btnY = 45;
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
    
    x += 112;
    
    x += 237 - (spaceBetweenObjects * 2);
    btnOsc2Min2.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Min1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Zero.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Plus1.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Plus2.setBounds(x, btnY, btnWidth, 15);
    
    btnWidth = 50;
    x = 10;
    btnY = 20;
    spaceBetweenObjects = 60;
    
    btnOsc1Sine.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Pulse.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Saw.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc1Triangle.setBounds(x, btnY, btnWidth, 15);
    
    x += 250;
    
    btnOsc2Sine.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Pulse.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Saw.setBounds(x, btnY, btnWidth, 15);
    x += spaceBetweenObjects;
    btnOsc2Triangle.setBounds(x, btnY, btnWidth, 15);
    
    filterFreq.setBounds(285, 50, 110, 110);
    
    x = 250;
    int y = 180;
    
    osc1Volume.setBounds(x, y, 80, 80);
    x += 100;
    osc2Volume.setBounds(x, y, 80, 80);
    
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    //not being used
}



void NewProjectAudioProcessorEditor::buttonClicked(Button* button){
    //set Buttonstates for OSC multipliers.
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
    
    //set array for further selection of waveforms
    //oscStates can be found in pluginProcessor files
    if (button == & btnOsc1Sine){
        setDefaultOscStates(1);
        processor.osc1States[0] = true;
    } else if (button == & btnOsc1Pulse){
        setDefaultOscStates(1);
        processor.osc1States[1] = true;
    } else if (button == & btnOsc1Saw){
        setDefaultOscStates(1);
        processor.osc1States[2] = true;
    } else if (button == & btnOsc1Triangle){
        setDefaultOscStates(1);
        processor.osc1States[3] = true;
    } else if (button == & btnOsc2Sine){
        setDefaultOscStates(2);
        processor.osc2States[0] = true;
    } else if (button == & btnOsc2Pulse){
        setDefaultOscStates(2);
        processor.osc2States[1] = true;
    } else if (button == & btnOsc2Saw){
        setDefaultOscStates(2);
        processor.osc2States[2] = true;
    } else if (button == & btnOsc2Triangle){
        setDefaultOscStates(2);
        processor.osc2States[3] = true;
    }
    
    
}


void NewProjectAudioProcessorEditor::setStandardButtonText(int oscillator){
    //setStandard text for the buttons.
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
    //set button states for further changing the octaves
    //these can be found in the pluginprocessor files
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

void NewProjectAudioProcessorEditor::setDefaultOscStates(int oscNum){
    //set states to false as default.
    //further use of this can be found in pluginprocessor files
    if (oscNum == 1){
        for (int i = 0; i < 4; i++){
            processor.osc1States[i] = false;
        }
    } else {
        for (int i = 0; i < 4; i++){
            processor.osc2States[i] = false;
        }
    }
}
