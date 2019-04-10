set(target ToonResourceParser)


set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/constexpr/vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/constexpr/string.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/constexpr/map.h
)

add_library(ToonResourceParser SHARED ${SOURCES} ${INCLUDES})

target_include_directories(ToonResourceParser
PUBLIC
    # ${CMAKE_SOURCE_DIR}/
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(ToonResourceParser
PRIVATE
)