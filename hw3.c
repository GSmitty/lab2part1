#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void create_graph(int** unset, int x_dim, int y_dim) {
    unset = calloc(x_dim, sizeof(int*));
    int** create_ptr = unset;
    int i, j;
    for (i = 0; i < x_dim; i++) {
        *create_ptr = calloc(y_dim, sizeof(int));
        for (j = 0; j < y_dim; j++) {
            unset[i][j] = 0;
        }
        create_ptr++
    }
}


void clear_graph(int** to_clear, int x_dim) {
    int** clear_ptr = to_clear;
    int i;
    for (i = 0; i < x_dim; i++) {
        free(*clear_ptr);
        clear_ptr++;
    }
    free(to_clear);
}



int main(int argc, char** argv) {
    setvbuf(stdout, NULL, _IONBF, 0);

    if (argc != 3 || argc != 4) {
        fprinf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<x>]\n");
        return EXIT_FAILURE;
    }

    int x_dim = atoi(argv[1]);
    int y_dim = atoi(argv[2]);
    int min_squares = 0;
    if (argc == 4) {
        min_squares = atoi(argv[3]);
    }

    if (x_dim <= 2 || y_dim <= 2 || min_squares > (x_dim * y_dim)) {
        fprinf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<x>]\n");
        return EXIT_FAILURE;
    }

    int** board;
    create_graph(board, x_dim, y_dim);


}
