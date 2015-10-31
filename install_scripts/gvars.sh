#!/bin/sh
mkdir -p $2/lib
mkdir -p $2/gvars3

cp $1/libGVars* $2/lib
cp $1/gvars3/* $2/gvars3

echo "GVars3 locally installed"
