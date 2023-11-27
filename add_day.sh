#!/usr/bin/bash

set -eu

usage()
{
  printf "Usage:\n"
  printf "\t-i: integer day\n"
  printf "\t-s: string day\n"
  printf "\t-t: string data type\n"
}

while getopts "i:s:t:" o; do
    case "${o}" in
        i)
            DAY_NUM=${OPTARG}
            if [[ $DAY_NUM -gt 25 ]]; then
              usage
              exit 1
            fi
            ;;
        s)
            DAY_STR=${OPTARG}
            ;;
        t)
            DAY_DATA_TYPE=${OPTARG}
            ;;
        *)
            usage
            exit 1
            ;;
    esac
done
shift $((OPTIND-1))

# directories
SRC_DIR=src
INCLUDE_DIR=include
INPUT_DIR=inputs
TEMPLATE_DIR=templates

# templates to copy
TEMPLATE_HPP=$TEMPLATE_DIR/_TEMPLATE.hpp
TEMPLATE_CPP=$TEMPLATE_DIR/_TEMPLATE.cpp

# src files to be created
NEW_HPP=$INCLUDE_DIR/$DAY_STR.hpp
NEW_CPP=$SRC_DIR/$DAY_STR.cpp
NEW_INPUT=$INPUT_DIR/$DAY_NUM.txt

for file in $NEW_HPP $NEW_CPP $NEW_INPUT
do
  if [ -f "$file" ]; then
    echo "$file already exists!"
    exit 1
  fi
done

STR_ALL_UPPER=${DAY_STR^^}
STR_CAPITALIZED=${DAY_STR^}

make_files()
{
  cp $TEMPLATE_HPP "$NEW_HPP"
  cp $TEMPLATE_CPP "$NEW_CPP"
  touch "$NEW_INPUT"
}

findReplace()
{
  file=$1
  sed -i "s/Template/${STR_CAPITALIZED}/g" "$file"
  sed -i "s/TEMPLATE/${STR_ALL_UPPER}/g" "$file"
  sed -i "s/template/${DAY_STR}/g" "$file"
  sed -i "s/X/${DAY_NUM}/g" "$file"
  sed -i "s/TYPE/${DAY_DATA_TYPE}/g" "$file"
}

make_files
findReplace "$NEW_HPP"
findReplace "$NEW_CPP"
