cmake_minimum_required(VERSION 3.25)

project (AutoDiff)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR src)
set(INCLUDE_DIRECTORIES include)

file(GLOB autodiff_SRC */*.cpp)
find_package( Eigen3 REQUIRED )

include_directories(include Eigen3)
add_executable(AutoDiff ${autodiff_SRC} ${INCLUDE_DIRECTORIES})

target_link_libraries(AutoDiff)
target_compile_features(AutoDiff PUBLIC cxx_std_17)