#include<stdio.h>
#define M 4
#define N 4

void MinMax(int A[M][N]){
    int i,j,p;
    int min[M],max[N];
    for(i=0;i<M;i++){
        p=0;
        for(j=0;j<N-1;j++){
            if(A[i][j]>A[i][j+1])
                p=j+1;
        }
        min[i]=A[i][p];
    }
    for(j=0;j<N;j++){
        p=0;
        for(i=0;i<M-1;i++){
            if(A[i][j]<A[i+1][j])
                p=i+1;
        }
        max[j]=A[p][j];
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(min[i]==max[j])
                printf("A[%d][%d]=%d\n",i,j,min[i]);
        }
    }
    printf("end");
}

int main()
{
    int i,j;
    int A[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}};
    printf("A矩阵：\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++)
            printf("%4d",A[i][j]);
        printf("\n");
    }
    printf("A矩阵中的马鞍点：\n");
    MinMax(A);
    return 1;
}