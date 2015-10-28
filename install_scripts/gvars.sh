#!/bin/sh
mkdir $2/lib
mkdir $2/include

cp $1/libGVars* $2/lib
cp $1/gvars3/* $2/include

echo "GVars3 locally installed"
