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
    int sum;
    fscanf(fp, "%d\n%d\n%d", &a, &b, &c);
    sum = a+b+c;

    // x = Next Value
    int ans = 0;
    int x;
    printf("Start Sum: %d\n", sum);
    while (fscanf(fp, "%d", &x) == 1){
        // New Value = sum - first + next
        int val = sum-a+x;
        if (val > sum) ans++;
        // Swap values and refresh sum
        a = b;
        b = c;
        c = x;
        sum = a+b+c;
    }

    printf("Increments: %d\n", ans);
    fclose(fp);
    return 0;
}
