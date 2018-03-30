//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 20 /*存储空间初始分配量*/
//
//typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//typedef int ElemType;  /* ElemType类型根据实际情况而定，这里假设为int */
//
//Status visit(ElemType c)
//{
//    printf("%d ",c);
//    return OK;
//}
//
//typedef struct{
//    ElemType data[MAXSIZE]; //数组存储数据元素，最大值为MAXSIZE（0~MAXSIZE-1）
//    int length; //线性表当前长度
//} SqList;
//
//Status InitList(SqList *L){
//    L->length=0;
//    return OK;
//}
//
//Status ListEmpty(SqList L){
//    if(L.length==0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
//Status ClearList(SqList *L) {
//    L->length=0;
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
//int ListLength(SqList L) {
//    return L.length;
//}
//
///*
// * 思路：判断是否越界，如果在线性表中取出数据
// * 此函数只是为了取出线性表中的一个数据，所以使用SqList L，这种方式只能用L.data来取值，而不能改变原始数据的值
// */
//Status GetElem(SqList L,int i,ElemType *e){
//    if (L.length==0||i<1||i>L.length)
//        return ERROR;
//    *e=L.data[i-1];
//    return OK;
//}
//
///* 初始条件：顺序线性表L已存在 */
///* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
///* 若这样的数据元素不存在，则返回值为0 */
//int LocateElem(SqList L,ElemType e){
//    int i;
//    if (L.length==0)
//        return 0;
//    for (i = 0; i < L.length; ++i) {
//        if (L.data[i]==e){
//            break;
//        }
//    }
//    if (i>=L.length)
//        return 0;
//    return i+1;
//}
//
///*
// * 添加节点思路：
// * 1、判断是否线性表已满
// * 2、判断时候在队列中，不允许中间空一个位置来插入
// * 3、将需要插入位置后的所有数据元素后移一位
// * 4、插入
// * 5、将长度+1
// * 技巧：为了插入SqList中一个特定的数值，所以使用指针SqList *L，此时使用L->data可以修改其中的内容
// */
//Status ListInsert(SqList *L, int i, ElemType e){
//    if (L->length>MAXSIZE){
//        printf("顺序线性表已满");
//        return ERROR;
//    }
//    if (i<1||i>L->length+1){//超过length+1，有可能还在可以存储的区域，但是已经和队列不连接
//        printf("不在队列内\n");
//        return ERROR;
//    }
//    if (i<=L->length){//如果插入位置不在表尾
//        for (int j = L->length-1; j >= i-1 ; --j) //将插入位置以后的数据元素向后移一位
//            L->data[j+1]=L->data[j];
//    }
//    L->data[i-1]=e;//将新元素插入
//    L->length++;
//
//    return OK;
//}
//
///*
// * 删除节点思路：
// * 1、如果删除位置不合理，抛出异常
// * 2、删除元素
// * 3、将删除元素位置以后的所有元素向前移动一位
// * 4、表长度-1
// */
//Status ListDelete(SqList *L,int i,ElemType *e){
//    if (L->length==0)//线性表为空
//        return ERROR;
//    if (i<1||i>L->length)//删除位置不正确
//        return ERROR;
//    *e=L->data[i-1];
//    if(i<L->length){//如果删除的位置不是最后一位
//        for (int j = i; j < L->length; ++j) {
//            L->data[i-1]=L->data[i];
//        }
//    }
//    L->length--;
//    return OK;
//}
//
//Status ListTraverse(SqList L){
//    for (int i = 0; i < L.length; ++i)
//        visit(L.data[i]);
//    printf("\n");
//    return OK;
//}
//
//Status unionL(SqList *La,SqList Lb){
//    int La_length,Lb_length;
//    ElemType e;
//    La_length=ListLength(*La);
//    Lb_length=ListLength(Lb);
//    for (int i = 0; i < Lb_length; ++i) {
//        GetElem(Lb,i,&e);
//        if (!LocateElem(*La,e))
//            ListInsert(La,++La_length,e);
//    }
//}
//
//int main() {
//    SqList L;
//    ElemType e;
//    Status i;
//    int j,k;
//    i=InitList(&L);
//    printf("初始化L后：L.length=%d\n",L.length);
//    for(j=1;j<=5;j++)
//        i=ListInsert(&L,1,j);
//    printf("在L的表头依次插入1～5后：L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n",L.length);
//    i=ListEmpty(L);
//    printf("L是否空：i=%d(1:是 0:否)\n",i);
//
//    i=ClearList(&L);
//    printf("清空L后：L.length=%d\n",L.length);
//    i=ListEmpty(L);
//    printf("L是否空：i=%d(1:是 0:否)\n",i);
//
//    for(j=1;j<=10;j++)
//        ListInsert(&L,j,j);
//    printf("在L的表尾依次插入1～10后：L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n",L.length);
//
//    ListInsert(&L,1,0);
//    printf("在L的表头插入0后：L.data=");
//    ListTraverse(L);
//    printf("L.length=%d \n",L.length);
//
//    GetElem(L,5,&e);
//    printf("第5个元素的值为：%d\n",e);
//    for(j=3;j<=4;j++)
//    {
//        k=LocateElem(L,j);
//        if(k)
//            printf("第%d个元素的值为%d\n",k,j);
//        else
//            printf("没有值为%d的元素\n",j);
//    }
//
//
//    k=ListLength(L); /* k为表长 */
//    for(j=k+1;j>=k;j--)
//    {
//        i=ListDelete(&L,j,&e); /* 删除第j个数据 */
//        if(i==ERROR)
//            printf("删除第%d个数据失败\n",j);
//        else
//            printf("删除第%d个的元素值为：%d\n",j,e);
//    }
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    j=5;
//    ListDelete(&L,j,&e); /* 删除第5个数据 */
//    printf("删除第%d个的元素值为：%d\n",j,e);
//
//    printf("依次输出L的元素：");
//    ListTraverse(L);
//
//    //构造一个有10个数的Lb
//    SqList Lb;
//    i=InitList(&Lb);
//    for(j=6;j<=15;j++)
//        i=ListInsert(&Lb,1,j);
//    ListTraverse(Lb);
//
//    unionL(&L,Lb);
//
//    printf("依次输出合并了Lb的L的元素：");
//    ListTraverse(L);
//
//    return 0;
//}
