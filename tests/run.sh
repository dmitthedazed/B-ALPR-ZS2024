#!/usr/bin/env bash
# Compiles each lab solution with sanitizers and compares its stdout with
# tests/NN-name/expected. Every case may have a stdin file and extra input
# files that are copied next to the program before it runs.
# Usage: tests/run.sh [lab-dir-name ...]   UPDATE=1 tests/run.sh   rewrites expected files.
set -u
root=$(cd "$(dirname "$0")/.." && pwd)
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT

labs=("$@")
[ ${#labs[@]} -eq 0 ] && labs=($(cd "$root/tests" && ls -d [0-9][0-9]-*/ | tr -d /))

pass=0; fail=0
for lab in "${labs[@]}"; do
  src=$(ls "$root"/labs/"$lab"/riesenie-*.c)
  bin="$work/$lab"
  if ! gcc -std=c99 -g -fsanitize=address,undefined -fno-sanitize-recover=undefined \
       -o "$bin" "$src" -lm 2> "$work/gcc.txt"; then
    echo "FAIL $lab (does not compile)"; cat "$work/gcc.txt"; fail=$((fail+1)); continue
  fi
  run="$work/run-$lab"; mkdir -p "$run"
  cp "$root"/tests/"$lab"/* "$run"/ 2>/dev/null
  rm -f "$run/expected" "$run/stdin"
  stdin=/dev/null; [ -f "$root/tests/$lab/stdin" ] && stdin="$root/tests/$lab/stdin"
  (cd "$run" && timeout 10 "$bin" < "$stdin" > "$work/$lab.out" 2> "$work/$lab.err"); rc=$?
  if [ -s "$work/$lab.err" ] || [ $rc -ge 124 ]; then
    echo "FAIL $lab (exit $rc)"; head -5 "$work/$lab.err"; fail=$((fail+1)); continue
  fi
  if [ "${UPDATE:-0}" = 1 ]; then cp "$work/$lab.out" "$root/tests/$lab/expected"; fi
  if diff -u "$root/tests/$lab/expected" "$work/$lab.out" > "$work/$lab.diff"; then
    echo "ok   $lab"; pass=$((pass+1))
  else
    echo "FAIL $lab (output differs)"; head -15 "$work/$lab.diff"; fail=$((fail+1))
  fi
done
echo "$pass passed, $fail failed"
[ $fail -eq 0 ]
