#!/bin/bash
set -e

cmake -Wdev --deb-output --build=build/ .
make

if [ ! $CI ]; then
  echo "build done, execute test?"
  read input

  if [[ $input == "y" || $input == "Y" ]]; then
    ./ccc-test
  else
    ./ccc
  fi
else
  ./ccc-test
fi

