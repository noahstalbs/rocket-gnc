add_executable(rocket_sim
  main.cpp
)

target_include_directories(rocket_sim PRIVATE include)
target_link_libraries(rocket_sim PRIVATE flight_core)
