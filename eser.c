#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
    int a;
    struct nodo *next;
} nodo;

void add(nodo *t, int el)
{
    while (t->next!=NULL) {
        t = t->next;
    }
    nodo *p = malloc(sizeof(nodo));
    p->a = el;
    p->next = NULL;
    t->next = p;
}

void add2(nodo *t, int el)
{
    if (t->next==NULL) {
        nodo *p = malloc(sizeof(nodo));
        p->a = el;
        p->next =NULL;
        t->next = p;
        return;
    }
    add2(t->next, el);
}

void print (nodo *t)
{
    while (1){
        printf("%d\n",t->a);
        if (t->next==NULL) return;
        t = t->next;
    }
}

int main()
{
    nodo *t = malloc(sizeof(nodo));
    nodo *t2 = malloc(sizeof(nodo));
    t->next = t2;
    t->a = 2;
    t2->a = 3;
    t2->next = NULL;
    print(t);
    add2(t, 4);
    print(t);
    return 0;
}
