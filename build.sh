#!/bin/bash
# (c) 2015, http://www.banana-pi.org/
# Build script for BPI-Kernel4.1.X

echo "=========================================="
echo -e "\033[41;37m  BPI-Kernel4.1.X Image Build Tool     \033[0m"
echo "=========================================="
echo
echo "This tool support following BPI board(s):"
echo "------------------------------------------"
echo "	1. BPI-M1"
echo "	2. BPI-M1-Plus"
echo "	3. BPI-M2"
echo "	4. BPI-R1"
echo "------------------------------------------"
read -p "Please choose a target(1-4): " choice
echo

echo -e "\033[31m Now building u-boot...\033[0m"
echo
cd ./u-boot-2015.07
case $choice in
	1) ./bpi-m1.sh;;
	2) ./bpi-m1-plus.sh;;
	3) ./bpi-m2.sh;;
	4) ./bpi-r1.sh;;
esac
echo
echo -e "\033[31m Building u-boot success!\033[0m"
echo

echo
echo -e "\033[31m Now building linux...\033[0m"
echo
cd ../linux-4.1.x
./build.sh
echo -e "\033[31m Building linux success!\033[0m"

cd ./output/bpi
ls
