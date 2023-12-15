#!/usr/bin/env bash

GREEN='\033[0;32m'
NC='\033[0m'

SRC='./src'
HEADER='t_vector.h'

check_norm() {
	norminette "${SRC}" &&
	norminette "${HEADER}" &&
	echo "${GREEN}===============NORME OK===============${NC}\n"
}

#############################################

check_norm
