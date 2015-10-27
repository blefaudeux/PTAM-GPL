#!/bin/sh
mkdir $2/lib
mkdir $2/include

cp $1/libcvd* $2/lib
cp $1/cvd/* $2/include

echo "CVD locally installed"
