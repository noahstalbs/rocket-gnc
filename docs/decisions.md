# Decisions log

One line per decision: what we chose and WHY. Newest at the bottom.

- 2026-11-08 — clamp asserts lo <= hi and returns lo if that's violated in
  release. A reversed range is always a caller bug, so it should be loud in
  test; but asserts vanish under NDEBUG and flight code can never be left
  undefined, so the fallback is deterministic rather than UB. (Compile-time
  bounds variant skipped — two APIs for a three-line function isn't worth it
  yet; revisit if runtime-config bounds become common.)
