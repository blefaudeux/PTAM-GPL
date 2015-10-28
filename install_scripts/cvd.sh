#!/bin/sh
mkdir $2/lib
mkdir $2/cvd

cp $1/libcvd* $2/lib
cp $1/cvd/* $2/cvd

echo "CVD locally installed"
