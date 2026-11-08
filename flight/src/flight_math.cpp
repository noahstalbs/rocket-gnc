#include "flight/flight_math.hpp"

#include <cassert>

namespace flight {

double clamp(double value, double lo, double hi) {
  assert(lo <= hi);
  if (lo > hi) {
    return lo;
  }
  if (value < lo) {
    return lo;
  }
  if (value > hi) {
    return hi;
  }
  return value;
}

}  // namespace flight
