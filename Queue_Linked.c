////
//// Created by �ſ��� on 2017/7/10.
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
//typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int QElemType;
//
//typedef struct QNode{/*�ڵ�ṹ*/
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
///* ����һ���ն���Q */
//Status InitQueue(LinkQueue *Q){
//    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
//    if(!Q->front)
//        exit(OVERFLOW);
//    Q->front->next=NULL;
//    return OK;
//}
//
///* ���ٶ���Q */
//Status DestroyQueue(LinkQueue *Q){
//    while(Q->front){
//        Q->rear=Q->front->next;
//        free(Q->front);
//        Q->front=Q->rear;
//    }
//    return OK;
//}
//
///* ��Q��Ϊ�ն��� */
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
///* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
//Status GetHead(LinkQueue Q,QElemType *e){
//    if(Q.front==Q.rear)
//        return ERROR;
//    QueuePtr p=Q.front->next;
//    *e=p->data;
//    return OK;
//}
//
///* ����Ԫ��eΪQ���µĶ�βԪ�� */
//Status EnQueue(LinkQueue *Q,QElemType e){
//    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
//    if (!s)
//        return ERROR;
//    s->data=e;
//    s->next=NULL;
//    Q->rear->next=s;    /*��βָ��ĺ��ָ���½��*/
//    Q->rear=s;      /*���½������Ϊβ���*/
//    return OK;
//}
//
///* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
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
///* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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
//        printf("�ɹ��ع�����һ���ն���!\n");
//    printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
//    printf("���еĳ���Ϊ%d\n",QueueLength(q));
//    EnQueue(&q,-5);
//    EnQueue(&q,5);
//    EnQueue(&q,10);
//    printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
//    printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
//    printf("���е�Ԫ������Ϊ��");
//    QueueTraverse(q);
//    i=GetHead(q,&d);
//    if(i==OK)
//        printf("��ͷԪ���ǣ�%d\n",d);
//    DeQueue(&q,&d);
//    printf("ɾ���˶�ͷԪ��%d\n",d);
//    i=GetHead(q,&d);
//    if(i==OK)
//        printf("�µĶ�ͷԪ���ǣ�%d\n",d);
//    ClearQueue(&q);
//    printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
//    DestroyQueue(&q);
//    printf("���ٶ��к�,q.front=%u q.rear=%u\n",q.front, q.rear);
//
//    return 0;
//}
//