#!/usr/bin/env bash
# usage: scripts/run_samples.sh stage_3 coin_combinations
bin="build/bin/$1/$2"
for in in data/$1/$2/*.in; do
  exp="${in%.in}.out"
  if diff -bB <("$bin" < "$in") "$exp" > /dev/null; then
    echo "PASS $in"
  else
    echo "FAIL $in"
  fi
done