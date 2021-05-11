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
        printf(">1：排队 2：就诊 3：查看排队 4：不在排队，余下依次就诊 5：下班  请选择：");
        scanf("%d",&sel);
        switch(sel){
            case 1:
                printf("请输入病历号：");
                while(true){
                    scanf("%d",&no);
                    if(exist(qu,no))
                        printf("输入病历号重复，请重新输入：");
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
                    printf("没有排队看病的病人");
                else{
                    p=qu->front;
                    printf(">>病人 %d 就诊\n",p->data);
                    if(qu->rear==p)
                        qu->front=qu->rear=NULL;
                    else    
                        qu->front=p->next;
                    free(p);
                }
                break;
            case 3:
                if(qu->front==NULL)
                    printf("没有排队看病的病人");
                else{
                    p=qu->front;
                    printf(">>排队病人：");
                    while(p!=NULL){
                        printf("%d\t",p->data);
                        p=p->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                if(qu->front==NULL)
                    printf("没有排队看病的病人");
                else{
                    p=qu->front;
                    printf("  >>病人请按一下顺序就诊：");
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
                    printf("排队的病人请明天就医！\n");
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

