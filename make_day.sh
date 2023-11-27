set -eu

usage()
{
  printf "Usage:\n"
  printf "\t-i: integer day\n"
  printf "\t-s: string day\n"
}

while getopts "i:s:" o; do
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
        *)
            usage
            exit 1
            ;;
    esac
done
#shift $((OPTIND-1))

if [ -z "${num}" ] || [ -z "${str}" ]; then
    usage
fi


TEMPLATE_DIR=templates
TEMPLATE_HEADER=$TEMPLATE_DIR/_TEMPLATE.hpp
TEMPLATE_SRC=$TEMPLATE_DIR/_TEMPLATE.cpp

HEADER=days/$str.txt
SRC=$str.cpp
echo $HEADER
echo $SRC
