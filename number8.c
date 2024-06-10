#include <stdio.h>
#include <math.h>

int closestPerfectSquare(int num) {
    int lower = (int) sqrt(num);
    int upper = lower + 1;
    
    int lowerSquare = lower * lower;
    int upperSquare = upper * upper;

    if ((num - lowerSquare) <= (upperSquare - num)) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int closest = closestPerfectSquare(num);
    printf("The closest integer with a whole number square root is: %d\n", closest);

    return 0;
}