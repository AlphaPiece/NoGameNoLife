#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static struct timespec	delay = {0, 100000000};

void print_state(int *state, int rows, int cols, int state_num)
{
	system("clear");
	printf("\n");
    for (int i = 0; i < rows * cols; i++)
	{
        printf(" %s%d\x1B[0m", (state[i]) ? "\x1B[32m" : "", state[i]);
        if (((i + 1) % cols) == 0)
			printf("\n");
    }
    printf("\n");
	if (state_num <= 10)
		sleep(2);
	else if (state_num <= 30)
		sleep(1);
	else
		nanosleep(&delay, 0);
}

static int has_2_3_neighbours(int *state, int cols, int row, int col)
{
	int	i, j, neighbours;

	neighbours = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++)
			if (!(i == row && j == col) && state[i * cols + j])
				neighbours++;
	return (neighbours == 2 || neighbours == 3);
}			

void update_state(int *curr_state, int *next_state, int rows, int cols)
{
	int	i, j;

	for (i = 1; i < rows - 1; i++)
		for (j = 1; j < cols - 1; j++)
			if (has_2_3_neighbours(curr_state, cols, i, j))
				next_state[i * cols + j] = 1;
			else
				next_state[i * cols + j] = 0;
}
