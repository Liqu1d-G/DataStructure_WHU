#include "sqstring.cpp"
#include<stdio.h>
SqString A,B;
SqString EnCrypt(SqString p)
{
    int i=0,j;
    SqString q;
    while (i<p.length)
    {
        for(j=0;p.data[i]!=A.data[j];j++);
        if(j>=p.length)
            q.data[i]=p.data[i];
        else q.data[i]=B.data[j];
        i++;
    }
    q.length=p.length;
    return q;
}
SqString UnEncrypt(SqString q)
{
    int i=0,j;
    SqString p;
    while (i<q.length)
    {
        for(j=0;q.data[i]!=B.data[j];j++);
        if(j>=q.length) p.data[i]=q.data[i];
        else p.data[i]=A.data[j];
        i++;
    }
    p.length=q.length;
    return p;
}
int main()
{
    SqString p,q;
    int ok=1;
    int i=0;
    StrAssign(A,"abcdefghijklmnopqrstuvwxyz");
    StrAssign(B,"ngzqtcobmuhelkpdawxfyivrsj");
    char str[MaxSize];
    printf("输入原文串：");
    while(true)
    {
        char c  = getchar();
        if (c == '\n')
            break;
        str[i++] = c;
    }
    str[i+1]='\0';
    StrAssign(p,str);
    printf("加密解密如下：\n");
    printf("  原文串：");
    DispStr(p);
    q=EnCrypt(p);
    printf("  加密串："); DispStr(q);
    p=UnEncrypt(q);
    printf("  解密串："); DispStr(p);
    printf("\n");
    DestroyStr(p); DestroyStr(q);
    return 1;
}