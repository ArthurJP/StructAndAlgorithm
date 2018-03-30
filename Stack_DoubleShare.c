////
//// Created by �ſ��� on 2017/7/6.
////
//
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 10
//
//typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int SElemType;
//
//
//Status visit(SElemType c) {
//    printf("%d ", c);
//    return OK;
//}
//
//
//typedef struct {
//    SElemType data[MAXSIZE];
//    int top1;
//    int top2;
//} SqStack;
//
//Status InitStack(SqStack *S) {
//    S->top1 = -1;
//    S->top2=MAXSIZE;
//    return OK;
//}
//
//Status ClearStack(SqStack *S) {
//    S->top1 = -1;
//    S->top2=MAXSIZE;
//    return OK;
//}
//
//Status StackEmpty(SqStack S) {
//    if (S.top1 == -1&&S.top2==MAXSIZE)
//        return TRUE;
//    else
//        return FALSE;
//}
//
//int StackLength(SqStack S) {
//    return S.top1 + 1+(MAXSIZE-S.top2);
//}
//
///* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
//Status Push(SqStack *S, SElemType e,int stackNumber) {
//    if (S->top1+1 == S->top2)
//        return ERROR;
//    if (stackNumber==1)
//        S->data[++S->top1]=e;
//    else if (stackNumber==2)
//        S->data[--S->top2]=e;
//    return OK;
//}
//
///* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
//Status Pop(SqStack *S, SElemType *e,int stackNumber) {
//    if (stackNumber==1){
//        if (S->top1==-1)
//            return ERROR;
//        *e=S->data[S->top1--];
//    }else if (stackNumber==2){
//        if (S->top2==MAXSIZE)
//            return ERROR;
//        *e=S->data[S->top2++];
//    }
//    return OK;
//}
//
//Status StackTraverse(SqStack S) {
//    int i = 0;
//    while (i <= S.top1)
//        visit(S.data[i++]);
//    i=S.top2;
//    while(i<MAXSIZE)
//        visit(S.data[i++]);
//    printf("\n");
//    return OK;
//}
//
//int main()
//{
//    int j;
//    SqStack s;
//    int e;
//    if(InitStack(&s)==OK)
//    {
//        for(j=1;j<=5;j++)
//            Push(&s,j,1);
//        for(j=MAXSIZE;j>=MAXSIZE-2;j--)
//            Push(&s,j,2);
//    }
//
//    printf("ջ��Ԫ������Ϊ��");
//    StackTraverse(s);
//
//    printf("��ǰջ��Ԫ���У�%d \n",StackLength(s));
//
//    Pop(&s,&e,2);
//    printf("������ջ��Ԫ�� e=%d\n",e);
//    printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
//
//    for(j=6;j<=MAXSIZE-2;j++)
//        Push(&s,j,1);
//
//    printf("ջ��Ԫ������Ϊ��");
//    StackTraverse(s);
//
//    printf("ջ����%d(1:�� 0:��)\n",Push(&s,100,1));
//
//
//    ClearStack(&s);
//    printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
//
//    return 0;
//}