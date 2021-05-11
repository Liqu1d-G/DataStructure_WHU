//实现两个多项式相加运算
#include <stdio.h>
#include <malloc.h>
#define MAX 100
typedef struct 
{
    double coef;
    int exp;
    /* data */
}PolyArray;

typedef struct pnode
{
    double coef;
    int exp;
    struct pnode *next;
}PolyNode;

void DispPoly(PolyNode *L)
{
    bool first = true;
    PolyNode *p = L->next;
    while(p!=NULL)
    {
        if(first)
            first = false;
        else if (p->coef>0)
            printf("+");
        if(p->exp==0)
            printf("%g", p->coef);
        else if(p->exp==1)
            printf("%gx", p->coef);
        else 
            printf("%gx^%d",p->coef, p->exp);
        p=p->next;
    }
    printf("\n");
}

void DestroyPoly(PolyNode *&L)
{
    PolyNode *pre = L, *p = pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;

    }
    free(pre);
}

void CreatePolyR(PolyNode *&L, PolyArray a[], int n)
{
    PolyNode *s, *r;
    int i;
    L = (PolyNode*)malloc(sizeof(PolyNode));
    L->next = NULL;
    r = L;
    for(i=0;i<n;i++)
    {
        s = (PolyNode*)malloc(sizeof(PolyNode));
        s->coef=a[i].coef;
        s->exp=a[i].exp;
        r->next=s;
        r=s;
    }
    r->next = NULL;
}

void Sort(PolyNode * &L)
{
    PolyNode *p = L->next, *pre, *q;
    if(p!=NULL)
    {
        q=p->next;
        p->next = NULL;
        p=q;
        while (p!=NULL)
        {
            q=p->next;
            pre = L;
            while(pre->next!=NULL&& pre->next->exp > p->exp)
                pre = pre->next;
            p->next = pre -> next;
            pre->next = p;
            p=q;
            /* code */
        }
        
    }
}

void Add(PolyNode *ha, PolyNode *hb, PolyNode *&hc)
{
    PolyNode *pa = ha -> next, *pb = hb ->next, *s, *r;
    double c;
    hc = (PolyNode*)malloc(sizeof(PolyNode));
    r = hc;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->exp > pb->exp)
        {
            s = (PolyNode *)malloc(sizeof(PolyNode));
            s->exp = pa->exp;
            s->coef = pa->coef;
            r->next = s;
            r=s;
            pa =pa->next;
        }
        else if(pa->exp < pb->exp)
        {
            s = (PolyNode *)malloc(sizeof(PolyNode));
            s->exp = pb->exp;
            s->coef = pb ->coef;
            r->next = s;
            r = s;
            pb = pb->next;
        }

        else 
        {
            c= pa->coef + pb->coef;
            if(c!=0)
            {
                s = (PolyNode *)malloc(sizeof(PolyNode));
                s->exp=pa->exp;
                s->coef = c;
                r->next=s;
                r=s;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    if(pb!=NULL)
        pa = pb;
    while(pa!=NULL)
    {
        s=(PolyNode*)malloc(sizeof(PolyNode));
        s->exp = pa->exp;
        s->coef = pa->coef;
        r->next = s;
        r=s;
        pa=pa->next;
    }
    r->next=NULL;
}

int main()
{
    PolyNode *ha, *hb, *hc;
    PolyArray a[] = {{1.2,0}, {2.5,1},{3.2,3},{-2.5,5}};
    PolyArray b[]= {{-1.2,0}, {2.5,1},{3.2,3},{2.5,5}, {5.4, 10}};
    CreatePolyR(ha, a, 4);
    CreatePolyR(hb,b,5);
    printf("原多项式A:");
    DispPoly(ha);
    printf("原多项式B:");
    DispPoly(hb);
    Sort(ha);
    Sort(hb);
    printf("有序多项式A:");
    DispPoly(ha);
    printf("有序多项式B:");
    DispPoly(hb);
    Add(ha,hb,hc);
    printf("多项式相加:");
    DispPoly(hc);
    DestroyPoly(ha);
    DestroyPoly(hb);
    DestroyPoly(hc);
    return 1;
}


