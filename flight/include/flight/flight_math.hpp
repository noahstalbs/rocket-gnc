#ifndef FLIGHT_FLIGHT_MATH_HPP
#define FLIGHT_FLIGHT_MATH_HPP

namespace flight {

// Clamps value to the range [lo, hi].
// Precondition: lo <= hi, asserted in debug builds. If violated in a release
// build, returns lo — flight code must never be left undefined. See
// docs/decisions.md (2026-11-08).
double clamp(double value, double lo, double hi);

}  // namespace flight

#endif  // FLIGHT_FLIGHT_MATH_HPP
