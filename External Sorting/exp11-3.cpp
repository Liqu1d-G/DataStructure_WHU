#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MaxSize 50
#define MAXKEY 32767
#define W 5
typedef int LoserTree;
typedef int InfoType;
typedef int KeyType;
typedef struct 
{
    KeyType key;
    InfoType otherinfo;
}RecType;
typedef struct 
{
    RecType recs[MaxSize];
    int lenght;
    int currec;
}FileType;
typedef struct
{
    RecType rec;
    int rnum;
}WorkArea;
FileType Fi;
FileType Fo;
void initial()
{
    int n=19,i;
    KeyType a[]={15,4,97,64,17,32,108,44,76,9,39,82,56,31,80,73,255,68,MAXKEY};
    for(i=0;i<n;i++)
        Fi.recs[i].key=a[i];
    Fi.lenght=n;
    Fi.currec=-1;
    Fo.currec=-1;
    Fo.lenght=0;
}
void Select_MiniMax(LoserTree ls[W],WorkArea wa[W],int q)
{
    int p,s,t;
    for(t=(W+q)/2,p=ls[t];t>0;t=t/2,p=ls[t])
    {
        if(wa[p].rnum<wa[q].rnum||wa[p].rnum==wa[q].rnum&&wa[p].rec.key<wa[q].rec.key)
        {
            s=q;
            q=ls[t];
            ls[t]=s;
        }
    }
    ls[0]=q;
}
void Construct_Loser(LoserTree ls[W],WorkArea wa[W])
{
    int i;
    for(i=0;i<W;i++)
        wa[i].rnum=wa[i].rec.key=ls[i]=0;
    for(i=W-1;i>=0;i--)
    {
        Fi.currec++;
        wa[i].rec=Fi.recs[Fi.currec];
        wa[i].rnum=1;
        Select_MiniMax(ls,wa,i);
    }
}
void get_run(LoserTree ls[W],WorkArea wa[W],int rc,int &rmax)
{
    int q;
    KeyType minimax;
    while(wa[ls[0]].rnum==rc)
    {
        q=ls[0];
        minimax=wa[q].rec.key;
        Fo.currec++;
        Fo.lenght++;
        Fo.recs[Fo.currec]=wa[q].rec;
        Fi.currec++;
        wa[q].rec=Fi.recs[Fi.currec];
        if(Fi.currec>=Fi.lenght-1)
        {
            wa[q].rnum=rmax+1;
            wa[q].rec.key=MAXKEY;
        }
        else
        {
            if(wa[q].rec.key<minimax)
            {
                rmax=rc+1;
                wa[q].rnum=rmax;
            }
            else
                wa[q].rnum=rc;
        }
        Select_MiniMax(ls,wa,q);
    }
}
void Replace_Selection(LoserTree ls[W],WorkArea wa[W])
{
    int rc,rmax;
    RecType j;
    j.key=MAXKEY;
    Construct_Loser(ls,wa);
    rc=1;
    rmax=1;
    while(rc<=rmax)
    {
        get_run(ls,wa,rc,rmax);
        Fo.currec++;
        Fo.recs[Fo.currec]=j;
        Fo.lenght++;
        rc=wa[ls[0]].rnum;
    }
}
int main()
{
    int i=0,rno=1;
    initial();
    LoserTree ls[W];
    WorkArea wa[W];
    printf("大文件的记录为:\n ");
    while(Fi.recs[i].key!=MAXKEY)
    {
        printf("%d ",Fi.recs[i].key);
        i++;
    }    
    printf("\n");
    Replace_Selection(ls,wa);
    printf("产生的归并段文件的记录如下:\n");
    printf(" 归并段%d:",rno);
    for(i=0;i<Fo.lenght;i++)
        if(Fo.recs[i].key==MAXKEY)
        {
            printf("∞");
            if(i<Fo.lenght-1)
            {
                rno++;
                printf("\n 归并段%d:",rno);
            }
        }
        else printf("%d ",Fo.recs[i].key);
    printf("\n 共产生%d个归并段文件\n",rno);
    return 1;
}
