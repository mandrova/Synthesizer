/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
 
    
 
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
//below is the tree as its called. this stores the date of all sliders. These can be read in de processing block for further programming
tree(*this, nullptr, "PARAMETER", { std::make_unique<AudioParameterFloat>("ampEnvAtt", "Attack", 1, 5000, 1),
                                    std::make_unique<AudioParameterFloat>("ampEnvDec", "Decay", 1, 2000, 1),
                                    std::make_unique<AudioParameterFloat>("ampEnvSus", "Sustain", 0.001, 1.0, 1.0f ),
                                    std::make_unique<AudioParameterFloat>("ampEnvRel", "Release", 1, 5000, 1),
                                    
                                    std::make_unique<AudioParameterFloat>("filEnvAtt", "Attack", 1, 5000, 1),
                                    std::make_unique<AudioParameterFloat>("filEnvDec", "Decay", 1, 2000, 1),
                                    std::make_unique<AudioParameterFloat>("filEnvSus", "Sustain", 0.001, 1.0f, 1.0f ),
                                    std::make_unique<AudioParameterFloat>("filEnvRel", "Release", 1, 5000, 20),
                                    std::make_unique<AudioParameterFloat>("filterFreq", "FilterFrequency", 10, 20000, 20000),
    
                                    std::make_unique<AudioParameterFloat>("osc1Volume", "osc1Volume", 0, 1, 1),
                                    std::make_unique<AudioParameterFloat>("osc2Volume", "osc2Volume", 0, 1, 1),
                                    
                                    
                


})

#endif
{
    //creation of mySynth
    mySynth.clearVoices();
    for (int i=0; i<10; i++){
        mySynth.addVoice(new synthVoice());
    }
    
    //clears mySynth and adds a new SynthSound as a voice
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound);
    
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String NewProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
    
}

void NewProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void NewProjectAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    //auto totalNumInputChannels  = getTotalNumInputChannels();
    //auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    //get the voices that are used in mySynth
    for (int i = 0; i < mySynth.getNumVoices(); i++){
        if ((myVoice = dynamic_cast<synthVoice*>(mySynth.getVoice(i)))){
            //get values out of the slider
            float* ampEnvAttack = (float*) tree.getRawParameterValue("ampEnvAtt");
            float* ampEnvDecay = (float*) tree.getRawParameterValue("ampEnvDec");
            float* ampEnvSustain = (float*) tree.getRawParameterValue("ampEnvSus");
            float* ampEnvRelease = (float*) tree.getRawParameterValue("ampEnvRel");
            
            //send value to myvoice
            myVoice->getAmpEnvelopeParams(ampEnvAttack, ampEnvDecay, ampEnvSustain, ampEnvRelease);
            
            float* filEnvAttack = (float*) tree.getRawParameterValue("filEnvAtt");
            float* filEnvDecay = (float*) tree.getRawParameterValue("filEnvDec");
            float* filEnvSustain = (float*) tree.getRawParameterValue("filEnvSus");
            float* filEnvRelease = (float*) tree.getRawParameterValue("filEnvRel");
            
            myVoice->getFilEnvelopeParams(filEnvAttack, filEnvDecay, filEnvSustain, filEnvRelease);
            
            //get Filter value from slider and set the desired filterfrequency
            float* filterFreq = (float*) tree.getRawParameterValue("filterFreq");
            myVoice->setFilterFrequency(filterFreq);
            
            float* osc1Volume = (float*) tree.getRawParameterValue("osc1Volume");
            float* osc2Volume = (float*) tree.getRawParameterValue("osc2Volume");
            myVoice->setOsc1Volume(osc1Volume);
            myVoice->setOsc2Volume(osc2Volume);
            
            //changing the multiplier bassed on button input
            //oscillator 1
            if (boolOtave1BtnMin2 == true){
                myVoice->setOctaveOne(0.25);
            } else if (boolOtave1BtnMin1 == true){
                myVoice->setOctaveOne(0.5);
            } else if (boolOtave1BtnZero == true){
                myVoice->setOctaveOne(1);
            } else if (boolOtave1BtnPlus1 == true){
                myVoice->setOctaveOne(2);
            } else if (boolOtave1BtnPlus2 == true){
                myVoice->setOctaveOne(4);
            }
            
            //oscillator 2
            if (boolOtave2BtnMin2 == true){
                myVoice->setOctaveTwo(0.25);
            } else if (boolOtave2BtnMin1 == true){
                myVoice->setOctaveTwo(0.5);
            } else if (boolOtave2BtnZero == true){
                myVoice->setOctaveTwo(1);
            } else if (boolOtave2BtnPlus1 == true){
                myVoice->setOctaveTwo(2);
            } else if (boolOtave2BtnPlus2 == true){
                myVoice->setOctaveTwo(4);
            }
            
            //selecting the waveform based on the osc states
            for (int i = 0; i < sizeof(osc1States); i++){
                if (osc1States[i] == true){
                    myVoice->setWaveformOsc1(i+1);
                }
            }
            for (int i = 0; i < sizeof(osc2States); i++){
                if (osc2States[i] == true){
                    myVoice->setWaveformOsc2(i+1);
                }
            }
            
            
        }
    }
    
    buffer.clear();
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
