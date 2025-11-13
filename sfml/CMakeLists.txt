cmake_minimum_required(VERSION 3.10)
project(SFMLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Явное указание путей к стандартной библиотеке
include_directories(
    /opt/homebrew/include
    /Library/Developer/CommandLineTools/usr/include/c++/v1
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
)

link_directories(/opt/homebrew/lib)

# Библиотеки SFML
set(SFML_LIBRARIES
    sfml-graphics
    sfml-window
    sfml-system
)

add_executable(app src/main.cpp)
target_link_libraries(app ${SFML_LIBRARIES})
target_link_options(app PRIVATE -rpath /opt/homebrew/lib)

message(STATUS "SFML 3.0.2 configured successfully!")