////
//// Created by �ſ��� on 2017/7/8.
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
//typedef double SElemType; /* SElemType���͸���ʵ������������������Ϊint */
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
///* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
//Status StackEmpty(LinkStack S) {
//    if (S.count == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* ����S��Ԫ�ظ�������ջ�ĳ��� */
//int StackLength(LinkStack S) {
//    return S.count;
//}
//
///* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
//Status GetTop(LinkStack S, SElemType *e) {
//    if (S.top == NULL)
//        return ERROR;
//    else
//        *e = S.top->data;
//    return OK;
//}
//
///* ��S��Ϊ��ջ */
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
///* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
//Status PushSq(SqStack *S, SqElemType e) {
//    if (S->top == MAXSIZE - 1)
//        return ERROR;
//    S->top++;
//    S->data[S->top] = e;
//    return OK;
//}
//
///* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
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
//    char a, b;  /*a���ڶ����û��������ݣ�b������ʱȡ��ջ������*/
//    char str[100];
//    int index = 0;
//
//    printf("��������׺���ʽ��#������");
//    scanf("%c", &a);
//
//    while ('#' != a) {
//        while (a >= '0' && a <= '9') {  /*�ж��Ƿ�������������*/
//            str[index++] = a;
////            printf("%s\n", str);
//            scanf("%c", &a);
//            if (a < '0' || a > '9') {   /*����һ���ַ���Ϊ����*/
//                str[index++] = ' ';
//            }
//        }
//        if (')' == a) {     /*���Ϊ��������г�ջ������ֱ��������Ϊֹ*/
//            PopSq(&sq, &b);
//            while ('(' != b) {
//                str[index++] = b;
//                str[index++] = ' ';
//                PopSq(&sq, &b);
//            }
//        } else if ('+' == a || '-' == a) {  /*�������+-�����ж�ջ����һ��Ԫ�ص����ȼ�*/
//            if (!SqStackLength(sq)) {/*��ջ��û��Ԫ�ص�ʱ��*/
//                PushSq(&sq, a);
//            } else {  /*ջ�л���Ԫ�ص�ʱ��*/
//                do {
//                    PopSq(&sq, &b);
//                    if ('(' == b) /*����ǣ������Ķ�*/
//                        PushSq(&sq, b);
//                    else {   /*�����ջ*/
//                        str[index++] = b;
////                        str[index++] = ' ';
//                    }
//                } while (SqStackLength(sq) && '(' != b);
//                PushSq(&sq, a);  /*����������ַ���ջ*/
//            }
//        } else if ('*' == a || '/' == a || '(' == a) {
//            PushSq(&sq, a);
//        } else if ('#' == a) {   /*��Ϊ¼�����ֵ�ʱ���ṩ������ӿڣ��˴�Ҳ�����ж��Ƿ�Ϊ��������*/
//            break;
//        } else {
//            printf("\n�û��������\n");
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
//    double e, d;/*���ڴ�ȡ����*/
//    char str_tmp[MAXSIZE];  /*���ڳ䵱�������������ַ�*/
//    int i = 0;
//
////    printf("�������׺���ʽ���Կո����");
////    scanf("%c", &c);
//    index=0;
//    c=str[index++];
//    while (c != '#') {
//        while (isdigit(c) || c == '.') {
//            str_tmp[i++] = c;
//            str_tmp[i] = '\0';  /*�ṩ����λ��*/
//            if (i >= MAXSIZE) {
//                printf("��������ĵ������ݹ���");
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
//                    printf("\n������������Ϊ0");
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
//    printf("\n���յļ�����Ϊ:%f\n", d);
//}
