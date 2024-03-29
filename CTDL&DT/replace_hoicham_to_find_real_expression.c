#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **top, int x){
    node *newNode = makeNode(x);
    newNode->next = *top;
    *top = newNode;
}
void pop(node **top){
    if(*top == NULL){
        return;
    }
    node *temp = *top;
    *top = (*top)->next;
    free(temp);
}
int Top(node *top){
    if(top != NULL){
        return top->data;
    }
}
int size(node *top){
    int ans = 0;
    while(top != NULL){
        ans++;
        top = top->next;
    }
    return ans;
}
int empty(node *top){
    if(top == NULL) return 1;
    else return 0;
}
int n;
int check(int a[], int n) {
    node *st = NULL;
    for (int i = 0; i < n; i++){
        if (a[i] == 1)
            push(&st, a[i]);
        else {
            if(empty(st))
                return 0;
            pop(&st);
        }
    }
    return empty(st);
}
void solve(int i, int a[]) {
    if (i == n) {
        if (check(a, n)){
            for(int i=0; i<n; i++){
                printf("%d", a[i]);
            }
            printf(" ");
        }
        return;
    }
    if (a[i] == 0){
       a[i] = 1;
       solve(i + 1, a);
       a[i] = 2;
       solve(i+1, a);
       a[i] = 0;
    }
    else if (a[i] == 1){
       solve(i + 1, a);
       a[i] = 0;
    }
    else {
        solve(i + 1, a);
        a[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve(0, a);
    return 0;
}