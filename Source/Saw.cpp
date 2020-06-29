/*
  ==============================================================================

    Saw.cpp
    Created: 27 Jun 2020 1:18:42pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "Saw.h"
#include <stdio.h>
#include "math.h"

Saw::Saw(){
    
}

Saw::~Saw(){
    
}

void Saw::tick(){
    sample=phase;
    if ( phase >= 1.0 ) phase -= 2.0;
    phase += (1./(sampleRate/(frequency))) * 2.0;
}
