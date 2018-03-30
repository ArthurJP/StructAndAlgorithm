////
//// Created by 张俊鹏 on 2017/7/6.
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
//typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
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
///* 插入元素e为新的栈顶元素 */
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
///* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
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
//    printf("栈中元素依次为：");
//    StackTraverse(s);
//
//    printf("当前栈中元素有：%d \n",StackLength(s));
//
//    Pop(&s,&e,2);
//    printf("弹出的栈顶元素 e=%d\n",e);
//    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
//
//    for(j=6;j<=MAXSIZE-2;j++)
//        Push(&s,j,1);
//
//    printf("栈中元素依次为：");
//    StackTraverse(s);
//
//    printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));
//
//
//    ClearStack(&s);
//    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
//
//    return 0;
//}