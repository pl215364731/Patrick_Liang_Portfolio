#!/bin/bash
for n in 1 2 4 8
do
    mpic++ fourier.cpp -o fourier  -lm
    mpiexec -np $n fourier
done