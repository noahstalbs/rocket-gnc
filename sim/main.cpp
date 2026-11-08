#include <iostream>

#include "flight/flight_math.hpp"

int main() {
  // Placeholder proving sim links against flight code. Real physics in Phase 1.
  const double command = flight::clamp(1.7, 0.0, 1.0);
  std::cout << "rocket_sim alive: clamp(1.7, 0.0, 1.0) = " << command << "\n";
  return 0;
}
