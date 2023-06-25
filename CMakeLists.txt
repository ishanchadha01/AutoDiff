cmake_minimum_required(VERSION 3.25)

project (AutoDiff)

set(SOURCE_DIR src)
set(INCLUDE_DIRECTORIES include)

include_directories(include)
add_executable(main ${SOURCE_DIR}/main.cpp ${INCLUDE_DIRECTORIES})

# target_include_directories(main PUBLIC ${INCLUDE_DIRECTORIES})