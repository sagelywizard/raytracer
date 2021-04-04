.PHONY: build test get-deps

build:
	mkdir -p build
	# Don't use cmake -S . -B build, because it's not supported by old versions of
	# cmake (including the version of cmake that's preinstalled on travis)
	cd build && cmake ../ -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

test: build
	./build/test/raytracer_test

get-deps:
	git submodule update --init --recursive

