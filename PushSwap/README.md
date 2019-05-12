# PushSwap
An interesting game for learning sorting algorithms.

This projects contains two programs. One is 'push_swap', which could sort a stack of numbers with a set of operation;
the other one is 'checker', which could check if the solution given by 'push_swap' is correct or not.


**Set of operations:**

- sa: swap a - swaps the first 2 elements of stack a (does nothing if there is only one or no elements).
- sb: swap b - swaps the first 2 elements of stack b (does nothing if there is only one or no elements).
- ss: sa and sb at the same time.
- pa: push a - takes the first element on top of b and puts it on top of a (does nothing if b is empty).
- pb: push b - takes the first element on top of a and puts it on top of b (does nothing if a is empty).
- ra: rotate a - shifts up all elements of stack. The first element becomes the last one.
- rb: rotate b - shifts up all elements of stack. The first element becomes the last one.
- rr: ra and rb at the same time.
- rra: reverse rotate a - shifts down all elements of stack a. The last element becomes the first one.
- rrb: reverse rotate b - shifts down all elements of stack b. The last element becomes the first one.
- rrr: rra and rrb at the same time.


**'push_swap' algorithms:**
- simple sort (# of elements <= 3)
- selection sort (3 < # of elements <= 30)
- merge sort (# of elememts > 30)

**'checker' options:**
- -n: number of moves
- -v: view of each step
- -d: dynamically display
- -o: omit redundant view when displaying

**Performance (average):**
- 100 elements: 880 steps
- 500 elements: 6000 steps

Example usage in shell:
    ARG=$(ruby -e "puts (1..50).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker -dno $ARG
