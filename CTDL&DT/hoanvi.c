#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100], b[100];
int n,i;
void duyet(){
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int gen(int i){
    for(int j = 1; j <= n; j++){
        if(b[j] == 0){
            a[i] = j;
            b[j] = 1;
            if(i == n) duyet();
            else gen(i+1);
            b[j] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        b[i] = 0;
    }
    gen(1);
}