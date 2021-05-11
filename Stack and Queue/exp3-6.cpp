#include<stdio.h>
#include<malloc.h>

typedef struct qnode{
    int data;
    struct qnode *next;
}QNode;

typedef struct{
    QNode *front,*rear;
}QuType;

void Destroyqueue(QuType *&qu)
{
    QNode *pre,*p;
    pre=qu->front;
    if(pre!=NULL){
        p=pre->next;
        while(p!=NULL){
            free(pre);
            pre=p;p=p->next;
        }
    }
    free(qu);
}

bool exist(QuType *qu,int no)
{
    QNode *p=qu->front;
    while(p!=NULL&&p->data!=no){
        p=p->next;
    }
    if(p!=NULL)
        return true;
    return false;
}

void seeDoctor()
{
    int sel,no;
    bool flag=true;
    QuType *qu;
    QNode *p;
    //printf("begin");
    qu=(QuType*)malloc(sizeof(QuType));
    qu->front=qu->rear=NULL;
    //printf("test");
    while(flag){
        printf(">1���Ŷ� 2������ 3���鿴�Ŷ� 4�������Ŷӣ��������ξ��� 5���°�  ��ѡ��");
        scanf("%d",&sel);
        switch(sel){
            case 1:
                printf("�����벡���ţ�");
                while(true){
                    scanf("%d",&no);
                    if(exist(qu,no))
                        printf("���벡�����ظ������������룺");
                    else
                        break;
                };
                p=(QNode*)malloc(sizeof(QNode));
                p->data=no;p->next=NULL;
                if(qu->rear==NULL)
                    qu->front=qu->rear=p;
                else{
                    qu->rear->next=p;
                    qu->rear=p;
                }
                break;
            case 2:
                if(qu->front==NULL)
                    printf("û���Ŷӿ����Ĳ���");
                else{
                    p=qu->front;
                    printf(">>���� %d ����\n",p->data);
                    if(qu->rear==p)
                        qu->front=qu->rear=NULL;
                    else    
                        qu->front=p->next;
                    free(p);
                }
                break;
            case 3:
                if(qu->front==NULL)
                    printf("û���Ŷӿ����Ĳ���");
                else{
                    p=qu->front;
                    printf(">>�ŶӲ��ˣ�");
                    while(p!=NULL){
                        printf("%d\t",p->data);
                        p=p->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                if(qu->front==NULL)
                    printf("û���Ŷӿ����Ĳ���");
                else{
                    p=qu->front;
                    printf("  >>�����밴һ��˳����");
                    while(p!=NULL){
                        printf("%d",p->data);
                        p=p->next;
                    }
                    printf("\n");
                }
                Destroyqueue(qu);
                flag=false;
                break;
            case 5:
                if(qu->front!=NULL)
                    printf("�ŶӵĲ����������ҽ��\n");
                flag=false;
                Destroyqueue(qu);
                break;
        }
    }
}

int main()
{
    seeDoctor();
    return 1;
}

