#include <stdio.h>

int a[100]; // mảng số nguyên, được khai báo toàn cục
int n, cnt; // các biến nguyên được khai báo toàn cục

void Try(int k) {
    for (int v = 0; v <= 1; ++v) { // biến v được khai báo cục bộ
        if (k == 1 || (k > 1 && a[k] + v > 0)) {
            a[k] = v;
            if (k == n){
                for(int i=0; i<n; i++) printf("%d", a[i]); 
                printf("\n");
           cnt = cnt + 1;
            }  
            else Try(k + 1);
        }
    }
}

int main() {
    n = 3;
    cnt = 0;
    Try(1);
    printf("%d\n", cnt); // in giá trị biến cnt ra màn hình
    return 0;
}
