# Target name
set(target ToonEngine)

# Define

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/stdafx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonAlignedAllocator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonCamera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonFilesystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonLogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonMesh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonRenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonRoot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonString.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonSystemMessageBus.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonTimer.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/targetver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonAlignedAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonBitwise.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonBufferedAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonCamera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonCRC32Hash.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonDoubleEndedStackAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonEngineSystem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonExceptions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonFilesystem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonHeaderPostfix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonHeaderPrefix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonLogger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonMaterial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonMesh.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonNoncopyable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonObfuscator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonObject.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPlatform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPlugEngine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPoolAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonPrerequisites.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonReflection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonRenderSystem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonRoot.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonSingleton.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonStackAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonSTLAllocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonString.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonSystemMessage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonSystemMessageBus.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonTexture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonTimer.h
)

add_executable(ToonEngine ${SOURCES} ${INCLUDES})

target_include_directories(ToonEngine
PUBLIC
    ${library_dir}/spdlog/include 
	${library_dir}/glm
	${project_dir}/ToonRendersystem_GL3Plus/Includes
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(ToonEngine
PUBLIC
    
PRIVATE
    glfw3 opengl32     
)

set_target_properties(ToonEngine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h)
cotire(ToonEngine)