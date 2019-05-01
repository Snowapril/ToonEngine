set(target ToonRenderSystem_GL3Plus)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/stdafx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusEffect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusFramebuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusGBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonGL3PlusRenderSystem.cpp
)

set(INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusEffect.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusErrorCodes.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusFramebuffer.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusGBuffer.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusRenderSystem.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusUtil.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPlugGL3Plus.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusPrerequisites.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusPlatform.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonGL3PlusInputSystem.h
)

add_library(ToonRenderSystem_GL3Plus ${SOURCES} ${INCLUDES})

target_include_directories(ToonRenderSystem_GL3Plus
PUBLIC
    ${library_dir}/glfw/include
	${library_dir}/GL
	${library_dir}/fmt/include
	${library_dir}/glm/include
	${library_dir}/NvToolsExt/include
	${project_dir}/ToonEngine/Includes
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(ToonRenderSystem_GL3Plus
PRIVATE
    glfw3 opengl32     
)

set_target_properties(ToonRenderSystem_GL3Plus PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h)
cotire(ToonRenderSystem_GL3Plus)