////
//// Created by �ſ��� on 2017/7/4.
////
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
///*
// * Ϊ�˱�֤���в�����һ���ԣ����ͷ��㣬ͷָ��ָ��ͷ���
// * ͷ���û��ʵ�����壬�������ڱ�������ĳ���
// * ͷ��㲻������ı�ҪԪ�أ�ɾ������Ҫ�ܶ�λ���жϣ��ð�����ѡ��ʹ�ÿռ任ʱ��
// */
//typedef struct Node{
//    ElemType data;
//    struct Node *next;
//}Node;
//
//typedef struct Node *CircleList;//����ָ�����ͽ��
//
///* ��ʼ��˳�����Ա� */
//Status InitList(CircleList *L){
//    *L=(CircleList)malloc(sizeof(Node));
//    if (!*L)
//        return ERROR;
//    (*L)->next=*L;
//
//    return OK;
//}
//
///* ��ʼ������ѭ�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//Status ListEmpty(CircleList L) {
//    if (L->next == L)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
//Status ClearList(CircleList *L){
//    CircleList p,q;
//    (*L)=(*L)->next;/* Lָ��ͷ��� */
//    p=(*L)->next;/* pָ���һ����� */
//    while(p!=*L){
//        q=p->next;
//        free(p);
//        p=q;
//    }
//    (*L)->next=(*L);
//    return OK;
//}
//
//int ListLength(CircleList L){
//    int i=0;
//    CircleList p=L->next; /* pָ��ͷ��� */
//    while (p!=L){ /*û����β*/
//        i++;
//        p=p->next;
//    }
//    return i;
//}
//
//Status GetElem(CircleList L,int i,ElemType *e){
//    int j=1;
//    CircleList p=L->next->next;
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
///* ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж����� */
///* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��*/
///*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
//int LocateElem(CircleList L,ElemType e){
//    int i=0;
//    CircleList p=L->next->next;
//    while(p!=L->next){
//        i++;
//        if (p->data==e)
//            return i;
//        p=p->next;
//    }
//    return 0;
//}
//
///* ��L�ĵ�i��λ��֮ǰ����Ԫ��e */
//Status ListInsert(CircleList *L,int i,ElemType e){
//    int j=1;
//    CircleList p=(*L)->next,s;
//    if (i<1||i>ListLength(*L)+1)/* �޷��ڵ�i��Ԫ��֮ǰ���� */
//        return ERROR;
//    while(j<i){/*�ҵ�ǰһ�����*/
//        p=p->next;
//        j++;
//    }
//    s=(CircleList)malloc(sizeof(Node));
//    s->data=e;
//    s->next=p->next;
//    p->next=s;
//    if(*L==p)/*�ı�β���*/
//        *L=s;
//    return OK;
//}
//
///* ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ */
//Status ListDelete(CircleList *L,int i,ElemType *e){
//    int j=1;
//    CircleList p=(*L)->next,q;
//    if (i<1||i>ListLength(*L))
//        return ERROR;
//    while(j<i){
//        p=p->next;
//        j++;
//    }
//    q=p->next;
//    p->next=q->next;
//    *e=q->data;
//    if (*L==q)
//        *L=p;
//    free(q);
//    return OK;
//}
//
//Status ListTraverse(CircleList L){
//    CircleList p=L->next->next;
//    while(p!=L->next){
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
//void CreateListHead(CircleList *L,int n){
//    CircleList p;
//    srand((unsigned int) time(0));
//    *L=(CircleList)malloc(sizeof(Node));
//    (*L)->next=*L;
//    for (int i = 0; i < n; ++i) {
//        p=(CircleList)malloc(sizeof(Node));
//        p->data=rand()%100+1;
//        p->next=(*L)->next;
//        (*L)->next=p;
//    }
//}
//
//void CreateListTail(CircleList *L,int n){
//    CircleList p,r;
//    srand((unsigned int) time(0));
//    *L=(CircleList)malloc(sizeof(Node));
//    r=*L;
//    for (int i = 0; i < n; ++i) {
//        p=(CircleList)malloc(sizeof(Node));
//        p->data=rand()%100+1;
//        r->next=p;
//        r=p;
//    }
//    r->next=*L;
//}
//
//int main() {
//    CircleList L;
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
//    i = ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    i = ClearList(&L);
//    printf("���L��ListLength(L)=%d\n", ListLength(L));
//    i = ListEmpty(L);
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