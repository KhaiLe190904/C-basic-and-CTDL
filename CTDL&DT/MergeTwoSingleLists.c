#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int key;
    struct Node* next;
};
struct Node* makeNode(int k) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int k) {
    struct Node* newNode = makeNode(k);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->key);
        head = head->next;
    }
    printf("\n");
}
struct Node* sortListDescending(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int swapped;
    struct Node* temp;
    struct Node* end = NULL;

    do {
        swapped = 0;
        temp = head;

        while (temp->next != end) {
            if (temp->key < temp->next->key) {
                int tempKey = temp->key;
                temp->key = temp->next->key;
                temp->next->key = tempKey;

                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;

    } while (swapped);

    return head;
}
struct Node* mergeSortedListsDescending(struct Node* headA, struct Node* headB) {
    struct Node* mergedHead = NULL;
    while (headA != NULL) {
        mergedHead = insertAtEnd(mergedHead, headA->key);
        headA = headA->next;
    }
    while (headB != NULL) {
        mergedHead = insertAtEnd(mergedHead, headB->key);
        headB = headB->next;
    }
    mergedHead = sortListDescending(mergedHead);

    return mergedHead;
}
struct Node* sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int swapped;
    struct Node* temp;
    struct Node* end = NULL;
    do {
        swapped = 0;
        temp = head;

        while (temp->next != end) {
            if (temp->key > temp->next->key) {
                int tempKey = temp->key;
                temp->key = temp->next->key;
                temp->next->key = tempKey;

                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;

    } while (swapped);

    return head;
}
struct Node* mergeSortedLists(struct Node* headA, struct Node* headB) {
    struct Node* mergedHead = NULL;
    while (headA != NULL) {
        mergedHead = insertAtEnd(mergedHead, headA->key);
        headA = headA->next;
    }
    while (headB != NULL) {
        mergedHead = insertAtEnd(mergedHead, headB->key);
        headB = headB->next;
    }
    mergedHead = sortList(mergedHead);
    return mergedHead;
}
int main() {
    int n, m, key;
    char lenh[20];
   struct Node* mergedList=NULL;
    scanf("%d", &n);
    struct Node* listA = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        listA = insertAtEnd(listA, key);
    }

    scanf("%d", &m);
    struct Node* listB = NULL;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &key);
        listB = insertAtEnd(listB, key);
    }
    scanf("%s",lenh);
    if(strcmp(lenh,"dSort")==0){
        mergedList=mergeSortedListsDescending(listA,listB);
    }
    else if(strcmp(lenh,"iSort")==0){
        mergedList=mergeSortedLists(listA,listB);
    }
    printList(mergedList);
    return 0;
}