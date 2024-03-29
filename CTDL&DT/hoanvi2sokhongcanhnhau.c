#include <stdio.h>
void printArray(int arr[], int k) {
    for (int i = 0; i < k; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void gen(int arr[], int n, int k, int i) {
    for(int j = 1; j <= n; j++){
        int check = 0;
        for(int l = 0; l < i; l++){
            if(arr[l] == j-1 || arr[l] == j+1 || arr[l] == j+2){
                check = 1;
                break;
            }
        }
        if(!check){
            arr[i] = j;
            if(i == k){
                printArray(arr, k);
                return;
            }
            gen(arr, n, k, i+1);
        }
    }   
}
int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[k];
    gen(arr, n, k, 0);
    return 0;
}
