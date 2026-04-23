#AppName


set(
    src
    src/main.cpp
    src/Menu.cpp
    src/Terminal.cpp
    src/Application.cpp
    src/MyMath.cpp
)

add_executable(${AppName} ${src})
target_include_directories(${AppName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_options(${AppName} PUBLIC -static -static-libgcc -static-libstdc++)
