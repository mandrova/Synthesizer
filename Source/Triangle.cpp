/*
  ==============================================================================

    Triangle.cpp
    Created: 27 Jun 2020 1:18:36pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "Triangle.h"
#include <stdio.h>
#include "math.h"
#include "Maximilian/maximilian.h"

Triangle::Triangle(){
    
}

Triangle::~Triangle(){
    
}

void Triangle::tick(double sampleRate_, float frequency){
    //This is a triangle wave.
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(maxiSettings::sampleRate/(frequency)));
    if (phase <= 0.5 ) {
        sample =(phase - 0.25) * 4;
    } else {
        sample =((1.0-phase) - 0.25) * 4;
    }
}

//returning the last made sample
float Triangle::getSample(){
    return sample;
}
