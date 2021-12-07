#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"
#define BOARD_SIZE 1000
int board[BOARD_SIZE][BOARD_SIZE] = {0};


int sign(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    if (x == 0) return 0;
}

void dumpBoard(){
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

void drawLine(int x1, int y1, int x2, int y2) {
    int x, y, n;
    int dx, dy;

    // Total distance that needs to be moved
    n = (x2-x1 == 0) ? abs(y2-y1) : abs(x2-x1);

    // Determine whether the point on the respective axis needs to move forward, backwards , or stay static (horiz./vert. line)
    dx = sign(x2-x1);
    dy = sign(y2-y1);

    for(int i = 0; i < n+1; i++){
        x = x1 + dx*i;
        y = y1 + dy*i;
        board[y][x]++;
    }
}

int main() {
    FILE *fp = fopen(INPUT_FILE, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: Could not open file.");
        return 1;
    }

    int x1, y1, x2, y2;
    // Draw all lines while parsing the input file
    while (fscanf(fp, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2) == 4){
        drawLine(x1, y1, x2, y2);
    }

    // Iterate through board and increment places where lines overlap
    int ans = 0;
    int x,y;
    for(x = 0; x < BOARD_SIZE; x++)
        for(y = 0; y < BOARD_SIZE; y++)
            if (board[x][y] > 1)
                ans++;

    // dumpBoard();
    printf("Answer: %d\n", ans);
    fclose(fp);
    return 0;
}

