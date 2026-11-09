#ifndef SIM_STATE_HPP
#define SIM_STATE_HPP

namespace sim {

// Ground-truth rocket state at one instant. 3-DOF: vertical, downrange, pitch.
//
// Units are SI and radians, everywhere, always — degrees exist only in logs
// and plots. Pitch is measured from vertical: 0 = straight up, positive tips
// the nose downrange (+x). See docs/decisions.md (2026-11-09).
//
// Flight software never sees this struct. It receives noisy sensor readings
// and spends the whole flight trying to estimate these values.
struct State {
  double t_s = 0.0;             // time since ignition [s]
  double alt_m = 0.0;           // altitude above launch pad [m]
  double downrange_m = 0.0;     // horizontal distance from pad [m]
  double vz_mps = 0.0;          // vertical velocity, up positive [m/s]
  double vx_mps = 0.0;          // horizontal velocity, downrange positive [m/s]
  double pitch_rad = 0.0;       // angle from vertical, downrange tilt positive [rad]
  double pitch_rate_radps = 0.0; // d(pitch)/dt [rad/s]
  double mass_kg = 0.0;         // vehicle mass incl. remaining propellant [kg]
};

}  // namespace sim

#endif  // SIM_STATE_HPP
