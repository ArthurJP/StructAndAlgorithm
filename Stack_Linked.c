////
//// Created by 张俊鹏 on 2017/7/7.
////
//
//#include <stdio.h>
//#include <malloc.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int SElemType; //定义数据类型，方便以后修改
//typedef char Status;
//
//Status visit(SElemType c){
//    printf("%d ",c);
//    return OK;
//}
//
//typedef struct StackNode{
//    SElemType data;
//    struct StackNode *next;
//}StackNode,*LinkStackPtr;
//
//typedef struct LinkStack{
//    LinkStackPtr top;
//    int count;
//}LinkStack;
//
//Status InitStack(LinkStack *S) {
//    S->top=(LinkStackPtr)malloc(sizeof(StackNode));
//    if (!S->top)
//        return ERROR;
//    S->top=NULL;
//    S->count=0;
//    return OK;
//}
//
//Status ClearStack(LinkStack *S) {
//    LinkStackPtr p = S->top,q;
//    while(p){
//        q=p->next;
//        free(p);
//        p=q;
//    }
//    S->top=p;
//    S->count=0;
//    return OK;
//}
//
//Status StackEmpty(LinkStack S) {
//    if (S.count == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
//int StackLength(LinkStack S) {
//    return S.count;
//}
//
//Status GetTop(LinkStack S, SElemType *e) {
//    if (S.top == NULL)
//        return ERROR;
//    else
//        *e = S.top->data;
//    return OK;
//}
//
///* 插入元素e为新的栈顶元素 */
//Status Push(LinkStack *S, SElemType e) {
//    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
//    s->data=e;
//    s->next=S->top;
//    S->top=s;
//    S->count++;
//    return OK;
//}
//
///* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
//Status Pop(LinkStack *S, SElemType *e) {
//    if (StackEmpty(*S))
//        return ERROR;
//    LinkStackPtr p=S->top;
//    *e=p->data;
//    S->top=p->next;
//    free(p);
//    S->count--;
//    return OK;
//}
//
//Status StackTraverse(LinkStack S) {
//    LinkStackPtr p=S.top;
//    for (int i = 0; i < S.count; ++i) {
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
//int main() {
//    int j;
//    LinkStack s;
//    int e;
//    if (InitStack(&s) == OK)
//        for (j = 1; j <= 10; j++)
//            Push(&s, j);
//    printf("栈中元素依次为：");
//    StackTraverse(s);
//    Pop(&s, &e);
//    printf("弹出的栈顶元素 e=%d\n", e);
//    printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
//    GetTop(s, &e);
//    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
//    ClearStack(&s);
//    printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
//    return 0;
//}