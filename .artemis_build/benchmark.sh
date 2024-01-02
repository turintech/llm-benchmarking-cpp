#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
source "$DIR/var.sh"

BENCHMARK="build/tests/tests [benchmark]"
echo "Running: $BENCHMARK"
eval $BENCHMARK


