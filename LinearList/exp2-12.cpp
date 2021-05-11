#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 50
typedef struct node
{
    int data;
    struct node*next;
}NodeType;
void CreateLink(NodeType *&h,char a[],int n)
{
    NodeType *p,*r;
    int i = 0;
    h = (NodeType*)malloc(sizeof(NodeType));
    r =h;
    while(i<n)
    {
        p = (NodeType *)malloc(sizeof(NodeType));
        p->data = a[n-i-1]-'0';
        r->next = p;r = p;
        i++;
    }
    r->next = NULL;
}
void DestroyLink(NodeType *&h)
{
    NodeType *pre = h,*p = pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}
void DispLink(NodeType *h)
{
    NodeType *p = h->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
}
void Add(NodeType *h1,NodeType *h2,NodeType *&h)
{
    NodeType *p1 = h1->next,*p2 = h2->next,*p,*r;
    int carry = 0;
    h = (NodeType *)malloc(sizeof(NodeType));
    r=h;
    while(p1!=NULL&&p2!=NULL)
    {
        p = (NodeType*)malloc(sizeof(NodeType));
        p->data = (p1->data+p2->data+carry)%10;
        r->next = p;r = p;
        carry = (p1->data+p2->data+carry)/10;
        p1 = p1->next;
        p2 = p2->next;
    }
    if(p1==NULL)p1=p2;
    while(p1!=NULL)
    {
        p=(NodeType*)malloc(sizeof(NodeType));
        p->data = carry;
        r->next = p;r = p;
    }
    r->next=  NULL;
}
void Reverse(NodeType *&h)
{
    NodeType *p = h->next,*q;
    h->next = NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next = h->next;h->next = p;
        p=q;
    }
}
int Mid(NodeType *h)
{
    NodeType *slow = h,*quick = h;
    while(quick!=NULL&&quick->next!=NULL)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    return slow->data;
}
int main()
{
    NodeType *h1,*h2,*h;
    char s[MaxSize],t[MaxSize];
    printf("操作步骤: \n");
    printf("(1)输入整数1:");scanf("%s",s);
    printf("(2)输入整数2:");scanf("%s",t);
    CreateLink(h1, s, strlen(s));
    CreateLink(h2, t, strlen(t));
    printf("(3)整数单链表1:");DispLink(h1);
    printf("(4)整数单链表2:");DispLink(h2);
    Add(h1,h2,h);
    printf("(5)结果单链表:");DispLink(h);
    Reverse(h);
    printf("(6)对应的整数:");DispLink(h);
    printf("(7)中间位:%d\n",Mid(h));
    DestroyLink(h);
    DestroyLink(h1);
    DestroyLink(h2);
    return 1;
}
