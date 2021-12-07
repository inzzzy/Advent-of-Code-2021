#include <stdio.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"


int main() {
    FILE *fp = fopen(INPUT_FILE, "r");
    if (!fp){
        fprintf(stderr, "ERROR: Could not open file.\n");
        return 1;
    }

    // Scan first 3 values, sum and remember them.
    int a,b,c;
    fscanf(fp, "%d\n%d\n%d", &a, &b, &c);

    // x = next value 
    int x;
    int ans = 0;
    while (fscanf(fp, "%d", &x) == 1){
        // New sum = previous sum - first + next
        if (b+c+x > a+b+c) ans++;
        a = b;
        b = c;
        c = x;
    }

    printf("Increments: %d\n", ans);
    fclose(fp);
    return 0;
}
