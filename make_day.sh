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
            num=${OPTARG}
            if [[ $num -gt 25 ]]; then
              usage
              exit 1
            fi
            ;;
        s)
            str=${OPTARG}
            ;;
        t)
            dataType=${OPTARG}
            ;;
        *)
            usage
            exit 1
            ;;
    esac
done
shift $((OPTIND-1))

if [ -z "${num}" ] || [ -z "${str}" ] || [ -z "${dataType}" ]; then
    usage
fi


TEMPLATE_DIR=templates
TEMPLATE_HEADER=$TEMPLATE_DIR/_TEMPLATE.hpp
TEMPLATE_SRC=$TEMPLATE_DIR/_TEMPLATE.cpp
HEADER=days/$str.hpp
SRC=$str.cpp

if [ -f "$SRC" ] || [ -f "$HEADER" ]; then
  echo "$SRC or $HEADER already exists!"
  exit 1
fi

strAllUpper=${str^^}
strCapitalized=${str^}

make_files()
{
  cp $TEMPLATE_HEADER $HEADER
  cp $TEMPLATE_SRC $SRC
}

findReplace()
{
  file=$1
  sed -i "" "s/Template/${strCapitalized}/g" "$file"
  sed -i "" "s/TEMPLATE/${strAllUpper}/g" "$file"
  sed -i "" "s/template/${str}/g" "$file"
  sed -i "" "s/X/${num}/g" "$file"
  sed -i "" "s/TYPE/${dataType}/g" "$file"
}

make_files
findReplace "$HEADER"
findReplace "$SRC"
