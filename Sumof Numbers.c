#include <stdio.h>

// Function to calculate the sum of the digits of a number
int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;  // Add the last digit to the sum
        number /= 10;        // Remove the last digit
    }
    return sum;
}

int main() {
    int number;

    // Prompt the user for a positive integer
    printf("Please enter a positive integer: ");
    scanf("%d", &number);

    // Check if the entered number is positive
    if (number <= 0) {
        printf("The number must be positive.\n");
        return 1;  // Exit with an error code
    }

    // Compute the sum of the digits
    int sum = sumOfDigits(number);

    // Output the result
    printf("The sum of the digits is: %d\n", sum);

    return 0;  // Exit successfully
}
