#!/bin/sh

mkdir -p $2/TooN

cp $1/*.h $2/TooN/.
cp -r $1/optimization $2/TooN
cp -r $1/internal $2/TooN
cp -r $1/functions $2/TooN

echo "TooN locally installed"

