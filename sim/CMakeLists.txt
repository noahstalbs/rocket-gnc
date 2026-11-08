add_executable(rocket_sim
  main.cpp
)

target_link_libraries(rocket_sim PRIVATE flight_core)
