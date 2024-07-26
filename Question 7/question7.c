// Debug the following code by compiling it for debugging and executing it within a
// debugger. At which line of code does the program crash? Why does it crash there?

/* This code has a compile-time error, and at
** least one run-time error. */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n, i;
    int d2, count;
    double d1;

    while (1)
    {
        printf("Enter a number (0 to quit): ");
        scanf("%d", &n);
        if (n == 0)
            break;

        count = 0;
        for (i = 0; i < n; i++) // Start i from 1 to avoid division by zero
        {
            d1 = (double)n / (double)i;
            d2 = n / i;
            if (fabs(d1 - (double)d2) < 0.00001)
                count++;
        }

        if (count == 2)
            printf("%d is prime\n", n);
        else
            printf("%d is not prime\n", n);
    }

    return 0;
}


// Answer
// The program crashes at the line d1=(double)n / (double)I; when ‘I’ is ‘zero’. The code will crash because of division by zero.
