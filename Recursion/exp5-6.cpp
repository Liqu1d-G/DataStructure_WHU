#include"linklist.cpp"
LinkNode *kthNode(LinkNode * L,int k,int &i)
{
	LinkNode * p;
	if(L==NULL)
		return NULL;
	p=kthNode(L->next,k,i);
	i++;
	if(i==k)
		return L;
	return p;
}
int main()
{
	LinkNode * L,* p;
	char a[]="12345678";
	int n=8,k=2,i=0;
	CreateListR(L,a,n);
	printf("L:");
	DispList(L);
	p=kthNode(L->next,k,i);
	if(p!=NULL)
		printf("倒数第%d个结点:%c\n",k,p->data);
	else
		printf("没有找到\n");
	DestroyList(L);
	return 1;
}
