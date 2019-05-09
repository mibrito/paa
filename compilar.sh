#!/usr/bin/env bash

# creates output directory
if [ ! -d "./bin" ]; then
  mkdir ./bin
fi

# change directory to ./src
cd ./src

# compile everything
make

# move executable for ./directory
mv tp2 ../bin

#change directory back
cd ..

if [ -e "./bin/tp2" ]; then
  echo "Success: executable 'tp2' placed inside ./bin"
else
  echo "Error: something bad happend"
fi
