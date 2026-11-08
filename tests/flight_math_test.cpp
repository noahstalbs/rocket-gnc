#include "flight/flight_math.hpp"

#include <gtest/gtest.h>

TEST(Clamp, PassesThroughValueInRange) {
  EXPECT_DOUBLE_EQ(flight::clamp(0.5, 0.0, 1.0), 0.5);
}

TEST(Clamp, ClampsValueBelowLo) {
  EXPECT_DOUBLE_EQ(flight::clamp(-2.0, 0.0, 1.0), 0.0);
}

TEST(Clamp, ClampsValueAboveHi) {
  EXPECT_DOUBLE_EQ(flight::clamp(1.7, 0.0, 1.0), 1.0);
}

TEST(Clamp, BoundsAreInclusive) {
  EXPECT_DOUBLE_EQ(flight::clamp(0.0, 0.0, 1.0), 0.0);
  EXPECT_DOUBLE_EQ(flight::clamp(1.0, 0.0, 1.0), 1.0);
}

// The reversed-range decision (docs/decisions.md 2026-11-08) has two halves,
// each only observable in one build type.
#ifndef NDEBUG
TEST(ClampDeathTest, ReversedRangeAssertsInDebug) {
  EXPECT_DEATH(flight::clamp(5.0, 10.0, 2.0), "lo <= hi");
}
#else
TEST(Clamp, ReversedRangeReturnsLoInRelease) {
  EXPECT_DOUBLE_EQ(flight::clamp(5.0, 10.0, 2.0), 10.0);
}
#endif
