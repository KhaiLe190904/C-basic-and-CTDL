#include <stdio.h>
#include <stdlib.h>

void generateBinaryStrings(int n, int *arr, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }

    // Gán bit 0
    arr[index] = 0;
    if (index == 0 || (index > 0 && arr[index - 1] == 0)) {
        generateBinaryStrings(n, arr, index + 1);
    }

    // Gán bit 1
    arr[index] = 1;
    if (index == 0 || (index > 0 && arr[index - 1] == 0)) {
        generateBinaryStrings(n, arr, index + 1);
    }
}

int main() {
    int n;
    printf("Nhap do dai n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    generateBinaryStrings(n, arr, 0);

    free(arr);
    return 0;
}
