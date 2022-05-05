cmake_minimum_required(VERSION 3.22)

########################################
set(MY_PROJECT "my-dyn-exe")
project(${MY_PROJECT} LANGUAGES C CXX)

########################################
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)


########################################
file(GLOB MY_SOURCES 
${CMAKE_CURRENT_LIST_DIR}/src/*.h
${CMAKE_CURRENT_LIST_DIR}/src/*.c
${CMAKE_CURRENT_LIST_DIR}/src/*.cpp

${CMAKE_CURRENT_LIST_DIR}/src/*.asm
${CMAKE_CURRENT_LIST_DIR}/src/*.S

${CMAKE_CURRENT_LIST_DIR}/src/*.f
${CMAKE_CURRENT_LIST_DIR}/src/*.f90
)

add_executable(${MY_PROJECT} ${MY_SOURCES})
add_dependencies(${MY_PROJECT} my-lib)
########################################
target_compile_definitions(${MY_PROJECT} PRIVATE MY_DYN_EXE_12289358_CC47_11EC_8243_47E9D2D6E4D5)

if(NOT "${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
#target_compile_options(${MY_PROJECT} PRIVATE )
target_compile_definitions(${MY_PROJECT} PRIVATE MY_WINDOWS_SOURCES)
else()
target_compile_options(${MY_PROJECT} PRIVATE -fvisibility=hidden)
target_compile_definitions(${MY_PROJECT} PRIVATE MY_LINUX_SOURCES)
endif()


target_include_directories(${MY_PROJECT} 
PRIVATE 
${CMAKE_CURRENT_LIST_DIR}/../common 
${CMAKE_CURRENT_LIST_DIR}/public
${CMAKE_CURRENT_LIST_DIR}/../my-lib/public
)


target_link_directories(${MY_PROJECT} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/install/lib)
target_link_libraries(${MY_PROJECT} PRIVATE my-lib)
#target_link_options(${MY_PROJECT} PRIVATE)


########################################
install(TARGETS ${MY_PROJECT})

