#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void reverse(int a[], int n){
    int l = 0, r = n-1;
    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r]= temp;
        l++;
        r--;
    }
}
void add(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b), n = 0;
    int x[n1], y[n2], z[n1+1];
    for(int i = 0; i < n1; i++) x[i] = a[i] - '0';
    for(int i = 0; i < n2; i++) y[i] = b[i] - '0';
    reverse(x, n1); reverse(y, n2);
    for(int i = n2; i < n1; i++){
        y[i] = 0;
    }
    int nho = 0;
    for(int i = 0; i < n1; i++){
        int temp = x[i] + y[i] + nho;
        z[n++] = temp % 10;
        nho = temp / 10;
    }
    if(nho == 1) z[n++] = nho;
    for(int i = n-1; i >= 0; i--) printf("%d", z[i]);
}
int main(){
    char a[1001], b[1001];
    scanf("%s", a);
    scanf("%s", b);
    if(strlen(a) >= strlen(b)){
        add(a, b);
    }
    else add(b,a);
}