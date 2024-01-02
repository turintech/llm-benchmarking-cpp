#!/bin/bash     

# Import variables
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
source "$DIR/variables.sh"

# Populate TEST with the test command
TEST="build/tests/tests [test]"
echo "Running test command: $TEST"
eval $TEST
