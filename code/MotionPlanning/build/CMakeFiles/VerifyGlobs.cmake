# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# motionPlanning_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/HSLAPixel.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/PNG.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/lidarPoint.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/lodepng/lodepng.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/pointCloud.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/lib/motionPlanning/sceneObject.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225FinalProject2022/code/MotionPlanning/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/KDTree.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/cluster.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/discreteGrid.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/fileReader.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/planner.cpp"
  "/workspaces/cs225FinalProject2022/code/MotionPlanning/src/visualize.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225FinalProject2022/code/MotionPlanning/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:131 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225FinalProject2022/code/MotionPlanning/tests/*.cpp")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225FinalProject2022/code/MotionPlanning/build/CMakeFiles/cmake.verify_globs")
endif()
