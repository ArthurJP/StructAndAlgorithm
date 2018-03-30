////
//// Created by 张俊鹏 on 2017/7/8.
////
//
//#include <mem.h>
//#include <ctype.h>
//#include "stdio.h"
//#include "stdlib.h"
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXSIZE 10
//
//typedef int Status;
//typedef double SElemType; /* SElemType类型根据实际情况而定，这里假设为int */
//typedef char SqElemType;
//
//typedef struct StackNode {
//    SElemType data;
//    struct StackNode *next;
//} StackNode, *LinkStackPtr;
//
//typedef struct {
//    LinkStackPtr top;
//    int count;
//} LinkStack;
//
//Status visit(SElemType c) {
//    printf("%d", c);
//}
//
//Status InitStack(LinkStack *S) {
//    S->top = (LinkStackPtr) malloc(sizeof(StackNode));
//    if (!S->top)
//        return ERROR;
//    S->top = NULL;
//    S->count = 0;
//    return OK;
//}
//
///* 若栈S为空栈，则返回TRUE，否则返回FALSE */
//Status StackEmpty(LinkStack S) {
//    if (S.count == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* 返回S的元素个数，即栈的长度 */
//int StackLength(LinkStack S) {
//    return S.count;
//}
//
///* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
//Status GetTop(LinkStack S, SElemType *e) {
//    if (S.top == NULL)
//        return ERROR;
//    else
//        *e = S.top->data;
//    return OK;
//}
//
///* 把S置为空栈 */
//Status ClearStack(LinkStack *S) {
//    LinkStackPtr p, q;
//    p = S->top;
//    while (p) {
//        q = p;
//        p = p->next;
//        free(q);
//    }
//    S->top = p;
//    S->count = 0;
//    return OK;
//}
//
//Status Push(LinkStack *S, SElemType e) {
//    LinkStackPtr s = (LinkStackPtr) malloc(sizeof(StackNode));
//    s->data = e;
//    s->next = S->top;
//    S->top = s;
//    S->count++;
//    return OK;
//}
//
//Status Pop(LinkStack *S, SElemType *e) {
//    LinkStackPtr p;
//    if (StackEmpty(*S))
//        return ERROR;
//    *e = S->top->data;
//    p = S->top;
//    S->top = p->next;
//    free(p);
//    S->count--;
//    return OK;
//}
//
//
//#define MAXSIZE 10
//
//typedef struct {
//    SqElemType data[MAXSIZE];
//    int top;
//} SqStack;
//
//Status InitSqStack(SqStack *S) {
//    for (int i = 0; i < MAXSIZE; ++i) {
//        S->data[i] = 0;
//    }
//    S->top = -1;
//    return OK;
//}
//
//Status ClearSqStack(SqStack *S) {
//    S->top = -1;
//    return OK;
//}
//
//Status StackSqEmpty(SqStack S) {
//    if (S.top == -1)
//        return TRUE;
//    else
//        return FALSE;
//}
//
//Status SetSqElem(SqStack *S, SElemType e) {
//    if (S->top == -1)
//        return ERROR;
//    else
//        S->data[S->top] = e;
//    return OK;
//}
//
//Status GetSqElem(SqStack S, SElemType *e) {
//    if (S.top == -1)
//        return ERROR;
//    else
//        *e = S.data[S.top];
//    return OK;
//}
//
//int SqStackLength(SqStack S) {
//    return S.top + 1;
//}
//
///* 插入元素e为新的栈顶元素 */
//Status PushSq(SqStack *S, SqElemType e) {
//    if (S->top == MAXSIZE - 1)
//        return ERROR;
//    S->top++;
//    S->data[S->top] = e;
//    return OK;
//}
//
///* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
//Status PopSq(SqStack *S, SqElemType *e) {
//    if (S->top == -1)
//        return ERROR;
//    *e = S->data[S->top];
//    S->top--;
//    return OK;
//}
//
//int main() {
//    SqStack sq;
//    InitSqStack(&sq);
//    char a, b;  /*a用于读入用户输入数据，b用于临时取出栈的数据*/
//    char str[100];
//    int index = 0;
//
//    printf("请输入中缀表达式，#结束：");
//    scanf("%c", &a);
//
//    while ('#' != a) {
//        while (a >= '0' && a <= '9') {  /*判断是否是连续的数字*/
//            str[index++] = a;
////            printf("%s\n", str);
//            scanf("%c", &a);
//            if (a < '0' || a > '9') {   /*当下一个字符不为数字*/
//                str[index++] = ' ';
//            }
//        }
//        if (')' == a) {     /*如果为），则进行出栈操作，直到遇到（为止*/
//            PopSq(&sq, &b);
//            while ('(' != b) {
//                str[index++] = b;
//                str[index++] = ' ';
//                PopSq(&sq, &b);
//            }
//        } else if ('+' == a || '-' == a) {  /*如果遇到+-，则判断栈中上一个元素的优先级*/
//            if (!SqStackLength(sq)) {/*当栈中没有元素的时候*/
//                PushSq(&sq, a);
//            } else {  /*栈中还有元素的时候*/
//                do {
//                    PopSq(&sq, &b);
//                    if ('(' == b) /*如果是（则不做改动*/
//                        PushSq(&sq, b);
//                    else {   /*否则出栈*/
//                        str[index++] = b;
////                        str[index++] = ' ';
//                    }
//                } while (SqStackLength(sq) && '(' != b);
//                PushSq(&sq, a);  /*将新输入的字符入栈*/
//            }
//        } else if ('*' == a || '/' == a || '(' == a) {
//            PushSq(&sq, a);
//        } else if ('#' == a) {   /*因为录入数字的时候提供了输入接口，此处也必须判断是否为结束符号*/
//            break;
//        } else {
//            printf("\n用户输入错误！\n");
//            return -1;
//        }
//        scanf("%c", &a);
//    }
//    while (SqStackLength(sq) != 0) {
//        PopSq(&sq, &b);
//        str[index++] = b;
////        str[index++] = ' ';
//    }
//
//    for (int j = 0; j < index; ++j) {
//        printf("%c", str[j]);
//    }
//    printf("\n");
//
//    printf("####################################");
//
//    LinkStack s;
//    InitStack(&s);
//    char c;
//    double e, d;/*用于存取数据*/
//    char str_tmp[MAXSIZE];  /*用于充当缓冲区，保存字符*/
//    int i = 0;
//
////    printf("请输入后缀表达式，以空格隔开");
////    scanf("%c", &c);
//    index=0;
//    c=str[index++];
//    while (c != '#') {
//        while (isdigit(c) || c == '.') {
//            str_tmp[i++] = c;
//            str_tmp[i] = '\0';  /*提供结束位置*/
//            if (i >= MAXSIZE) {
//                printf("出错，输入的单个数据过大！");
//                return -1;
//            }
////            scanf("%c", &c);
//            c=str[index++];
//            if (c == ' ') {
//                d = atof(str_tmp);
//                Push(&s, d);
//                i = 0;
//                break;
//            }
//        }
//
//
//        switch (c) {
//            case '+':
//                Pop(&s, &e);
//                Pop(&s, &d);
//                Push(&s, d + e);
//                break;
//            case '-':
//                Pop(&s, &e);
//                Pop(&s, &d);
//                Push(&s, d - e);
//                break;
//            case '*':
//                Pop(&s, &e);
//                Pop(&s, &d);
//                Push(&s, d * e);
//                break;
//            case '/':
//                Pop(&s, &e);
//                Pop(&s, &d);
//                if (e != 0)
//                    Push(&s, d / e);
//                else {
//                    printf("\n出错，除数不能为0");
//                    return -1;
//                }
//                break;
//            default:
//                break;
//        }
////        scanf("%c", &c);
//        c=str[index++];
//    }
//    Pop(&s, &d);
//    printf("\n最终的计算结果为:%f\n", d);
//}
