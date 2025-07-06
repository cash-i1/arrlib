#!/usr/bin/env bash
set -e
mkdir -p out/
clang tests.c ../arrlib.c -o out/test && out/test
