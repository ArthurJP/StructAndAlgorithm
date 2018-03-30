//
///*
// Created by �ſ��� on 2017/7/5.
//*/
//
//
//#include <stdio.h>
//#include <malloc.h>
//#include <time.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
//
//Status visit(ElemType c) {
//    printf("%d ", c);
//    return OK;
//}
//
//typedef struct Node{
//    ElemType data;
//    struct Node *prior;
//    struct Node *next;
//}Node,*DoubleLinkedList;
//
//Status InitList(DoubleLinkedList *L){
//    *L=(DoubleLinkedList)malloc(sizeof(Node));
//    if (!*L)
//        return ERROR;
//    (*L)->prior=(*L)->next=*L;
//    return OK;
//}
//
//Status IsEmpty(DoubleLinkedList L){
//    if (L->next==L->prior)
//        return TRUE;
//    return FALSE;
//}
//
//Status ClearList(DoubleLinkedList *L){
//    DoubleLinkedList p,q;
//    (*L)=(*L)->next;
//    p=(*L)->next;
//    while(p!=(*L)){
//        q=p->next;
//        free(p);
//        p=q;
//    }
//    (*L)->next=(*L)->prior=*L;
//    return OK;
//}
//
//int ListLength(DoubleLinkedList L){
//    int j=0;
//    DoubleLinkedList p=L->next->next;
//    while(p!=L->next){
//        j++;
//        p=p->next;
//    }
//    return j;
//}
//
//Status GetElem(DoubleLinkedList L,int i,ElemType *e){
//    DoubleLinkedList p=L->next->next;
//    int j=1;
//    if (i<1||i>ListLength(L))
//        return ERROR;
//    while(j<i){
//        p=p->next;
//        j++;
//    }
//    *e=p->data;
//    return OK;
//}
//
//int LocateElem(DoubleLinkedList L,ElemType e){
//    int i=0;
//    DoubleLinkedList p=L->next->next;
//    while(p!=L->next){
//        i++;
//        if (p->data==e)
//            return i;
//        p=p->next;
//    }
//    return 0;
//}
//
//Status ListInsert(DoubleLinkedList *L,int i,ElemType e){
//    if (i<1||i>ListLength(*L)+1)
//        return ERROR;
//    int j=1;
//    DoubleLinkedList p=(*L)->next,s;
//    while(j<i){
//        p=p->next;
//        j++;
//    }
//    s=(DoubleLinkedList)malloc(sizeof(Node));
//    s->data=e;
//    p->next->prior=s;
//    s->next=p->next;
//    p->next=s;
//    s->prior=p;
//    if(p==*L)
//        *L=s;
//    return OK;
//}
//
//Status ListDelete(DoubleLinkedList *L,int i,ElemType *e){
//    if (i<1||i>ListLength(*L))
//        return ERROR;
//    int j=1;
//    DoubleLinkedList p=(*L)->next,q;
//    while(j<i){
//        p=p->next;
//        j++;
//    }
//    q=p->next;
//    p->next=q->next;
//    q->next->prior=p;
//    *e=q->data;
//    if (q==*L)
//        *L=p;
//    free(q);
//    return OK;
//}
//
//Status ListTraverse(DoubleLinkedList L){
//    DoubleLinkedList p=L->next->next;
//    while(p!=L->next){
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
//void CreateListHead(DoubleLinkedList *L,int n){
//    srand((unsigned int) time(0));
//    InitList(L);
//    for (int i = 0; i < n; ++i) {
//        ListInsert(L,1,rand()%100+1);
//    }
//}
//
//void CreateListTail(DoubleLinkedList *L,int n){
//    srand((unsigned int) time(0));
//    InitList(L);
//    for (int i = 0; i < n; ++i) {
//        ListInsert(L,i,rand()%100+1);
//    }
//}
//
//int main() {
//    DoubleLinkedList L;
//    ElemType e;
//    Status i;
//    int j, k;
//    i = InitList(&L);
//    printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
//    for (j = 1; j <= 5; j++)
//        i = ListInsert(&L, 1, j);
//    printf("��L�ı�ͷ���β���1��5��L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//    i = IsEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    i = ClearList(&L);
//    printf("���L��ListLength(L)=%d\n", ListLength(L));
//    i = IsEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    for (j = 1; j <= 10; j++)
//        ListInsert(&L, j, j);
//    printf("��L�ı�β���β���1��10��L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    ListInsert(&L, 1, 0);
//    printf("��L�ı�ͷ����0��L.data=");
//    ListTraverse(L);
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    GetElem(L, 5, &e);
//    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
//    for (j = 3; j <= 4; j++) {
//        k = LocateElem(L, j);
//        if (k)
//            printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
//        else
//            printf("û��ֵΪ%d��Ԫ��\n", j);
//    }
//
//    k = ListLength(L); /* kΪ�� */
//    for (j = k + 1; j >= k; j--) {
//        i = ListDelete(&L, j, &e); /* ɾ����j������ */
//        if (i == ERROR)
//            printf("ɾ����%d������ʧ��\n", j);
//        else
//            printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//    }
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    j = 5;
//    ListDelete(&L, j, &e); /* ɾ����5������ */
//    printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\n���L��ListLength(L)=%d\n", ListLength(L));
//    CreateListHead(&L, 20);
//    printf("���崴��L��Ԫ��(ͷ�巨)��");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
//    CreateListTail(&L, 20);
//    printf("���崴��L��Ԫ��(β�巨)��");
//    ListTraverse(L);
//
//
//    return 0;
//}