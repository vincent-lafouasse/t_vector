#!/usr/bin/env bash

SRC='./src'
HEADER='t_vector.h'

check_norm() {
	norminette "${SRC}"
	norminette "${HEADER}"
}

main() {
	check_norm
}
