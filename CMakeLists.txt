project(Test)

set ( CMAKE_C_FLAGS "--save-temps")

add_executable(${PROJECT_NAME} main.c)
