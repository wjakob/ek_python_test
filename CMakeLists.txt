# This script is fully compatible with a range of CMake versions
cmake_minimum_required(VERSION 3.13...3.18)

# Declare the project name and version
project(ek_python_test VERSION 0.0.1)

# Set a default build configuration (Release) if none was specified
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# Find suitable Python interpreter
if (SKBUILD)
  set(Python_EXECUTABLE ${PYTHON_EXECUTABLE})
else()
  find_package(Python COMPONENTS Interpreter Development REQUIRED)
endif()

# Add Python's site-packages directory to the search path, needed by the next step
execute_process(
  COMMAND "${Python_EXECUTABLE}" -c
    "import pybind11, os; print(os.path.dirname(os.path.dirname(pybind11.__file__)))"
  OUTPUT_VARIABLE EK_SITEPKG OUTPUT_STRIP_TRAILING_WHITESPACE
)
list(APPEND CMAKE_PREFIX_PATH "${EK_SITEPKG}")

# Find pybind11 and enoki
find_package(pybind11 CONFIG REQUIRED)
find_package(enoki    CONFIG REQUIRED)

# Compile the extension module
pybind11_add_module(_ek_python_test MODULE src/ek_python_test.cpp)

# Link against Enoki and the JIT compiler (enoki-autodiff also needed if AD is used)
target_link_libraries(_ek_python_test PRIVATE enoki enoki-jit)

# Install directives for skikit-build
install(DIRECTORY pysrc/ DESTINATION ./ek_python_test)
install(TARGETS _ek_python_test LIBRARY DESTINATION ek_python_test)
