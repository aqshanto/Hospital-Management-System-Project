#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}* root;

typedef struct Node newnode;

int main() {
    root = (newnode*)malloc(sizeof(newnode));
    int N;
    scanf("%d", &N);
    newnode* Head;
    Head = (newnode*)malloc(sizeof(newnode));
    Head = root;
    int num;
    scanf("%d", &num);
    root->data = num;
    for (int i = 1; i < N; i++) {
        scanf("%d", &num);
        while (Head->left != NULL && Head->right != NULL) {
            if (Head->data <= num) {
                Head = Head->left;
            } else {
                Head = Head->right;
            }
        }
        if (Head->data <= num) {
            Head->left->data = num;
        } else {
            Head->right->data = num;
        }
    }
    return 0;
}