# Path definitions.
set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add motionPlanning library.
set(motionPlanning_dir ${lib_dir}/motionPlanning)
file(GLOB_RECURSE motionPlanning_sources CONFIGURE_DEPENDS ${motionPlanning_dir}/*.cpp)
add_library(motionPlanning ${motionPlanning_sources})
target_include_directories(motionPlanning PRIVATE ${lib_dir})

# Add overall libs library.
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE ${lib_dir})
target_link_libraries(libs INTERFACE motionPlanning)