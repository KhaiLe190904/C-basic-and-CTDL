#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    char maYC[7];
    int people;
    int maPhong;
    char maKS[3];
    char time[11];
    int kids;
} hotel;
typedef struct node{
    hotel ht;
    struct node* next;
} node;
node *root;
int idKS(char maKS[]){
    char id[4]; int k = 0;
    for(int i=3; i < 7; i++){
        id[k] = maKS[i];
        k++;
    }
    return atoi(id);
}
int hash(int maKS, int tableSize) {
    return maKS % tableSize;
}

void themPhong(node* hashTable[], hotel ht, int tableSize){
    int index = hash(ht.maPhong, tableSize);
    node* current = hashTable[index];
     while (current != NULL) {
        if (current->ht.maPhong == ht.maPhong) {
            printf("Phong da bi dat\n");
            return ; // Đã có phòng nên không thêm được
        }
        current = current->next;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->ht = ht;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}


int timPhong(node* hashTable[], int maPhong, int tableSize) {
    int index = hash(maPhong, tableSize);
    node* current = hashTable[index];
    while (current != NULL) {
        if (current->ht.maPhong == maPhong) {
            return 1; // Tìm thấy phòng
        }
        current = current->next;
    }
    return 0;  // Không tìm thấy phòng
}

void phongThoaMan(node* hashTable[], int tableSize) {
    printf("Cac phong thoa man:\n");
    for (int i = 0; i < tableSize; i++) {
        node* current = hashTable[i];
        while (current != NULL) {
            if (current->ht.people > 0 && current->ht.kids == 0) {
                printf("%s %d %d %s %s %d\n", current->ht.maYC, current->ht.people, current->ht.maPhong, current->ht.maKS, current->ht.time, current->ht.kids);
            } else if (current->ht.people - current->ht.kids > 0 && current->ht.kids > 0) {
                printf("%s %d %d %s %s %d\n", current->ht.maYC, current->ht.people, current->ht.maPhong, current->ht.maKS, current->ht.time, current->ht.kids);
            }
            current = current->next;
        }
    }
}

void inratimPhong(node* hashTable[], int maPhong, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        node* current = hashTable[i];
        while (current != NULL) {
            if (current->ht.maPhong == maPhong) {
                printf("%s %d %d %s %s %d\n", current->ht.maYC, current->ht.people, current->ht.maPhong, current->ht.maKS, current->ht.time, current->ht.kids);
                return; 
            }
            current = current->next;
        }
    }
    printf("Not found\n");
}
int main() {
    int tableSize = 100;
    node* hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = NULL;
    }
    while (1) {
        hotel room;
        char lc[20];
        scanf("%s", lc);
        if (strcmp(lc, "*") == 0){
            break;
        }
        else if(strcmp(lc, "addRoom") == 0){
            scanf(" %s %d %d %s %s %d", room.maYC, &room.people, &room.maPhong, room.maKS, room.time, &room.kids);
            themPhong(hashTable, room, tableSize);
        }
        else if(strcmp(lc, "locRoom") == 0){
            phongThoaMan(hashTable, tableSize);
        }
        else if(strcmp(lc, "searchRoom") == 0){
            int maP; scanf("%d", &maP);
            inratimPhong(hashTable, maP, tableSize);
        }
    }
    return 0;
}