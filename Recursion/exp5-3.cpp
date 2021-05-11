#define MaxSize 100
#include<stdio.h>
typedef struct
{
    char data[MaxSize];
    int length;
}IP;
void addch(IP&ip,char ch)
{
    ip.data[ip.length]=ch;
    ip.length++;
}
IP addot(IP ip)
{
    addch(ip,'.');
    return ip;
}
void solveip(char s[],int n,int start,int step,IP ip)
{
    if(start<=n)
    {
        if(start==n&&step==4)
        {
            for(int i=0;i<ip.length-1;i++)
                printf("%c",ip.data[i]);
            printf("\n");
        }
    }
    int num=0;
    for(int i=start;i<n&&i<start+3;i++)
    {
        num=10*num+(s[i]-'0');
        if(num<=255)
        {
            addch(ip,s[i]);
            solveip(s,n,i+1,step+1,addot(ip));
        }
        if(num==0) break;
    }
}
int main()
{
    char s[MaxSize]="25525511135 ";
    int n=5;
    IP ip;
    ip.length=0;
    solveip(s,n,0,0,ip);
    return 1;
}