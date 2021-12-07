#include <stdio.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"


int main() {
    FILE *fp = fopen(INPUT_FILE, "r");
    if (!fp){
        fprintf(stderr, "ERROR: Could not open file.\n");
        return 1;
    }

    int curr;
    int prev = 0;
    int ans = -1;
    while (fscanf(fp, "%d", &curr) == 1){
        if (curr > prev) ans++;
        prev = curr;
    }
    printf("Increments: %d\n", ans);
    return 0;
}
