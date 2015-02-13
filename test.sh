#!/bin/bash
# Script for testing mycp.c

echo "Calling mycp test.txt test.txt.bak"
./mycp test.txt test.txt.bak

echo "Checking that the two files are the same"
diff test.txt test.txt.bak
