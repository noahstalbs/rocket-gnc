include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

add_executable(flight_math_test
  flight_math_test.cpp
)

target_link_libraries(flight_math_test PRIVATE flight_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(flight_math_test)
