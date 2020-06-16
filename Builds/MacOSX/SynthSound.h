/*
  ==============================================================================

    SynthSound.h
    Created: 16 Jun 2020 10:56:04am
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int /*midiNoteNumber*/){
        return true;
    }
    
    bool appliesToChannel(int /*midiChannel*/){
        return true;
    }
};
