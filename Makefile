.PHONY: build test get-deps

# Don't use cmake -S . -B build, because it's not supported by old versions of
# cmake (including the version of cmake that's preinstalled on travis)
all:
	mkdir -p build
	cd build && cmake ../ -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

build-test:
	mkdir -p build
	cd build && cmake ../ -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --target raytracer_test

test: build-test
	./build/test/raytracer_test

debug-test: build
	lldb ./build/test/raytracer_test

get-deps:
	git submodule update --init --recursive

ppm-example: build
	./build/example/ppm_example
	open example.ppm
