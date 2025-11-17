#!/bin/sh
mkdir -p m4
export AUTOMAKE="automake --foreign -a"
autoreconf -f -i
