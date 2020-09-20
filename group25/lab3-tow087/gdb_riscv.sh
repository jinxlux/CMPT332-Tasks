#! /bin/bash
# CMPT 332 XV6-riscv testing script
# Written by Jason Goertzen 2019
#
# Move this script to the root of your xv6-riscv directory

export GDB=/student/cmpt332/xv6/prefix/bin/riscv64-unknown-elf-gdb

$GDB kernel/kernel
