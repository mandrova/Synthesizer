#include "sine.h"
#include "math.h"
#include <iostream>

Sine::Sine() {
  // initialize members
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

void Sine::tick(double sampleRate_, double frequency_) {
  // TODO - frequency / samplerate can be implemented in a more efficient way
  phase += frequency_ / sampleRate_;
  sample = sin(M_PI * 2 * phase);

    //std::cout << "Sine - phase = \n" << phase;
    if (phase >= 1){
        phase -= 1;
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
