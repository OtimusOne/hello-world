#include <stdio.h>
#include <stdlib.h>

struct nod{
    int value;
    struct nod *next;
};
typedef struct nod Nod;
struct list{
    Nod *head,*tail;
}L1,L2,L3;
void insert(struct list *L,int value){
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->value=value;
            nou->next=NULL;
    if(L->head==NULL){
        L->head=nou;
        L->tail=nou;
    }
    else{
        L->tail->next=nou;
        L->tail=nou;
    }
}
void display(struct list *L){
    Nod *curent=L->head;
    int k=0;
    while(curent){
        printf("%dx^%d ",curent->value,k);
        k++;
        curent=curent->next;
    }
    printf("\n");
}
void add(struct list *L1,struct list *L2,struct list *L3){
    Nod *c1=L1->head,*c2=L2->head;
    while(c1 && c2){
        int value=c1->value+c2->value;
        insert(L3,value);
        c1=c1->next;
        c2=c2->next;
    }
    while(c1){
        int value=c1->value;
        insert(L3,value);
        c1=c1->next;
    }
    while(c2){
        int value=c2->value;
        insert(L3,value);
        c2=c2->next;
    }
}
int main()
{   L1.head=NULL;
    L1.tail=NULL;
    L2.head=NULL;
    L2.tail=NULL;
    L3.head=NULL;
    L3.tail=NULL;
    insert(&L1,3);
    insert(&L1,2);
    insert(&L1,4);
    insert(&L1,4);
    insert(&L2,1);
    insert(&L2,4);
    insert(&L2,1);
    add(&L1,&L2,&L3);
    display(&L1);
    display(&L2);
    display(&L3);
    return 0;
}
