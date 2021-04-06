add_library(tuple tuple.cc)
target_include_directories(tuple PRIVATE ../include)
target_compile_options(tuple PRIVATE -Wall -Wextra -Werror)

add_library(canvas canvas.cc)
target_include_directories(canvas PRIVATE ../include)
target_compile_options(canvas PRIVATE -Wall -Wextra -Werror)

add_library(ppm ppm.cc)
target_include_directories(ppm PRIVATE ../include)
target_compile_options(ppm PRIVATE -Wall -Wextra -Werror)

add_library(matrix matrix.cc)
target_include_directories(matrix PRIVATE ../include)
target_compile_options(matrix PRIVATE -Wall -Wextra -Werror)
