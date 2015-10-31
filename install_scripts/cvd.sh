#!/bin/sh
mkdir -p $2/lib
mkdir -p $2/cvd
mkdir -p $2/cvd/internal
mkdir -p $2/cvd/Linux

cp $1/libcvd* $2/lib
cp $1/cvd/* $2/cvd
cp $1/cvd/internal/* $2/cvd/internal/.
cp $1/cvd/Linux/* $2/cvd/Linux/.

echo "CVD locally installed"
