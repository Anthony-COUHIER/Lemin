#!/bin/sh
BIN=./lem_in
BAD=./bonus/tests_fonctionnel

execution() {
    echo -e "\033[1;34m$1\033[00m"
    $BIN < $BAD/$1
    echo
}

echo -e "\033[1;31mBAD\033[00m"
execution bad/double_end
execution bad/double_start
execution bad/no_end
execution bad/no_start
execution bad/number_ants
echo -e "\033[1;31mGOOD\033[00m"
execution good
