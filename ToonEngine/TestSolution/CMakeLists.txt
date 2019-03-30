# Target name
set(target TestSolution)

set(SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

add_executable(TestSolution ${SOURCES})

target_include_directories(TestSolution
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(TestSolution
PUBLIC
    
PRIVATE
    glfw3 opengl32     
)