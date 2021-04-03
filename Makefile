.PHONY: build test get-deps

build:
	mkdir -p build
	cd build && cmake ../ -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

test: build
	./build/test/raytracer_test

get-deps:
	git submodule update --init --recursive

