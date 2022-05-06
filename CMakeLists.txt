cmake_minimum_required(VERSION 3.22)

########################################
set(MY_PROJECT "my-sln")
project(${MY_PROJECT})

########################################
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)

########################################
add_subdirectory(my-exe)
add_subdirectory(my-lib)
add_subdirectory(my-dyn-exe)

