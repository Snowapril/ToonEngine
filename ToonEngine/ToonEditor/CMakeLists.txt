# Target name
set(target ToonEditor)

set(project_include_py ${project_dir}/Scripts/ProjectInclude.py)
add_custom_command(
    COMMAND python ${project_include_py}
)

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

file(GLOB IMGUI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*
)

set(ENV{PATH} ${library_dir}/dll)

add_executable(ToonEditor ${SOURCES} ${INCLUDES} ${IMGUI_SRC})

target_include_directories(ToonEditor
PUBLIC
	${project_dir}/ToonEngine/Includes
	${project_dir}/ToonResourceParser/Includes
	${project_dir}/Common/Includes
	${library_dir}/sol2/single
	${library_dir}/spdlog/include
	${library_dir}/luajit/src
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
	${CMAKE_CURRENT_SOURCE_DIR}/Precompiled
)

target_link_libraries(ToonEditor
PUBLIC
    
PRIVATE
    glfw3 opengl32     
)

set_target_properties(ToonEditor PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${CMAKE_CURRENT_SOURCE_DIR}/Precompiled/stdafx.h)
cotire(ToonEditor)