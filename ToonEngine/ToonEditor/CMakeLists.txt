# Target name
set(target ToonEditor)

add_executable(toonengine
    LuaEngine.cpp
    main.cpp
    stdafx.cpp
    ToonRoot.cpp
)

target_include_directories(toonengine
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(toonengine
PUBLIC
    
PRIVATE
    glfw3 opengl32     
)