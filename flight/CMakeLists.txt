add_library(flight_core STATIC
  src/flight_math.cpp
)

target_include_directories(flight_core PUBLIC include)
