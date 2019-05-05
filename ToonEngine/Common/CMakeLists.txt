# Target name
set(target Common)

set(SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

add_executable(Common ${SOURCES})

target_include_directories(Common
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
	${CMAKE_CURRENT_SOURCE_DIR}/Precompiled
)

target_link_libraries(Common
PUBLIC
    
PRIVATE

)