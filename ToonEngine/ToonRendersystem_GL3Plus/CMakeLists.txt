set(target ToonRenderSystem_GL3Plus)

add_library(rendersystem_gl3plus SHARED
    dllmain.cpp
    stdafx.cpp
    ToonGL3PlusEffect.cpp
    ToonGL3PlusFramebuffer.cpp
    ToonGL3PlusGBuffer.cpp
    ToonGL3PlusRenderSystem.cpp
)

target_include_directories(rendersystem_gl3plus
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(rendersystem_gl3plus
PRIVATE
    glfw3 opengl32     
)