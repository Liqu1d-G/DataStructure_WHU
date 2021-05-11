#include"linklist.cpp"

void Sort(LinkNode *&L)
{
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while(p!=NULL){
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data){
                pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
}

void Union(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{
    LinkNode *pa=ha->next,*pb=hb->next,*s,*tc;
    hc=(LinkNode*)malloc(sizeof(LinkNode));
    tc=hc;
    while(pa!=NULL&&pb!=NULL){
        if(pa->data<pb->data){
            s=(LinkNode*)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
            pa=pa->next;
        }
        else if(pa->data>pb->data){
            s=(LinkNode*)malloc(sizeof(LinkNode));
            s->data=pb->data;
            tc->next=s;tc=s;
            pb=pb->next;
        }
        else{
            s=(LinkNode*)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
            pb=pb->next;
            pa=pa->next;
        }
    }
    if(pb!=NULL)
        pa=pb;
    while(pa!=NULL){
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=pa->data;
        tc->next=s;tc=s;
        pa=pa->next;
    }
    tc->next=NULL;
}

void InterSect(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{
    LinkNode *pa=ha->next,*pb=hb->next,*s,*tc;
    hc=(LinkNode*)malloc(sizeof(LinkNode));
    tc=hc;
    while(pa!=NULL){
        pb=hb->next;
        while(pb!=NULL&&pb->data<pa->data)
            pb=pb->next;
        if(pb!=NULL&&pb->data==pa->data){
            s=(LinkNode*)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}

void Subs(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{
    LinkNode *pa=ha->next,*pb=hb->next,*s,*tc;
    hc=(LinkNode*)malloc(sizeof(LinkNode));
    tc=hc;
    while(pa!=NULL){
        pb=hb->next;
        while(pb!=NULL&&pb->data<pa->data)
            pb=pb->next;
        if(!(pb!=NULL&&pb->data==pa->data)){
            s=(LinkNode*)malloc(sizeof(LinkNode));
            s->data=pa->data;
            tc->next=s;tc=s;
        }
        pa=pa->next;
    }
    tc->next=NULL;
}

int main()
{
    LinkNode *ha,*hb,*hc;
    ElemType a[]={'c','a','e','h'};
    ElemType b[]={'f','h','b','g','d','a'};
    printf("���ϵ��������£�\n");
    CreateListR(ha,a,4);
    CreateListR(hb,b,6);
    printf("ԭ����A��");DispList(ha);
    printf("ԭ����B��");DispList(hb);
    Sort(ha);Sort(hb);
    printf("���򼯺�A:");DispList(ha);
    printf("���򼯺�B:");DispList(hb);
    Union(ha,hb,hc);
    printf("���ϵĲ���C��");DispList(hc);
    InterSect(ha,hb,hc);
    printf("���ϵĽ���C��");DispList(hc);
    Subs(ha,hb,hc);
    printf("���ϵĲC��");DispList(hc);
    DestroyList(ha);DestroyList(hb);DestroyList(hc);
    return 1;
}
    