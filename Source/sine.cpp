#include "sine.h"
#include "math.h"
#include <iostream>
#include "Maximilian/maximilian.h"

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
  sample=sin (phase*(M_PI * 2));
    
  if ( phase >= 1.0 ) phase -= 1.0;
  phase += (1./(maxiSettings::sampleRate/(frequency_)));
    
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

//returning the last made sample
float Sine::getFrequency()
{
  return frequency;
}
