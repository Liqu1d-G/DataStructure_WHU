#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 100
#define MaxSons 10
typedef struct
{
    char fname[20];
    char sname[20];
}RecType;

typedef struct node
{
    char data[20];
    struct node *sons[MaxSons];
}TSonNode;

void ReadFile(RecType R[], int &n)
{
    FILE *fp;
    n = 0;
    if((fp=fopen("abc.txt","r"))==NULL)
    {
        printf("���ܴ��ļ�abc.txt");
        return ;
    }
    while(!feof(fp))
    {
        fscanf(fp, "%s", &R[n].fname);
        fscanf(fp, "%s", &R[n].sname);
        n++;
    }
    fclose(fp);
}

TSonNode *CreateTree(char root[], RecType R[], int n)
{
    int i, j, k;
    TSonNode *t;
    t = (TSonNode*)malloc(sizeof(TSonNode));
    strcpy(t->data,root);
    for(k=0;k<MaxSons;k++)
        t->sons[k] = NULL;
    i =0; j=0;
    while(j<n)
    {
        if(strcmp(R[i].fname, root)==0)
        {
            t->sons[j] = CreateTree(R[i].sname,R, n);
            j++;
        }
        j++;
    }
    return t;
}

void DispTree(TSonNode *t)
{
    int i;
    if(t!=NULL)
    {
        printf("%s", t->data);
        if(t->sons[0]!=NULL)
        {
            printf("(");
        
            for(i=0;i<MaxSons;i++)
            {
                DispTree(t->sons[i]);
                if(t->sons[i+1]!=NULL)
                printf(",");
                else    
                    break;
            }
            printf(")");
        }
    }
}

void DestoryTree(TSonNode *&t)
{
    int i;
    if(t!=NULL)
    {
        for(i=0;i<MaxSons;i++)
        {
            if(t->sons[i]!=NULL)
                DestoryTree(t->sons[i]);
            else 
                break;
        }
        free(t);
    }
}

TSonNode *FindNode(TSonNode *t, char x[])
{
    int i;
    TSonNode *p;
    if(t==NULL)
        return NULL;
    else if(strcmp(t->data,x)==0)
        return t;
    else
    {
        for(i=0;i<MaxSons;i++)
            if(t->sons[i]!=NULL)
            {
                p = FindNode(t->sons[i],x);
                if(p!=NULL) return p;
            }
            else break;
        return NULL;
    }
}

int ChildCount(TSonNode *p)
{
    int i, num = 0;
    for(i=0;i<MaxSons;i++)
    {
        if(p->sons[i]!=NULL)
            num ++;
        else
            break;
    }
    return num;
}

int Sonnum(TSonNode *t, char x[])
{
    TSonNode *p;
    p = FindNode(t, x);
    if(p==NULL)
        return 0;
    else 
        return ChildCount(p);
}

int LeafCount(TSonNode *t)
{
    int i, num=0;
    if(t==NULL)
        return 0;
    else 
    {
        if(t->sons[0]==NULL)
            num++;
        else 
        {
            for(i=0;i<MaxSons;i++)
                if(t->sons[i]!=NULL)
                    num += LeafCount(t->sons[i]);
                else break;
        }
        return num;
    }
}

int Classnum(TSonNode *t, char x[])
{
    TSonNode *p;
    p = FindNode(t,x);
    if(p==NULL)
        return 0;
    else 
        return LeafCount(p);
}

int LeafSum(TSonNode *t)
{
    int i, sum=0;
    if(t==NULL)
        return 0;
    else 
    {
        if(t->sons[0]==NULL)
            return  atoi(t->data);         
        //�˴�������
        else 
        {
            for(i=0;i<MaxSons;i++)
                if(t->sons[i]!=NULL)
                    sum+= LeafSum(t->sons[i]);
                else break;
        }
        return sum;
    }
}

int Studnum(TSonNode *t, char x[])
{
    TSonNode *p;
    p = FindNode(t,x);
    if(p==NULL)
        return 0;
    else 
        return LeafSum(p);
}

int main()
{
    TSonNode *t;
    RecType R[MaxSize];
    int n;
    printf("(1)��abc.txt�ļ���ȡ���ݵ�R������\n");
    ReadFile(R,n);
    if(n==0) return 1;
    printf("(2)������R������t�ĺ������洢�ṹ\n");
    t = CreateTree(R[0].fname, R, n);
    printf("(3)�����t:"); DispTree(t); printf("\n");
    printf("(4)������ѧԺ��רҵ��:%d\n", Sonnum(t,"�����ѧԺ"));
    printf("(5)������ѧԺ�İ���:%d\n", Classnum(t,"�����ѧԺ"));
    printf("(6)�����ѧԺ��ѧ����:%d\n", Studnum(t,"����ѧԺ"));
    printf("(7)������t\n");
    DestoryTree(t);
    return 1;
}