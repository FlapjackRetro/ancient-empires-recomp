#!/bin/sh
# One round of the recompile loop: merge the runtime's dispatch misses into
# work/misses.txt, re-lift, rebuild, and run a headless smoke test.
#   usage: tools/iterate.sh <game-dir> [extra empires args]
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
GAME=$1; shift
mkdir -p "$ROOT/out"
if [ -f "$ROOT/out/misses.txt" ]; then
  cat "$ROOT/work/misses.txt" "$ROOT/out/misses.txt" 2>/dev/null | sort -u > "$ROOT/work/misses.new"
  mv "$ROOT/work/misses.new" "$ROOT/work/misses.txt"; rm "$ROOT/out/misses.txt"
fi
PCRECOMP_HOME=${PCRECOMP_HOME:-/home/claude/pcrecomp} python3 -I "$ROOT/tools/lift_empires.py" | tail -2
cmake --build "$ROOT/build" -j8 2>&1 | grep -E "error|undefined" || true
cd "$ROOT/out" && "$ROOT/build/empires" --headless --game-dir "$GAME" "$@" 2>&1 | head -40
