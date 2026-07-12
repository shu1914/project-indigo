.DEFAULT_GOAL := debug

.PHONY: debug release run clean

debug:
	cmake --preset debug
	cmake --build build/debug

release:
	cmake --preset release
	cmake --build build/release

run: debug
	./build/debug/project_indigo

clean:
	rm -rf build