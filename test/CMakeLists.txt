set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cc)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})
target_compile_options(${BINARY} PRIVATE -Wall -Wextra -Werror -Wpedantic)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_include_directories(${BINARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(${BINARY} PUBLIC gtest tuple canvas ppm matrix)
