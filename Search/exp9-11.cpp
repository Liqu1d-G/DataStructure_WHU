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
    printf("(1)�������������bt\n");
    bt=CreateBST(keys,m);
    printf("(2)���BST:");DispBST(bt);printf("\n");
    KeyType a[]={5,6,8,9};
    printf("(3)�ؼ�������:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    if(Findsep(bt,a,n))
        printf("��һ����������\n");
    else
        printf("����һ����������\n");
    printf("(4)����bt\n");DestroyBST(bt);
    return 1;
}