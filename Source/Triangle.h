/*
  ==============================================================================

    Triangle.h
    Created: 27 Jun 2020 1:18:36pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once
class Triangle{
    
    
public:
    Triangle();
    ~Triangle();
    
    void tick(double, float);
    float getSample();
    
    
private:
    float samplerate;
    float phase;
    float sample;
    float frequency;
};
