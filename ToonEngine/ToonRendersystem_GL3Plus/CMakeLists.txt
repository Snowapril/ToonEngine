set(target ToonRendersystem_GL3Plus)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Sources/dllmain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/stdafx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusEffect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusFramebuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusGBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusRenderSystem.cpp
)

set(INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/targetver.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusEffect.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusErrorCodes.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusFramebuffer.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusGBuffer.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusRenderSystem.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusUtil.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPlugGL3Plus.h
)

add_library(ToonRendersystem_GL3Plus SHARED ${SOURCES} ${INCLUDES})

target_include_directories(ToonRendersystem_GL3Plus
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(ToonRendersystem_GL3Plus
PRIVATE
    glfw3 opengl32     
)