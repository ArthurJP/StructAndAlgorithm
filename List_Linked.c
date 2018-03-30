////
//// Created by 张俊鹏 on 2017/6/30.
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
//typedef struct Node {
//    ElemType data;  //数据域
//    struct Node *next;//指针域
//} Node;
//
//typedef struct Node *LinkList;//定义指针类型结点
//
///* 初始化顺序线性表 */
//Status InitList(LinkList *L) {
//    *L = (LinkList) malloc(sizeof(Node));
//    if (!(*L))
//        return ERROR;
//    (*L)->next = NULL;
//
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
//Status ListEmpty(LinkList L) {
//    if (L->next)
//        return FALSE;
//    else
//        return TRUE;
//}
//
///*
// * 单链表的整体删除 思路:
// * 1、声明结点p，q；
// * 2、将第一个结点赋值给p；
// * 3、LOOP
// *      将下一个结点赋值给q；
// *      释放p；
// *      将q赋值给p；
// */
//Status ClearList(LinkList *L) {
//    LinkList p, q;
//    p = (*L)->next;
//    while (p) {
//        q = p->next;
//        free(p);
//        p = q;
//    }
//    (*L)->next = NULL;
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
//int ListLength(LinkList L) {
//    int i = 0;
//    LinkList p = L->next;/*指向头结点*/
//    while (p) {
//        i++;
//        p = p->next;
//    }
//    return i;
//}
//
///*
// * 获取第i个单链表元素  思路：
// * 1、声明一个结点p指向链表第一个结点，初始化j从1开始
// * 2、当j<i时，就遍历链表，让p的指针不断向后移，不断指向下一个结点，j累加1
// * 3、若j到达链表结尾，则说明第i个元素不存在，返回ERROR
// * 4、若查找成功，返回结点p的数据
// */
///* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
///* 操作结果：用e返回L中第i个数据元素的值 */
//Status GetElem(LinkList list, int i, ElemType *e) {//此处list不需要修改，所以以一级指针形式传入
//    int j = 1;//标记当前指针位置
//    LinkList p = list->next;//获得可移动指针，保留原头指针位置
//    while (p && j < i) {//如果当前结点存在，并且尚未到达i位置
//        p = p->next;
//        j++;
//    }
//    if (!p || j > i)//如果p结点不存在，或者i输入的值小于1
//        return ERROR;
//    *e = p->data;/*将结点数据返回*/
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在 */
///* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
///* 若这样的数据元素不存在，则返回值为0 */
//int LocateElem(LinkList L,ElemType e){
//    int i=0;
//    LinkList p=L->next;
//    while(p){
//        i++;
//        if (p->data==e)
//            return i;
//        p=p->next;
//    }
//    return 0;
//}
//
///*
// * 单链表第i个数据插入结点 思路：
// * 1、声明一个结点p指向链表，初始化j从1开始；
// * 2、当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1；
// * 3、若到链表末尾p为null，说明第i个元素不存在；
// * 4、否则说明查找成功，在系统中生成一个空节点s；
// * 5、将数据元素e赋值给s->data；
// * 6、单链表的插入标准语句s->next=p->next; p->next=s;
// * 7、返回成功；
// */
///* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
///* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
//Status ListInsert(LinkList *L, int i, ElemType e) {//由于此处需要修改原链表的内容，使用二级指针传入；一下同理
//    int j = 1;
//    LinkList p = *L;//由于是第i个结点位置插入，所以要停在i-1结点位置
//    LinkList s;
//    while (p && j < i) {
//        p = p->next;
//        j++;
//    }
//    if (!p || j > i)/*如果p结点不存在,或者i输入的值小于1*/
//        return ERROR;
//    s = (LinkList) malloc(sizeof(Node));//这里注意：Node才是结构体类型，小心设置为LinkList（指针类型，默认八位）
//    s->data = e;
//    s->next = p->next;  /* 将p的后继结点赋值给s的后继  */
//    p->next = s;    /* 将s赋值给p的后继 */
//    return OK;
//}
//
///*
// * 单链表删除第i个结点 思路：
// * 1、声明一个结点p指向链表，初始化j从1开始(因为要到达该删除结点的前驱结点)；
// * 2、当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1；
// * 3、若到链表末尾p为空，则说明第i个元素不存在；
// * 4、否则查找成功，将p->next的地址保存在q中，以保存现场，防止p->变成无法访问的结点却无法回收；
// * 5、单链表的删除指令：p->next=q->next；
// * 6、将q中的数据赋值给e，作为返回值；
// * 7、释放q结点；
// * 8、返回成功；
// */
//Status ListDelete(LinkList *L, int i, ElemType *e) {
//    int j = 1;
//    LinkList p, q;//此处用了typedef定义的LinkList，所以p,q都为指针类型
//    p = *L;
//    while (p && j < i) {//用于寻找第i个结点
//        p = p->next;
//        j++;
//    }
//    if (!(p->next) || j > i)/*如果p结点不存在，或者i输入的值小于1*/
//        return ERROR;
//    q = p->next;
//    p->next = q->next;//将q的后继赋值给p的后继
//    *e = q->data;//保存q结点数据，我认为是以防执行失败，支持回滚操作
//    free(q);//回收垃圾函数
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在 */
///* 操作结果：依次对L的每个数据元素输出 */
//Status ListTraverse(LinkList L){
//    LinkList p=L->next;
//    while(p){
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
///*
// * 单链表整表创建 思路1：头插法
// * 1、声明一个结点p和计数器变量i；
// * 2、初始化以空链表L；
// * 3、让L的头结点的指针指向NULL，即建立一个带头结点的单链表；
// * 4、LOOP:
// *      生成一个新结点赋值给p；
// *      随机生成一个数字赋值给p的数据域p->data;
// *      将p插入到头结点与前一新结点之间
// */
//void CreateListHead(LinkList *L, int n) {
//    LinkList p;
//    srand((unsigned int) time(0));
//    *L = (LinkList) malloc(sizeof(Node));//L为二级指针，*p可以获取LinkList的头指针
//    (*L)->next = NULL;//将头指针的后继指向NULL，以防内存溢出
//    for (int i = 0; i < n; ++i) {
//        p = (LinkList) malloc(sizeof(Node));
//        p->data = rand() % 100 + 1;
//        p->next = (*L)->next;
//        (*L)->next = p;//插入到表头
//    }
//}
//
///*
// * 单链表整表创建 思路2：尾插法
// * 相较于头插法，尾插法需要保存头指针；故使用一个临时指针r来移动链表结点
// */
//void CreateListTail(LinkList *L, int n) {
//    LinkList p, r;
//    srand((unsigned int) time(0));
//    *L = (LinkList) malloc(sizeof(Node));
//    r = *L;
//    for (int i = 0; i < n; ++i) {
//        p = (LinkList) malloc(sizeof(Node));
//        p->data = rand() % 100 + 1;
//        r->next = p;
//        r = p;
//    }
//    r->next = NULL;
//}
//
//
//int main() {
//    LinkList L;
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
