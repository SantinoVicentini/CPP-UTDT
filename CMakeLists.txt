cmake_minimum_required(VERSION 3.14)
project(wordle)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(m Ejercicio1/main.cpp)
add_executable(c Ejercicio1/calculadora.cpp)
add_executable(t Recursion/teo1.cpp)
add_executable(guia5 Recursion/guia5.cpp)




add_executable(
  wordle
  Wordle/wordle.cpp
  wordle/funciones.cpp
)

add_executable(
  tests
  tests/tests.cpp
  Wordle/funciones.cpp
)

target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
