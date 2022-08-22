cmake_minimum_required(VERSION 3.0.0)
project(Prueba VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)
add_executable(calc calculadora.cpp)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
