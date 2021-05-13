#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define M 4
#define N 4
typedef struct ANode
{   int i,j;
    struct ANode *nextarc;
}ArcNode;
typedef struct VNode
{   
    ArcNode *firstarc;
}VNode;
typedef struct
{
    VNode adjlist[M+2][N+2];
}ALGraph;
typedef struct
{   int i;
    int j;
}Box;
typedef struct
{   Box data[MaxSize];
    int length;
}PathType;
int visited[M+2][N+2]={0};
int count = 0;
void CreateAdj(ALGraph *&G,int mg[][N+2])
{   int i,j,i1,j1,di;
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    for(i=0;i<M+2;i++)
        for(j=0;j<N+2;j++)
            G->adjlist[i][j].firstarc=NULL;
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if(mg[i][j]==0)
            {   di=0;
                while(di<4)
                {   switch(di)
                    {
                    case 0:i1=i-1;j1=j;break;
                    case 1:i1=i;j1=j+1;break;
                    case 2:i1=i+1;j1=j;break;
                    case 3:i1=i;j1=j-1;break;
                    }
                    if(mg[i1][j1]==0)
                    {   p=(ArcNode *)malloc(sizeof(ArcNode));
                        p->i=i1;p->j=j1;
                        p->nextarc=G->adjlist[i][j].firstarc;
                        G->adjlist[i][j].firstarc=p;
                    }
                    di++;
                }
            }
}
void DispAdj(ALGraph *G)
{   int i,j;
    ArcNode *p;
    for(i=0;i<M+2;i++)
        for(j=0;j<N+2;j++)
        {   printf(" [%d,%d]:",i,j);   
            p=G->adjlist[i][j].firstarc;
            while(p!=NULL)
            {   printf("(%d,%d) ",p->i,p->j);
                p=p->nextarc;
            }
            printf("\n");
        }
}
void DestroyAdj(ALGraph *&G)	
{   int i,j;
	ArcNode *pre,*p;
	for(i=0;i<M+2;i++)
        for(j=0;j<N+2;j++)
        {	pre=G->adjlist[i][j].firstarc;	
	    	if(pre!=NULL)
	    	{	p=pre->nextarc;
	    		while(p!=NULL)	
		    	{	free(pre);
				    pre=p; p=p->nextarc;
		    	}
		    	free(pre);
	    	}
    	}
	free(G);
}
void FindPath(ALGraph *G,int xi,int yi,int xe,int ye,PathType path)
{   ArcNode *p;
    visited[xi][yi]=1;
    path.data[path.length].i=xi;path.data[path.length].j=yi;
    path.length++;
    if(xi==xe&&yi==ye)
    {   printf(" 迷宫路径%d:",++count);
        for(int k=0;k<path.length;k++)
            printf("(%d,%d)",path.data[k].i,path.data[k].j);
        printf("\n");
    }
    p=G->adjlist[xi][yi].firstarc;
    while(p!=NULL)
    {   if(visited[p->i][p->j]==0)
            FindPath(G,p->i,p->j,xe,ye,path);
        p=p->nextarc;
    }
    visited[xi][yi]=0;
}
int main()
{   ALGraph *G;
    int mg[M+2][N+2]={
        {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
        {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}};
    CreateAdj(G,mg);
    printf("迷宫对应的邻接表:\n");DispAdj(G);
    PathType path;
    path.length=0;
    printf("所有的迷宫路径:\n");
    FindPath(G,1,1,M,N,path);
    DestroyAdj(G);
    return 1;
}