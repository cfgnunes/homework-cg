cmake_minimum_required(VERSION 2.8)
project(paquito C)

# Freeglut Library
if(MINGW)
    set(GLUT_ROOT_PATH "C:/mingw32/i686-w64-mingw32")
endif()

# Dependencies
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR})

# Set compiler parameters
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s -O3 -Wall -Wextra -Wpedantic")

# Sources
file(GLOB SRC_FILES src/*.c src/*.h)

# Compile the main executable
if(WIN32)
    set(SRC_FILES ${SRC_FILES} windows-dist/resource.rc)
    add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SRC_FILES})
else()
    add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
endif()
target_link_libraries(${CMAKE_PROJECT_NAME} SOIL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} SDL2main SDL2 SDL2_mixer m)

# Define the files location during install process
if(WIN32)
    install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "/")
    install(DIRECTORY "resource" DESTINATION "resource")
    install(FILES "C:/mingw32/i686-w64-mingw32/bin/libfreeglut.dll" DESTINATION "/")
    install(FILES "C:/mingw32/i686-w64-mingw32/bin/SDL2.dll" DESTINATION "/")
    install(FILES "C:/mingw32/i686-w64-mingw32/bin/SDL2_mixer.dll" DESTINATION "/")
else()
    install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "bin")
    install(DIRECTORY "resource" DESTINATION "share/${CMAKE_PROJECT_NAME}/resource")
endif()

# Define the 'run' target
add_custom_target(run
    COMMAND ${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ../${CMAKE_PROJECT_DIR}
)
