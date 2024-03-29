#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int s[n];
    s[1] = a[1];
    int ans = s[1];
    for(int i = 2; i <= n; i++){
        if(s[i-1] > 0){
            s[i] = s[i-1] + a[i];
        }
        else s[i] = a[i];
        if(ans < s[i]){
            ans = s[i];
        }
    }
    printf("%d", ans);
}