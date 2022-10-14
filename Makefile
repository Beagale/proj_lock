all:

	arm-linux-gnueabihf-gcc -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror main.c lock.c common.c -o proj_lock
	cp proj_lock $(HOME)/cmpt433/public/myApps/