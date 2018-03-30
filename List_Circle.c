////
//// Created by 张俊鹏 on 2017/7/4.
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
//typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
//
//Status visit(ElemType c) {
//    printf("%d ", c);
//    return OK;
//}
//
///*
// * 为了保证所有操作的一致性，添加头结点，头指针指向头结点
// * 头结点没有实际意义，或者用于保存链表的长度
// * 头结点不是链表的必要元素，删掉后需要很多位置判断，该案例中选择使用空间换时间
// */
//typedef struct Node{
//    ElemType data;
//    struct Node *next;
//}Node;
//
//typedef struct Node *CircleList;//定义指针类型结点
//
///* 初始化顺序线性表 */
//Status InitList(CircleList *L){
//    *L=(CircleList)malloc(sizeof(Node));
//    if (!*L)
//        return ERROR;
//    (*L)->next=*L;
//
//    return OK;
//}
//
///* 初始条件：循环线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
//Status ListEmpty(CircleList L) {
//    if (L->next == L)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
//Status ClearList(CircleList *L){
//    CircleList p,q;
//    (*L)=(*L)->next;/* L指向头结点 */
//    p=(*L)->next;/* p指向第一个结点 */
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
//    CircleList p=L->next; /* p指向头结点 */
//    while (p!=L){ /*没到表尾*/
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
///* 初始条件：线性表L已存在，compare()是数据元素判定函数 */
///* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。*/
///*           若这样的数据元素不存在，则返回值为0 */
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
///* 在L的第i个位置之前插入元素e */
//Status ListInsert(CircleList *L,int i,ElemType e){
//    int j=1;
//    CircleList p=(*L)->next,s;
//    if (i<1||i>ListLength(*L)+1)/* 无法在第i个元素之前插入 */
//        return ERROR;
//    while(j<i){/*找到前一个结点*/
//        p=p->next;
//        j++;
//    }
//    s=(CircleList)malloc(sizeof(Node));
//    s->data=e;
//    s->next=p->next;
//    p->next=s;
//    if(*L==p)/*改变尾结点*/
//        *L=s;
//    return OK;
//}
//
///* 删除L的第i个元素，并由e返回其值 */
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
//    printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
//    for (j = 1; j <= 5; j++)
//        i = ListInsert(&L, 1, j);
//    printf("在L的表头依次插入1～5后：L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//    i = ListEmpty(L);
//    printf("L是否空：i=%d(1:是 0:否)\n", i);
//
//    i = ClearList(&L);
//    printf("清空L后：ListLength(L)=%d\n", ListLength(L));
//    i = ListEmpty(L);
//    printf("L是否空：i=%d(1:是 0:否)\n", i);
//
//    for (j = 1; j <= 10; j++)
//        ListInsert(&L, j, j);
//    printf("在L的表尾依次插入1～10后：L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    ListInsert(&L, 1, 0);
//    printf("在L的表头插入0后：L.data=");
//    ListTraverse(L);
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    GetElem(L, 5, &e);
//    printf("第5个元素的值为：%d\n", e);
//    for (j = 3; j <= 4; j++) {
//        k = LocateElem(L, j);
//        if (k)
//            printf("第%d个元素的值为%d\n", k, j);
//        else
//            printf("没有值为%d的元素\n", j);
//    }
//
//    k = ListLength(L); /* k为表长 */
//    for (j = k + 1; j >= k; j--) {
//        i = ListDelete(&L, j, &e); /* 删除第j个数据 */
//        if (i == ERROR)
//            printf("删除第%d个数据失败\n", j);
//        else
//            printf("删除第%d个的元素值为：%d\n", j, e);
//    }
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    j = 5;
//    ListDelete(&L, j, &e); /* 删除第5个数据 */
//    printf("删除第%d个的元素值为：%d\n", j, e);
//
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));
//    CreateListHead(&L, 20);
//    printf("整体创建L的元素(头插法)：");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\n删除L后：ListLength(L)=%d\n", ListLength(L));
//    CreateListTail(&L, 20);
//    printf("整体创建L的元素(尾插法)：");
//    ListTraverse(L);
//
//
//    return 0;
//}