#include <stdio.h>
#include <math.h>
// Function to find the closest perfect square to the given number
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
    //modified this line to only allow positive perfect square
 int closest = closestPerfectSquare(num);
    printf("The closest perfect square to %d is: %d\n", num, closest);

    return 0;
}
