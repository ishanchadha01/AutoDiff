cmake_minimum_required(VERSION 3.25)

project (AutoDiff)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR src)
set(INCLUDE_DIRECTORIES include)

include_directories(include)
add_executable(AutoDiff ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/operator.cpp ${INCLUDE_DIRECTORIES})

target_link_libraries(AutoDiff)
target_compile_features(AutoDiff PUBLIC cxx_std_17)