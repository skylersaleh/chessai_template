
cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+

project(ChessTemplate)

# These settings control how the chess engine will advertise itself 
# to applications that use it.

add_compile_definitions(CHESS_ENGINE_NAME="ChessAI Example")
add_compile_definitions(CHESS_ENGINE_AUTHOR="Skyler Saleh")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ") 

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c 
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp 
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
 
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/util
  ${CMAKE_CURRENT_SOURCE_DIR}/src/
  ${CMAKE_CURRENT_SOURCE_DIR}/src/util/deps/tinycthread
)
 
