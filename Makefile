.DEFAULT_GOAL := debug

.PHONY: debug release run test test-list ctest clean

debug:
	cmake --preset debug
	cmake --build build/debug

release:
	cmake --preset release
	cmake --build build/release

run: debug
	./build/debug/project_indigo

test: debug
	./build/debug/tests/project_indigo_tests

test-list: debug
	./build/debug/tests/project_indigo_tests --list-tests

ctest: debug
	ctest --test-dir build/debug --output-on-failure

clean:
	rm -rf build