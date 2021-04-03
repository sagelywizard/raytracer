.PHONY: build test

build:
	cmake -B build . -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

test: build
	./build/test/raytracer_test
