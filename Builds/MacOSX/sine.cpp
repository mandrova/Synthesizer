#include "sine.h"
#include "math.h"
#include <iostream>

Sine::Sine(float frequency, float samplerate) {
  // initialize members
  this->frequency = frequency;
  this->samplerate = samplerate;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // TODO - frequency / samplerate can be implemented in a more efficient way
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase);
    //std::cout << "Sine - phase = \n" << phase;
    //sample = 0.9 * (4/M_PI * (1/1) * sin((1*M_PI)*phase) + (4/M_PI) * (1/3) * sin(3*M_PI*phase) + (4/M_PI) * (5/1) * sin(5*M_PI*phase) + (4/M_PI) * (1/7) * sin(7*M_PI*phase)) ;
    if (phase >= 1){
        phase = phase - 1;
    }
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
