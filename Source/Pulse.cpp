//
//  Pulse.cpp
//  SynthVST - Shared Code
//
//  Created by Nick Verbeek on 15/06/2020.
//

#include <stdio.h>
#include "Pulse.h"
#include "math.h"

Pulse::Pulse(){
    
}

Pulse::~Pulse(){
    
}

void Pulse::tick(){
    //generating a square wave
    if (phase<0.5) sample=-1;
    if (phase>0.5) sample=1;
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(sampleRate/(frequency)));
}
