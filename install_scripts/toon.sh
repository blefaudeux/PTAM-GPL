#!/bin/sh

mkdir $2/lib
mkdir $2/include

cp $1/libGVars* $2/lib
cp $1/gvars3/* $2/include

cp $1/*.h $2
cp -r $1/optimization $2/
cp -r $1/internal $2/
cp -r $1/functions $2/

echo "TooN locally installed"

