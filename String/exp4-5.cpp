#include "sqstring.cpp"
#include<malloc.h>
#include<stdio.h>
SqString *MaxSubstr(SqString s)
{
    SqString *subs;
    int index=0,length=0,length1,i=0,j,k;
    while(i<s.length)
    {
        j=i+1;
        while(j<s.length)
        {
            if(s.data[i]==s.data[j]){
                length1=1;
                for(k=1;s.data[i+k]==s.data[j+k];k++)  length1++;
                if(length1>length)
                {
                    index=i;
                    length=length1;
                }
                j+=length1;
            }
            else j++;
        }
        i++;
    }
    subs=(SqString*)malloc(sizeof(SqString));
    subs->length=length;
    for(i=0;i<length;i++)  subs->data[i]=s.data[index+i];
    return subs;
}
int main()
{
    char str[MaxSize];
    int i=0;
    SqString s,*subs;
    printf("输入串：");
    
    while(true)
    {
        char c  = getchar();
        if (c == '\n')
            break;
        str[i++] = c;
    }

    str[i+1]='\0';
    puts(str);
    StrAssign(s,str);
    subs=MaxSubstr(s);
    printf("求最长重复子串：\n");
    printf("    原串：");
    DispStr(s);
    printf("  最长重复子串：");
    DispStr(*subs);
    DestroyStr(s);free(subs);
    return 1;
}