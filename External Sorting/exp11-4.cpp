#include<stdio.h>
#define MaxSize 20
#define K 5
#define MAXKEY 32767
#define MINKEY -32768
typedef int InfoType;
typedef int KeyType;
typedef struct
{   KeyType key;
    InfoType otherinfo;
}RecType;
typedef struct
{   RecType recs[MaxSize];
    int currec;
}FileType;
typedef int LoserTree;
RecType b[K];
FileType F[K];
void initial()
{   int i;
    F[0].recs[0].key=17;        F[0].recs[1].key=21;
    F[0].recs[2].key=MAXKEY;    F[1].recs[0].key=5;
    F[1].recs[1].key=44;        F[1].recs[2].key=MAXKEY;
    F[2].recs[0].key=10;        F[2].recs[1].key=12;
    F[2].recs[2].key=MAXKEY;    F[3].recs[0].key=29;
    F[3].recs[1].key=32;        F[3].recs[2].key=MAXKEY;
    F[4].recs[0].key=15;        F[4].recs[1].key=56;
    F[4].recs[2].key=MAXKEY;
    for(i=0;i<K;i++) F[i].currec=-1;
}
void input(int i,int &key)
{   F[i].currec++;
    key=F[i].recs[F[i].currec].key;
}
void output(int q)
{   
    printf("输出F[%d]的关键字%d\n",q,F[q].recs[F[q].currec].key);
}
void Adjust(LoserTree ls[K],int s)
{   int i,t;
    t=(s+K)/2;
    while(t>0)
    {   if(b[s].key>b[ls[t]].key)
        {   i=s;
            s=ls[t];
            ls[t]=i;
        }
        t=t/2;
    }
    ls[0]=s;
}
void display(LoserTree ls[K])
{   int i;
    printf("败者树:");
    for(i=0;i<K;i++)
        if(b[ls[i]].key==MAXKEY)
            printf("%d(∞) ",ls[i]);
        else if(b[ls[i]].key==MINKEY)
            printf("%d(-∞) ",ls[i]);
        else
            printf("%d(%d) ",ls[i],b[ls[i]].key);
    printf("\n");
}
void CreateLoserTree(LoserTree ls[K])
{   int i;
    b[K].key=MINKEY;
    for(i=0;i<K;i++)
        ls[i]=K;
    for(i=K-1;i>=0;--i)
        Adjust(ls,i);
}
void K_Merge(LoserTree ls[K])
{   int i,q;
    for(i=0;i<K;++i)
        input(i,b[i].key);
    CreateLoserTree(ls);
    display(ls);
    while(b[ls[0]].key!=MAXKEY)
    {   q=ls[0];
        output(q);
        input(q,b[q].key);
        if(b[q].key==MAXKEY)
            printf("从F[%d]中添加关键字∞并调整\n",q);
        else
            printf("从F[%d]中添加关键字%d并调整\n",q,b[q].key);
        Adjust(ls,q);
        display(ls);
    }
}
int main()
{   LoserTree ls[K];
    printf("F0:{17,21,∞}  F1:{5,44,∞}  F2:{10,12,∞}  F3:{29,32,∞}  F4:{15,56,∞}\n");
    initial();
    K_Merge(ls);
    return 1;
}