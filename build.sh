#!/bin/bash

mkdir -p build
cd build
echo "Construindo..."
cmake ..
echo "Compilando..."
make


