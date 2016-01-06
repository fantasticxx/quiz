#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5

typedef struct _List {
    struct _List *next;
    int val;
} List;

List *reverseBetween(List *head,int m,int n)
{

    List* newHead;
    newHead->next=head;
    List* prev =newHead;
    for(int i=0; i<m-1; i++) {
        prev=prev->next;
    }
    List* reversedPrev = prev;
    prev =prev->next;
    List* cur = prev->next;
    for(int i=m; i<n; i++) {
        prev->next=cur->next;
        cur->next=reversedPrev->next;
        reversedPrev->next=cur;
        cur= prev->next;
    }
    return newHead->next;

}
void print_list(List* head)
{
    while(head) {
        printf("%d\t",head->val);

        head=head->next;
    }
    printf("\n");
}

int main()
{
    List *node;
    List *head;
    List *curNode=NULL;
    int m,n;

    for(int i=0; i<LENGTH; i++) {
        node=(List*)malloc(sizeof(List));
        node->val=i+1;
        node->next=NULL;
        if(curNode==NULL) {
            head=curNode=node;
        } else {
            curNode->next=node;
            curNode=curNode->next;
        }
    }
    print_list(head);
    scanf("%d %d",&m,&n);
    if(1<=m && m<=n && n<=LENGTH) {
        head=reverseBetween(head,m,n);
        print_list(head);
    }
    free(head);
    return 0;
}
