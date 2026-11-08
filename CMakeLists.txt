cmake_minimum_required(VERSION 3.24)

project(rocket_gnc
  VERSION 0.1.0
  DESCRIPTION "3-DOF rocket flight software, simulator, and Monte Carlo harness"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)

enable_testing()

add_subdirectory(flight)
add_subdirectory(sim)
add_subdirectory(tests)

# --- flight/sim layering guard ----------------------------------------------
# flight/ must never depend on sim/: the same flight code has to run unchanged
# on a microcontroller where no simulator exists. Cross the boundary and the
# configure fails — not a code review six weeks later.
function(assert_flight_never_links_sim)
  get_property(flight_targets DIRECTORY flight PROPERTY BUILDSYSTEM_TARGETS)
  get_property(sim_targets DIRECTORY sim PROPERTY BUILDSYSTEM_TARGETS)
  foreach(flight_target IN LISTS flight_targets)
    get_target_property(link_deps ${flight_target} LINK_LIBRARIES)
    get_target_property(iface_deps ${flight_target} INTERFACE_LINK_LIBRARIES)
    set(deps "")
    if(link_deps)
      list(APPEND deps ${link_deps})
    endif()
    if(iface_deps)
      list(APPEND deps ${iface_deps})
    endif()
    foreach(dep IN LISTS deps)
      if(dep IN_LIST sim_targets)
        message(FATAL_ERROR
          "Layering violation: flight target '${flight_target}' depends on "
          "sim target '${dep}'. Flight code must never depend on sim code.")
      endif()
    endforeach()
  endforeach()
endfunction()
assert_flight_never_links_sim()
