#!/bin/bash

# Compile the pipex program
make re

# Test 1: Single word match
echo "This is a test file." > infile
./pipex infile "grep test" "wc -l" outfile
EXPECTED_OUTPUT="1"
ACTUAL_OUTPUT=$(cat outfile | tr -d ' ')
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 1 passed."
else
    echo "Test 1 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Test 2: No match
echo "This is a test file." > infile
./pipex infile "grep no_match" "wc -l" outfile
EXPECTED_OUTPUT="0"
ACTUAL_OUTPUT=$(cat outfile | tr -d ' ')
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 2 passed."
else
    echo "Test 2 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Test 3: Multiple matches
echo -e "This is a test file.\nAnother test line.\nYet another test line." > infile
./pipex infile "grep test" "wc -l" outfile
EXPECTED_OUTPUT="3"
ACTUAL_OUTPUT=$(cat outfile | tr -d ' ')
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 3 passed."
else
    echo "Test 3 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Test 4: Multiple commands
echo -e "This is a test file.\nAnother test line.\nYet another test line." > infile
./pipex infile "grep test" "awk" "'{print $1}'" outfile
EXPECTED_OUTPUT="This\nAnother\nYet"
ACTUAL_OUTPUT=$(cat outfile)
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 4 passed."
else
    echo "Test 4 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Test 5: Case insensitive search
echo -e "This is a Test file.\nAnother test line.\nYet another Test line." > infile
./pipex infile "grep -i test" "wc -l" outfile
EXPECTED_OUTPUT="3"
ACTUAL_OUTPUT=$(cat outfile | tr -d ' ')
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 5 passed."
else
    echo "Test 5 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Test 6: Word count
echo -e "This is a test file.\nAnother test line.\nYet another test line." > infile
./pipex infile "cat" "wc -w" outfile
EXPECTED_OUTPUT="12"
ACTUAL_OUTPUT=$(cat outfile | tr -d ' ')
if [ "$EXPECTED_OUTPUT" = "$ACTUAL_OUTPUT" ]; then
    echo "Test 6 passed."
else
    echo "Test 6 failed. Expected '$EXPECTED_OUTPUT', but got '$ACTUAL_OUTPUT'."
fi

# Clean up
rm infile outfile