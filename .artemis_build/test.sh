#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
source "$DIR/var.sh"

TEST="build/tests/tests [test]"
echo "Running: $TEST"
eval $TEST

