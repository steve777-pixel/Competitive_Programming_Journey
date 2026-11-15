# Notes for the Journey

- Solutions: every .cpp under a stage folder becomes its own executable, 
e.g. build/bin/stage_3/coin_combinations.

# Notes for Running the Build

- First time (configure once)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

- After every change (build everything):
cmake --build build -j (Why j ???)

- Build and run only what you’re working on:
cmake --build build --target stage_3_coin_combinations
./build/bin/stage_3/coin_combinations < data/stage_3/coin_combinations/1.in

- Run all tests, or only one stage’s:
ctest --test-dir build --output-on-failure
./build/bin/tests/test_3

- Fast Release build for timing, kept in its own folder:
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release -j

- A one-liner for the edit, build and test loop:
cmake --build build -j && ctest --test-dir build --output-on-failure