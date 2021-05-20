#include<stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

KeyType M_Search(RecType A[], RecType B[], int n)
{
    int start1, end1, mid1, start2, end2, mid2;
    start1 = 0 ; end1 = n-1;
    start2 = 0; end2 = n-1;
    while(start1!=end1 || start2 != end2)
    {
        mid1 = (start1 + end1)/2;
        mid2 = (start2 + end2)/2;
        if(A[mid1].key == B[mid2].key)
            return A[mid1].key;
        if(A[mid1].key<B[mid2].key)
        {
            if((start1 + end1)%2 == 0)
            {
                start1 = mid1;
                end2 = mid2;
            }
            else
            {
                start1 = mid1 + 1;
                end2 = mid2;
            }
        }
        else 
        {
            if((start1 + end1)%2 == 0)
            {
                end1 = mid1;
                start2 = mid2;
            }
            else
            {
                end1 = mid1;
                start2 = mid2 + 1;
            }
        }
    }

    return A[start1].key<B[start2].key?A[start1].key:B[start2].key;
}

int main()
{
    KeyType keys1[] = {11, 13, 15, 17, 19};
    KeyType keys2[] = {2, 4, 6, 8, 20};
    int n = 5, i;
    RecType A[MAXL], B[MAXL];
    for(i=0;i<n;i++)
        A[i].key = keys1[i];
    for(i=0;i<n;i++)
        B[i].key = keys2[i];
    printf("A:");
    for(i=0;i<n;i++)    printf("%3d", A[i].key);
    printf("\n");
    printf("B:");
    for(i=0;i<n;i++)    printf("%3d", B[i].key);
    printf("\n");
    printf("The mid-number of A and B is %d\n", M_Search(A, B, n));
    return 1;
}