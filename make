#!/bin/sh

echo "make-wrapper: running pmake $* in directory `pwd`"
exec pmake "$@"
