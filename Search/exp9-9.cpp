//统计一个字符串中出现的字符及其次数
//exp9-9
#include<stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXWORD 100
typedef struct tnode
{
    char ch;
    int count;
    struct tnode *lchild, *rchild;
}BSTNode;

void CreateBST(BSTNode *&bt, char c)
{
    if(bt == NULL)
    {
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt -> ch = c;
        bt -> count = 1;
        bt ->lchild = bt -> rchild = NULL;

    }
    else if(c==bt->ch)
        bt -> count++;
    else if(c<bt->ch)
        CreateBST(bt->lchild, c);
    else 
        CreateBST(bt->rchild,c);
}

void InOrder(BSTNode *bt)
{
    if(bt!=NULL)
    {
        InOrder(bt->lchild);
        printf("  %c(%d)\n", bt->ch, bt->count);
        InOrder(bt->rchild);
    }
}

void DestroyBSTNode(BSTNode *bt)
{
    if(bt!=NULL)
    {
        DestroyBSTNode(bt->lchild);
        DestroyBSTNode(bt->rchild);
        free(bt);
    }
}

int main()
{
    BSTNode *bt = NULL;
    int i=0;
    char str[MAXWORD];
    printf("Input string: ");   gets(str);
    while(str[i]!='\0')
    {
        CreateBST(bt, str[i]);
        i++;
    }
    printf("Char and times it appears:\n");
    InOrder(bt); printf("\n");
    DestroyBSTNode(bt);
    return 1;
    
}