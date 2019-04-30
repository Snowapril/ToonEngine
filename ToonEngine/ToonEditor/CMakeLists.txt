# Target name
set(target ToonEditor)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Sources/LuaEngine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/stdafx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ToonRoot.cpp
)

set(INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/LuaEngine.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h
	${CMAKE_CURRENT_SOURCE_DIR}/Includes/ToonRoot.h
)

set(ENV{PATH} ${library_dir}/dll)

add_executable(ToonEditor ${SOURCES} ${INCLUDES})

target_include_directories(ToonEditor
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(ToonEditor
PUBLIC
    
PRIVATE
    glfw3 opengl32     
)

set_target_properties(ToonEditor PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${CMAKE_CURRENT_SOURCE_DIR}/Includes/stdafx.h)
cotire(ToonEditor)