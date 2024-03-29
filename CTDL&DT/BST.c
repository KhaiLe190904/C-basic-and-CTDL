#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node{
int key;
struct node* leftChild;
struct node* rightChild;
} node;
node* root;
node* makenode(int v) {
    node* p = (node*)malloc(sizeof(node));
    p->key = v;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}
node* insert(node* r, int v) {
   if(r == NULL)
      r = makenode(v);
   else if(r->key > v)
      r->leftChild = insert(r->leftChild,v);
   else if(r->key < v)
      r->rightChild = insert(r->rightChild,v);
   return r;
}
node* search(node* r, int v){
   if(r == NULL)
      return NULL;
   if(r->key == v)
      return r;
   else if(r->key > v)
      return search(r->leftChild, v);
      return search(r->rightChild, v);
}
node* findMin(node* r) {
   if(r == NULL)
    return NULL;
   node* lmin = findMin(r->leftChild);
   if(lmin != NULL) return lmin;
   return r;
}
node* findMax(node* r) {
   if(r == NULL)
    return NULL;
   node* lmax = findMax(r->rightChild);
   if(lmax != NULL) return lmax;
   return r;
}
node* del(node* r, int v) {
   if(r == NULL) return NULL;
   else if(v < r->key) r->leftChild = del(r->leftChild, v);
   else if(v > r->key) r->rightChild = del(r->rightChild, v);
   else{ 
      if(r->leftChild != NULL && r->rightChild != NULL){
         node* tmp = findMin(r->rightChild);
         r->key = tmp->key; r->rightChild = del(r->rightChild, tmp->key);
      }
      else{
         node* tmp = r;
         if(r->leftChild == NULL) r = r->rightChild;
         else r = r->leftChild;
         free(tmp);
      }
    }
    return r;
}
int getHeight(node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = getHeight(node->leftChild);
    int rightHeight = getHeight(node->rightChild);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
int getDepth(node* root, int key) {
    if (root == NULL)
        return -1;
    if (root->key == key)
        return 0;
    int leftDepth = getDepth(root->leftChild, key);
    int rightDepth = getDepth(root->rightChild, key);
    if (leftDepth != -1)
        return leftDepth + 1;
    if (rightDepth != -1)
        return rightDepth + 1;
    return -1;
}
void inOrder(node* r) {
   if(r == NULL) return;
   inOrder(r->leftChild);
   printf("%d ", r->key);
   inOrder(r->rightChild);
}
void preOrder(node* r){
    if(r == NULL) return;
    printf("%d ", r->key);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
void postOrder(node* r){
    if(r == NULL) return;
    preOrder(r->leftChild);
    preOrder(r->rightChild);
    printf("%d ", r->key);
}
void freeTree(node* r) {
    if (r == NULL)
        return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}
int main() {
    char lc[100];
    int id, id1, id2;
    while(1){
        scanf("%s", lc);
        if(strcmp(lc, "insert") == 0){
            scanf(" %d", &id);
            root = insert(root, id);
        }
        else if(strcmp(lc, "#") == 0){
            preOrder(root); printf("\n");
            inOrder(root); printf("\n");
            postOrder(root);
            break;
        }
    }
    freeTree(root);
}