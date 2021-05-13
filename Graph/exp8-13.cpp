#include "graph.cpp"
void Dispapath(int path[][MAXV], int i, int j)
{
    int apath[MAXV], d;
    int k=path[i][j];
    d=0; apath[d]=j;
    while(k!=-1&&k!=i)
    {
        d++; apath[d]=k;
        k=path[i][k];
    }
    d++; apath[d]=i;
    for(int s=d; s>=0;s--)
        printf("%d->", apath[s]);
}

int Mincycle(MatGraph g, int A[MAXV][MAXV], int &mini, int &minj)
{
    int i, j, min = INF;
    for(i=0;i<g.n;i++)
        for(j=0;j<g.n;j++)
            if(i!=j&&g.edges[j][i]<INF)
            {
                if(A[i][j]+g.edges[j][i]<min)
                {
                    min=A[i][j]+g.edges[j][i];
                    mini = i; minj = j;
                }
            }
    return min;
}

void Floyd(MatGraph g)
{
    int A[MAXV][MAXV], path[MAXV][MAXV];
    int i, j, k, min, mini, minj;
    for(i=0;i<g.n;i++)
        for(j=0;j<g.n;j++)
        {
            A[i][j] = g.edges[i][j];
            if(i!=j&&g.edges[i][j]<INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    for(k=0;k<g.n;k++)
    {
        for(i=0;i<g.n;i++)
            for(j=0;j<g.n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j] = A[i][k]+A[k][j];
                    path[i][j] = path[k][j];
                }
    }
    min = Mincycle(g, A, mini, minj);
    if(min!=INF)
    {
        printf("  图中最小环: ");
        Dispapath(path, mini, minj);
        printf("%d, 长度: %d\n", mini, min);
    }
    else printf("  图中没有任何环\n");
}

int main()
{
    MatGraph g;
    int A[MAXV][MAXV] = {
        {0,10,1,INF}, {21, 0, INF, 6}, {INF, 1, 0, INF}, {5, INF, INF, 0}
    };
    int n=4, e=6;
    CreateMat(g,A, n, e);
    printf("有向图G的邻接矩阵:\n"); DispMat(g);
    printf("求解结果:\n"); Floyd(g);
    return 1;
}