#include<stdio.h>
void f(int n, int b){
    if(n==0) return;
    else{
     f(n/b,b);
     printf("%d",n%b);
    }
}
int main(){
    f(2020,8);
}