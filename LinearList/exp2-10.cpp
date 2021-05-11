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

void Mult1(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
    PolyNode *pa=ha->next,*pb,*s,*tc;
    hc=(PolyNode*)malloc(sizeof(PolyNode));
    tc=hc;
    while(pa!=NULL){
        pb=hb->next;
        while(pb!=NULL){
            s=(PolyNode*)malloc(sizeof(PolyNode));
            s->coef=(pa->coef)*(pb->coef);
            s->exp=pa->exp+pb->exp;
            tc->next=s;
            tc=s;
            pb=pb->next;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}

void Comb(PolyNode *&L)
{
    PolyNode *pre=L->next,*p;
    if(pre==NULL)
        return;
    p=pre->next;
    while(p!=NULL){
        while(p->exp==pre->exp){
            pre->coef+=p->coef;
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        pre=p;
        p=p->next;
    }
}

void DelZero(PolyNode *&L)
{
    PolyNode *pre=L,*p=pre->next;
    while(p!=NULL){
        if(p->coef==0.0){
            pre->next=p->next;
            free(p);
        }
        pre=p;
        p=p->next;
    }
}

void Mult(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
    Mult1(ha,hb,hc);
    printf("��˽����  ");DispPoly(hc);
    Sort(hc);
    printf("��ָ�����������  ");DispPoly(hc);
    Comb(hc);
    printf("�ϲ��ظ�ָ��� ");DispPoly(hc);
    DelZero(hc);
    printf("ɾ������Ϊ0�");DispPoly(hc);
}

int main()
{
    PolyNode * Poly1,* Poly2, *Poly3;
    PolyArray a[MAX]={{2,3},{1,0},{3,1}};
    int n;
    n = 3;
    printf("��1������ʽ:\n");
    CreatePolyR(Poly1,a,n);
    printf("����ǰ����ʽ1:");DispPoly(Poly1);
    Sort(Poly1);
    printf("��������ʽ1:");DispPoly(Poly1);
    printf("��2������ʽ:\n");
    a[0].coef= 2;
    a[0].exp = 3;
    a[1].coef= -3;
    a[1].exp = 2;
    a[2].coef = 5;
    a[2].exp = 4;
    a[3].coef = -3;
    a[3].exp = 0;
    n=4;
    CreatePolyR(Poly2,a,n);
    printf("����ǰ����ʽ2:");DispPoly(Poly2);
    Sort(Poly2);
    printf("��������ʽ2:");DispPoly(Poly2);
    Mult(Poly1,Poly2,Poly3);
    printf("��˺����ʽ3:");DispPoly(Poly3);
    DestroyPoly(Poly1);
    DestroyPoly(Poly2);
    DestroyPoly(Poly3);
    return 1;
}