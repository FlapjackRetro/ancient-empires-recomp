#!/bin/sh
# Re-lift/rebuild/run a scripted session N times, accumulating dispatch misses.
#   usage: tools/playtest.sh <game-dir> <rounds> <seconds> "<key script>"
ROOT=$(cd "$(dirname "$0")/.." && pwd)
GAME=$1; ROUNDS=$2; SECS=$3; KEYS=$4
i=1
while [ $i -le "$ROUNDS" ]; do
  echo "== round $i"
  rm -rf "$ROOT/out/shots"; mkdir -p "$ROOT/out/shots"
  "$ROOT/tools/iterate.sh" "$GAME" --max-seconds "$SECS" --frame-dir "$ROOT/out/shots" --frame-every 1000000 --keys "$KEYS" 2>&1 | grep -v "^\[dos\] open" | tail -6
  i=$((i+1))
done
