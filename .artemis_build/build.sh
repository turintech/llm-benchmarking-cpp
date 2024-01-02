#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
source "$DIR/var.sh"

BUILD="make && $BEAR_EXECUTABLE -- make compile"
echo "Running: $BUILD"
eval $BUILD
