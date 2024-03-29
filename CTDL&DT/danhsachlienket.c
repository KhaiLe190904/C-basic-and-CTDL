#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *makeNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int contain(node* head, int u){
    while (head != NULL)
    {
        if(head->data == u){
            return 1;
        }
        else head = head->next;
    }
    return 0;
}
node *addFirst(node *head, int x){
    if(!contain(head, x)){
       node *newNode = makeNode(x);
       newNode->next = head;
       head = newNode;
    }
    return head;
}
node *addLast(node *head, int x){
    if(!contain(head, x)){
        node *newNode = makeNode(x);
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
    }
    return head;
}
node *addAfter(node *head, int u, int v){
    if(!contain(head, u) && contain(head, v)){
        node *newNode = makeNode(u);
        node *temp = head;
        while(temp->data != v){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
node *addBefore(node *head, int u, int v){
    if(!contain(head, u) && contain(head, v)){
        node *newNode = makeNode(u);
        node *temp = head;
        while(temp->next != NULL && temp->next->data != v){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
node *removeNode(node *head, int x){
    node *temp = head;
    node *previos = NULL;
    while(temp != NULL && temp->data != x){
        previos = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        if(previos != NULL){
            previos->next = temp->next;
        }
        else head = temp->next;
        free(temp);
    }
    return head;
}
node *reverse(node *head){
    node *current = head;
    node *previos = NULL;
    node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = previos;
        previos = current;
        current = next;
    }
    return previos;
}
int main(){
    int n;
    node *head = NULL;
    int data;
    while(1){
        if(scanf("%d", &data) != 1){
            break;
        }
        head = addLast(head, data);
    }
    char lc[100];
    int id, id1, id2;
    while(1){
        scanf("%s", lc);
        if(strcmp(lc, "addfirst") == 0){
            scanf(" %d", &id);
            head = addFirst(head, id);
        }
        else if(strcmp(lc, "addlast") == 0){
            scanf(" %d", &id);
            head = addLast(head, id);
        }
        else if(strcmp(lc, "addafter") == 0){
            scanf(" %d %d", &id1, &id2);
            head = addAfter(head, id1, id2);
        }
        else if(strcmp(lc, "addafter") == 0){
            scanf(" %d %d", &id1, &id2);
            head = addAfter(head, id1, id2);
        }
        else if(strcmp(lc, "addbefore") == 0){
            scanf(" %d %d", &id1, &id2);
            head = addBefore(head, id1, id2);
        }
        else if(strcmp(lc, "remove") == 0){
            scanf(" %d", &id);
            head = removeNode(head, id);
        }
        else if(strcmp(lc, "reverse") == 0){
            head = reverse(head);
        }
        else if(strcmp(lc, "duyet") == 0){
            duyet(head);
        }
        else if(strcmp(lc, "#") == 0){
            break;
        }
    }
    duyet(head);
}