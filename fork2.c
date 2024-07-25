cl#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkInstance(){
 if(fork()==0){
   printf("Hello from Child");
 }else {
   printf("Hello from Parent\n");
}
}
 int main (){
  forkInstance();
 return 0;
}
