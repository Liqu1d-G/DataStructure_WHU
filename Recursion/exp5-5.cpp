#include"linklist.cpp"
void Reverse(LinkNode *p,LinkNode *&L)
{
	if(p->next==NULL)
	{
		L->next=p;
		return;
	}
	Reverse(p->next,L);
	p->next->next=p;
	p->next=NULL;
}
int main()
{
	LinkNode *L;
	char a[]="12345678";
	int n=8;
	CreateListR(L,a,n);
	printf("L");
	DispList(L);
	printf("ÄæÖÃL\n");
	Reverse(L->next,L);
	printf("L");
	DispList(L);
	DestroyList(L);
	return 1;
}
