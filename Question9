#include <stdio.h>

int main() {
    int number, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }


    printf("The sum of the digits is: %d\n", sum);

    return 0;
}
