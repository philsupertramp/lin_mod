#!/bin/bash
set -e

cmake -Wdev --deb-output --build=build/ .
make

echo "build done, execute test?"
read input

if [[ $input == "y" || $input == "Y" ]]; then
  ./ccc-test
else
  ./ccc
fi

