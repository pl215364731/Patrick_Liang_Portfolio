#!/bin/bash
for n in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608
do
  g++  project_4.cpp  -DARRAYSIZE=$n  -o project_4  -lm  -fopenmp
  ./project_4
done