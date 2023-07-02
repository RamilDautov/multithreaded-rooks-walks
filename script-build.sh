#!/bin/bash

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DENABLE_THREAD_SANITIZER=OFF
cmake --build build
