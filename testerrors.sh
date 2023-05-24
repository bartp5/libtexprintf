#!/bin/bash

separate=`$utftex '\frac{\alp' 2>&1 | tail -n 3`
combined=`$utftex -E '\frac{\alp' 2>&1 | tail -n 2`

if test "$separate" != $'ERROR: Premature end of string (1x)\nERROR: Unknown command (1x)'; then
    echo "FAIL: separate"
    exit 1
fi

if test "$combined" != "ERRORS: Premature end of string (1x); Unknown command (1x)"; then
    echo "FAIL: combined"
    exit 1
fi
