# Decisions log

One line per decision: what we chose and WHY. Newest at the bottom.

- 2026-11-08 — clamp asserts lo <= hi and returns lo if that's violated in
  release. A reversed range is always a caller bug, so it should be loud in
  test; but asserts vanish under NDEBUG and flight code can never be left
  undefined, so the fallback is deterministic rather than UB. (Compile-time
  bounds variant skipped — two APIs for a three-line function isn't worth it
  yet; revisit if runtime-config bounds become common.)
- 2026-11-08 — GoogleTest via FetchContent, pinned to v1.17.0. A clean clone must build with no pre-installed deps, and a pinned tag means every clone builds the identical dependency — floating branches make builds non-reproducible.
- 2026-11-09 — pitch measured from vertical (0 = straight up), positive tips
  the nose downrange. Rockets fly near vertical early, so angles stay small
  and readable; the convention lives in state.hpp and is never mixed.
- 2026-11-09 — SI units + radians internally; every physical variable name
  carries a unit suffix (alt_m, vz_mps). Degrees only in plots/logs. Units
  mix-ups are the canonical spacecraft killer (Mars Climate Orbiter);
  suffixes make them visible at every use site.
