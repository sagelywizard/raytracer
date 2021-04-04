add_executable(ppm_example ppm_example.cc)
target_link_libraries(ppm_example tuple canvas ppm)
target_include_directories(ppm_example PRIVATE ../include)
