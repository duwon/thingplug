#bin/bash
mkdir bin
echo "compile.. ${1}.c"
gcc -o bin/${1} ${1}.c -lpaho-mqtt3c
bin/${1}
