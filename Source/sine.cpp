#include "sine.h"
#include "math.h"
#include <iostream>
#include "Maximilian/maximilian.h"

Sine::Sine() {
  // initialize members
    sample = 0;
    phase = 0;
}

Sine::~Sine() {
}

void Sine::tick() {
  // TODO - frequency / samplerate can be implemented in a more efficient way
  sample=sin (phase*(M_PI * 2));
    
  if ( phase >= 1.0 ) phase -= 1.0;
  phase += (1./(sampleRate/(frequency)));
}
