set(target ToonResourceParser)

set(SOURCES
)

set(INCLUDES
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