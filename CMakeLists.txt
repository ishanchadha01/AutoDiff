cmake_minimum_required(VERSION 3.22)

project (AutoDiff)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_DIR src)
set(INCLUDE_DIRECTORIES include)

file(GLOB autodiff_SRC */*.cpp */*/*.cpp)

include_directories(include "/usr/local/include/eigen3")
add_executable(AutoDiff ${autodiff_SRC} ${INCLUDE_DIRECTORIES})

target_link_libraries(AutoDiff)
target_compile_features(AutoDiff PUBLIC cxx_std_17)