#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define NUM_CHARS 94

int main(void) {
    srand(time(NULL));
    int x, y,count;
    count=0;
    char matrix[HEIGHT][WIDTH];

    // Initialize the matrix with spaces
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            matrix[y][x] = ' ';
        }
    }

    while (1) {
        // Scroll the matrix down one row
        for (y = HEIGHT - 1; y > 0; y--) {
            for (x = 0; x < WIDTH; x++) {
                matrix[y][x] = matrix[y - 1][x];
            }
        }

        // Add new characters at the top of the matrix
        for (x = 0; x < WIDTH; x++) {
            matrix[0][x] = '!' + (rand() % NUM_CHARS);
        }

        // Print the matrix to the console
        for (y = 0; y < HEIGHT; y++) {
            for (x = 0; x < WIDTH; x++) {
                count=rand()/10000000;
                if (count<100)
                {
                   printf("  ");

                }else{
                printf(" ");

                printf("\033[32m%c",matrix[y][x]);
                printf(" ");
                }
            }
            putchar('\n');
        }

        // Wait a bit before scrolling again
        usleep(150000);
    }
    return 0;
}
