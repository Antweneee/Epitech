#!/usr/bin/env bash
##
## EPITECH PROJECT, 2020
## build.sh
## File description:
## build.sh
##

#!/bin/sh

gcc -c *.c
ar rc libmy.a *.o
rm *.o
