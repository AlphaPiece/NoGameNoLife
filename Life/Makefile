SHELL = /bin/bash
FLAGS = -Wall -std=gnu99 -g

.PHONY: check_life clean

all: life

life: life.o utils.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c life.h
	gcc ${FLAGS} -c $<

check_life: life
	@check_life_output=`./life 5 4 10 < sample-life-input | cmp sample-life-output 2>&1`; \
	if [ -z "$$check_life_output" ]; then \
		echo Compiled and life check passed; \
	else \
		echo Failed life check; \
	fi

clean:
	rm -f *.o life

re: clean all
