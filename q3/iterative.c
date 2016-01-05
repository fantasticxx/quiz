#include <stdlib.h>
#include <stdio.h>


typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

void flatten(Node *root)
{
    while(root!=NULL) {
        if(root->left) {
            Node* ptr=root->left;
            while(ptr->right) {
                ptr=ptr->right;
            }
            ptr->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}

void inorder(Node *root)
{
    if (root!=NULL) {
        inorder(root->left);
        printf("%d\t",root->val);
        inorder(root->right);
    }
}

int main()
{
    Node *node[6];
    Node *t;
    Node *root;

    for(int i=0; i<6; i++) {
        node[i] = (Node*)malloc(sizeof(Node));
        t=node[i];
        t->val=i+1;
        t->left=NULL;
        t->right=NULL;
    }

    root=node[0];
    node[0]->left=node[1];
    node[0]->right=node[4];
    node[1]->left=node[2];
    node[1]->right=node[3];
    node[4]->right=node[5];

    printf("Inorder traversal\n");
    inorder(root);
    flatten(root);
    printf("\nafter flattening\n");
    printf("Inorder traversal\n");
    inorder(root);

    for(int j=0; j<6; j++) {
        free(node[j]);
    }
    return 0;
}
