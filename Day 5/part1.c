#include <stdio.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"
#define BOARD_SIZE 1000

int board[BOARD_SIZE][BOARD_SIZE] = {0};


void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void printBoard(){
    for(int x = 0; x < BOARD_SIZE; x++) {
        for(int y = 0; y < BOARD_SIZE; y++){
            if (board[x][y]) {
                fprintf(stdout, "%d", board[x][y]);
            } else {
                fprintf(stdout, ".");
            }
        }
        fprintf(stdout, "\n");
    }
}

void drawVert(int x, int y1, int y2) {
    if (y1 > y2) swap(&y1, &y2);
    for(int y = y1; y<y2+1; y++) board[y][x]++;
}

void drawHorz(int y, int x1, int x2) {
    if (x1 > x2) swap(&x1, &x2);
    for(int x = x1; x<x2+1; x++) board[y][x]++;
}

int main() {
    FILE *fp = fopen(INPUT_FILE, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: Could not open file.");
        return 1;
    }

    // Draw horizontal and vertical lines while parsing the input file
    int x1, y1, x2, y2;
    while (fscanf(fp, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2) == 4) {
        if ( x1 == x2 ) drawVert(x1, y1, y2);
        if ( y1 == y2 ) drawHorz(y1, x1, x2);
    }

    // Iterate through board and increment places where lines overlap
    int ans = 0;
    int x,y;
    for(x = 0; x < BOARD_SIZE; x++)
        for(y = 0; y < BOARD_SIZE; y++)
            if (board[x][y] > 1)
                ans++;

    // printBoard();
    fprintf(stdout, "Answer: %d\n", ans);
    fclose(fp);
    return 0;
}

