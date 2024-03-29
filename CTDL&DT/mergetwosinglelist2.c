#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
}node;
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node *addLast(node *head, int x){
    node* newNode = makeNode(x);
    if(head == NULL){
        return head = newNode;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;;
}
node *bubbleSort(node *head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int swapped;
    node *temp = head;
    node *last = NULL;
    do
    {
        swapped = 0;
        temp = head;
        while (temp->next != last)
        {
            if(temp->data > temp->next->data){
                int temp2 = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp2;
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
    return head;
}
node *merge2List(node *listA, node *listB){
    node *mergeList = NULL;
    while (listA != NULL)
    {
        mergeList = addLast(mergeList, listA->data);
        listA = listA->next;
    }
    while (listB != NULL)
    {
        mergeList = addLast(mergeList, listB->data);
        listB = listB->next;
    }
    return mergeList;
}
node *reverse(node *head){
    node *temp = head;
    node *previos = NULL;
    node *next = NULL;
    while(temp != NULL){
        next = temp->next;
        temp->next = previos;
        previos = temp;
        temp = next;
    }
    return previos;
}
struct Node* mergeSortedLists(struct Node* headA, struct Node* headB) {
    struct Node* mergedHead = NULL;
    while (headA != NULL) {
        mergedHead = addLast(mergedHead, headA->data);
        headA = headA->next;
    }
    while (headB != NULL) {
        mergedHead = addLast(mergedHead, headB->data);
        headB = headB->next;
    }
    mergedHead = bubbleSort(mergedHead);
    return mergedHead;
}
int main(){
    int n, m, data;
    char lenh[20];
    struct Node* mergedList=NULL;
    scanf("%d", &n);
    struct Node* listA = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        listA = addLast(listA, data);
    }

    scanf("%d", &m);
    struct Node* listB = NULL;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &data);
        listB = addLast(listB, data);
    }
    scanf("%s",lenh);
    if(strcmp(lenh,"dSort")==0){
        mergedList=mergeSortedLists(listA,listB);
        mergedList = reverse(mergedList);
    }
    else if(strcmp(lenh,"iSort")==0){
        mergedList=mergeSortedLists(listA,listB);
    }
    duyet(mergedList);
    return 0;
    while (mergedList != NULL) {
        node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
}