# Competitive Programmer's Handbook: Roadmap

My working repository for studying **Competitive Programmer's Handbook** by Antti Laaksonen. The goal is not to finish the book but to get measurably better at solving problems. Every chapter is read, re-derived, implemented from scratch in C++, tested, and then practiced on real problems.

## Roadmap

| Stage | Topic | Book chapters |
|-------|-------|---------------|
| 0 | Foundations, efficiency, programming techniques | Introduction, Programming techniques, Efficiency |
| 1 | Sorting, searching, data structures | Sorting and searching, Data structures, Amortized analysis |
| 2 | Complete search, greedy, bit tricks, range queries | Complete search, Greedy algorithms, Bit manipulation, Range queries |
| 3 | Dynamic programming | Dynamic programming |
| 4 | Graph fundamentals | Basics of graphs, Graph traversal, Shortest paths, Spanning trees, Tree algorithms, Directed graphs |
| 5 | Advanced graphs and trees | Strong connectivity, Tree queries, Paths and circuits, Flows and cuts |
| 6 | Mathematics | Number theory, Combinatorics, Matrices, Probability, Game theory |
| 7 | Strings, sqrt, advanced data structures, geometry | String algorithms, Square root algorithms, More segment trees, Geometry, Sweep line |

After Stage 7 comes ongoing contest practice and upsolving (solving the problems I failed in a contest afterwards).

Each stage is only completed after passing its own progress check: a set of problems solved, algorithms rewritten from memory, and a speed target.

## Repository structure

```
.
├── CMakeLists.txt
├── README.md
├── docs/
│   └── NOTES.md              study notes and problem log
├── data/                     sample inputs and expected outputs
│   └── stage_N/<problem>/
│       ├── 1.in
│       └── 1.out
├── scripts/
│   └── run_samples.sh        runs a solution against its data/ cases
└── src/
    ├── stages/stage_N/       algorithms (.hpp) and problem solutions (.cpp)
    └── tests/test_N/         GoogleTest tests for stage N
```

### Conventions

- **Algorithms** (DSU, Fenwick tree, `modpow`, sieve, ...) are header files (`.hpp`) in `src/stages/stage_N/`. They can be included by tests and by other solutions.
- **Solutions** are standalone `.cpp` files in `src/stages/stage_N/`, each with its own `main()`. Every one becomes its own executable.
- **Tests** are `test_*.cpp` files in `src/tests/test_N/`. Each folder becomes one GoogleTest executable that includes headers as `#include "stage_N/header.hpp"`.
- **Sample cases** live in `data/stage_N/<problem_name>/` as `1.in` / `1.out`, `2.in` / `2.out`, and so on.

## Requirements

- A C++17 compiler (GCC or Clang)
- CMake 3.16 or newer (3.20+ for `ctest --test-dir`)
- GoogleTest. It is found automatically if installed; otherwise CMake downloads it on first configure (internet needed once).

## Build and run

Configure once:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Rebuild after every change:

```bash
cmake --build build -j
```

Run a solution:

```bash
./build/bin/stage_3/coin_combinations < data/stage_3/coin_combinations/1.in
```

Run a solution against all its sample cases:

```bash
scripts/run_samples.sh stage_3 coin_combinations
```

Run the tests:

```bash
ctest --test-dir build --output-on-failure   # all stages
./build/bin/tests/test_3                     # only stage 3
```

Build only one target:

```bash
cmake --build build --target stage_3_coin_combinations
```

Fast Release build for timing:

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release -j
```

Debug builds enable AddressSanitizer and UndefinedBehaviorSanitizer, which catch out-of-bounds access and overflow bugs early. Turn this off with `-DCP_SANITIZERS=OFF`. To add a stage 8 folder, configure with `-DCP_LAST_STAGE=8`.

## Workflow for each chapter

1. Read the chapter once, slowly, with pen and paper.
2. Close the book and re-derive the key idea.
3. Implement the algorithm from scratch in `src/stages/stage_N/` and write tests for it in `src/tests/test_N/`.
4. Solve the problems for that stage (CSES first, then Codeforces and LeetCode).
5. Log each problem in `docs/NOTES.md`: idea, trick, complexity, mistakes.
6. Re-solve a few problems after 3-7 days without looking at the notes.

## Resources

- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) (free PDF)
- [CSES Problem Set](https://cses.fi/problemset/): the main practice source, by the same author
- [cp-algorithms](https://cp-algorithms.com/): extra explanations and proofs
- [USACO Guide](https://usaco.guide/): structured topic pages
- [Codeforces](https://codeforces.com/) and [LeetCode](https://leetcode.com/): contests and extra problems
