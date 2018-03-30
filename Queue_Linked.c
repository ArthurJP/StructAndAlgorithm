////
//// Created by 张俊鹏 on 2017/7/10.
////
//
//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//typedef int QElemType;
//
//typedef struct QNode{/*节点结构*/
//    QElemType data;
//    struct QNode *next;
//}QNode,*QueuePtr;
//
//typedef struct{
//    QueuePtr front,rear;
//}LinkQueue;
//
//Status visit(QElemType c){
//    printf("%d ",c);
//    return OK;
//}
//
///* 构造一个空队列Q */
//Status InitQueue(LinkQueue *Q){
//    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
//    if(!Q->front)
//        exit(OVERFLOW);
//    Q->front->next=NULL;
//    return OK;
//}
//
///* 销毁队列Q */
//Status DestroyQueue(LinkQueue *Q){
//    while(Q->front){
//        Q->rear=Q->front->next;
//        free(Q->front);
//        Q->front=Q->rear;
//    }
//    return OK;
//}
//
///* 将Q清为空队列 */
//Status ClearQueue(LinkQueue *Q){
//    QueuePtr p=Q->front->next,q;
//    while(p){
//        q=p->next;
//        free(p);
//        p=q;
//    }
//    Q->rear=Q->front;
//    Q->front->next=NULL;
//    return OK;
//}
//
//Status QueueEmpty(LinkQueue Q){
//    if (Q.front==Q.rear)
//        return TRUE;
//    else
//        return FALSE;
//}
//
//int QueueLength(LinkQueue Q){
//    int i=0;
//    QueuePtr p=Q.front;
//    while(Q.rear!=p){
//        i++;
//        p=p->next;
//    }
//    return i;
//}
//
///* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
//Status GetHead(LinkQueue Q,QElemType *e){
//    if(Q.front==Q.rear)
//        return ERROR;
//    QueuePtr p=Q.front->next;
//    *e=p->data;
//    return OK;
//}
//
///* 插入元素e为Q的新的队尾元素 */
//Status EnQueue(LinkQueue *Q,QElemType e){
//    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
//    if (!s)
//        return ERROR;
//    s->data=e;
//    s->next=NULL;
//    Q->rear->next=s;    /*将尾指针的后继指向新结点*/
//    Q->rear=s;      /*将新结点设置为尾结点*/
//    return OK;
//}
//
///* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
//Status DeQueue(LinkQueue *Q,QElemType *e){
//    if (Q->front==Q->rear)
//        return ERROR;
//    QueuePtr p=Q->front->next;
//    *e=p->data;
//    Q->front->next=p->next;
//    if (Q->rear==p)
//        Q->rear=Q->front;
//    free(p);
//    return OK;
//}
//
///* 从队头到队尾依次对队列Q中每个元素输出 */
//Status QueueTraverse(LinkQueue Q)
//{
//    QueuePtr p;
//    p=Q.front->next;
//    while(p)
//    {
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
//int main()
//{
//    int i;
//    QElemType d;
//    LinkQueue q;
//    i=InitQueue(&q);
//    if(i)
//        printf("成功地构造了一个空队列!\n");
//    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
//    printf("队列的长度为%d\n",QueueLength(q));
//    EnQueue(&q,-5);
//    EnQueue(&q,5);
//    EnQueue(&q,10);
//    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",QueueLength(q));
//    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
//    printf("队列的元素依次为：");
//    QueueTraverse(q);
//    i=GetHead(q,&d);
//    if(i==OK)
//        printf("队头元素是：%d\n",d);
//    DeQueue(&q,&d);
//    printf("删除了队头元素%d\n",d);
//    i=GetHead(q,&d);
//    if(i==OK)
//        printf("新的队头元素是：%d\n",d);
//    ClearQueue(&q);
//    printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
//    DestroyQueue(&q);
//    printf("销毁队列后,q.front=%u q.rear=%u\n",q.front, q.rear);
//
//    return 0;
//}
//
