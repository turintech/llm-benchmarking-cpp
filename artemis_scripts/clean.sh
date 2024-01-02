#!/bin/bash     

# Import variables
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
source "$DIR/variables.sh"

# Populate CLEAN with the clean command
CLEAN="make clean"
echo "Running clean command: $CLEAN"
eval $CLEAN
