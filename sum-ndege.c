#include <stdio.h>

int main(){
    int num , sum;
    while(1){
        printf("Input a positive integer, 0 to exit:\n");
        scanf("%d" , &num);
        sum = 0;
        if(num == 0){
            break;
        }
        else{
            while(num != 0){
            sum += num % 10;
            num /= 10;
        }
        printf("The sum is: %d\n" , sum);
        }
    }
}