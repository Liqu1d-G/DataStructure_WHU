#include<stdio.h>
#define MaxLen 10

void fun(int a[MaxLen][MaxLen],int n)
{
    int i,j,k=0,cnt=1;
    while(k<n/2){
        i=k;j=k;
        for(i;i<n-k-1;i++)
            a[j][i]=cnt++;
        for(j;j<n-k-1;j++)
            a[j][i]=cnt++;
        for(i;i>k;i--)
            a[j][i]=cnt++;
        for(j;j>k;j--)
            a[j][i]=cnt++;
        k++;
    }
    if(n%2!=0)
        a[k][k]=cnt;
}

int main()
{
    int n,i,j;
    int a[MaxLen][MaxLen];
    printf("输入n(n<10):");
    scanf("%d",&n);
    fun(a,n);
    printf("%d阶的数字方阵如下：\n",n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%8d",a[i][j]);
        printf("\n");
    }
    return 1;
}