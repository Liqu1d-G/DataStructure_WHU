#include"bst.cpp"
bool Findsep(BSTNode *bt,int a[],int n)
{   BSTNode *p=bt;
    int i=0;
    while(i<n&&p!=NULL)
    {   if(i==n-1&&a[i]==p->key)
            return true;
        if(p->key!=a[i])
            return false;
        i++;
        if(a[i]<p->key) p=p->lchild;
        else if (a[i]>p->key) p=p->rchild;
    }
    return false;
}
int main()
{   BSTNode *bt;
    KeyType keys[]={5,2,3,4,1,6,8,7,9};int m=9,n=4;
    printf("(1)构造二叉排序树bt\n");
    bt=CreateBST(keys,m);
    printf("(2)输出BST:");DispBST(bt);printf("\n");
    KeyType a[]={5,6,8,9};
    printf("(3)关键字序列:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    if(Findsep(bt,a,n))
        printf("是一个查找序列\n");
    else
        printf("不是一个查找序列\n");
    printf("(4)销毁bt\n");DestroyBST(bt);
    return 1;
}