#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int heso;
    int somu;
    struct node* next;
} node;
node *makeNode(int heso, int somu){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->heso = heso;
    newNode->somu = somu;
    newNode->next = NULL;
    return newNode;
}
node *addLast(node *head, int u, int v){
    node *newNode = makeNode(u, v);
    if(head == NULL){
        head = newNode;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void duyet(node *head){
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if(temp->heso != 0) count++;
        temp = temp->next;
    }
    if(count == 0){
        printf("1 0");
        return;
    }
    else printf("%d ", count);
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->heso);
        temp = temp->next;
    }
}
node *sumList(node *headA, node *headB, int n){
    node *sum = NULL;
    node *hA = headA;
    node *hB = headB;
    for(int i = 0; i < n; i++){
        if(hA != NULL && hB != NULL){
            sum = addLast(sum, hA->heso + hB->heso, i);
        }
        hA = hA->next;
        hB = hB->next;
    }
    return sum;  
}
node *hieuList(node *headA, node *headB, int n){
    node *sum = NULL;
    node *hA = headA;
    node *hB = headB;
    for(int i = 0; i < n; i++){
        if(hA != NULL && hB != NULL){
            sum = addLast(sum, hA->heso - hB->heso, i);
        }
        hA = hA->next;
        hB = hB->next;
    }
    return sum;  
}
int main(){
    node *headA = NULL;
    node *headB = NULL;
    node *sum = NULL;
    int n, hsA;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &hsA);
        headA = addLast(headA, hsA, i);
    }
    int m, hsB;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &hsB);
        headB = addLast(headB, hsB, i);
    }
    int k;
    if(n > m){
        k = n;
        for(int i = m; i < k; i++){
            headB = addLast(headB, 0, i);
        }
    }
    else{
        k = m;
        for(int i = n; i < k; i++){
            headA = addLast(headA, 0, i);
        }
    }
    char lc[20];
    scanf("%s", lc);
    if(strcmp(lc, "plus") == 0){
        sum = sumList(headA, headB, k);
    }
    else if(strcmp(lc, "minus") == 0){
        sum = hieuList(headA, headB, k);
    }
    duyet(sum);
}