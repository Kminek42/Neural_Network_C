#!/bin/bash

gcc $(cat filelist.txt) -Wall -O3 -o a.out
./a.out
