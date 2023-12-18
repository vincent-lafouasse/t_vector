#!/usr/bin/env bash

GREEN='\033[0;32m'
NO_COLOR='\033[0m'

SRC='src'
INC='include'

check_norm() {
	norminette "${SRC}" &&
	norminette "${INC}" &&
	echo "${GREEN}===============NORME OK===============${NO_COLOR}\n"
}

run_cppcheck() {
	cppcheck --language=c $(find ${SRC} -name '*.c') &&
	# cppcheck --language=c $(find ${SRC} -name '*.h') &&
	cppcheck --language=c $(find ${INC} -name '*.h') &&
	echo "${GREEN}===============CPPCHECK OK===============${NO_COLOR}\n"
}

#############################################

check_norm
run_cppcheck
