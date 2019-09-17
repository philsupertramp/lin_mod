#!/bin/bash
set -e

cmake -Wdev --deb-output --build=build/ .
make
./ccc
