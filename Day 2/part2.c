#include <stdio.h>
#include <string.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"
#define BUFFER_SIZE 256

int main() {
    FILE *fp = fopen(INPUT_FILE, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: Could not open file.\n");
        return 1;
    }

    int h = 0;
    int d = 0;
    int a = 0;

    char cmd[BUFFER_SIZE];
    int x;

    while(fscanf(fp, "%s %d", &cmd, &x) == 2){
        if (strcmp(cmd, "down") == 0) a += x;
        if (strcmp(cmd, "up") == 0) a -= x;
        if (strcmp(cmd, "forward") == 0){
            h += x;
            d += a*x;
        }
    }

    int ans = h * d;
    printf("Pos: %d\n", ans);
    fclose(fp);
  
}
