////
//// Created by 张俊鹏 on 2017/7/1.
////
//
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//
//#define MAXSIZE 8//以防数组溢出
//
//typedef int ElemType; //定义数据类型，方便以后修改
//typedef char Status;
//
//Status visit(ElemType c){
//    printf("%c ",c);
//    return OK;
//}
//
//typedef struct{
//    ElemType data;
//    int cur;//游标（Cursor），为0时表示无指向
//}StaticLinkList[MAXSIZE];
//
///* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
//Status InitList(StaticLinkList space){
//    for (int i = 0; i < MAXSIZE - 1; ++i)
//        space[i].cur=i+1;
//    space[MAXSIZE-1].cur=0;
//    return OK;
//}
//
///*
// * 获得空闲分量的下标
// */
///* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
//int Malloc_SSL(StaticLinkList space){
//    int i=space[0].cur;/* 当前数组第一个元素的cur存的值。就是要返回的第一个备用空闲的下标 */
//    if (space[0].cur)//如果拿出来一个分量使用了，将备用数组指向他的下一个分量
//        space[0].cur=space[i].cur;
//    return i;
//}
//
//void Free_SSL(StaticLinkList space,int k){
//    space[k].cur=space[0].cur;//将第一个元素的cur赋值给要删除的分量cur，即将要删除的分量cur指向备用空间的第一个
//    space[0].cur=k;
//}
//
//int ListLength(StaticLinkList L){
//    int j=0;
//    int i=L[MAXSIZE-1].cur;
//    while(i){
//        i=L[i].cur;
//        j++;
//    }
//    return j;
//}
//
///*
// * 插入第i个元素
// */
//Status ListInsert(StaticLinkList L,int i,ElemType e){
//    int j,k,l;
//    k=MAXSIZE-1;  //k获得最后一个元素的下标
//    if(i<1||i>ListLength(L)+1)/*输入值异常或者不连接队列*/
//        return ERROR;
//    j=Malloc_SSL(L);//获得空闲分量的下标
//    if(j){
//        L[j].data=e;//将数据赋值给此分量的data
//        for ( l = 1; l < i ; ++l)//找到第i个元素之前的位置
//            k=L[k].cur;
//        L[j].cur=L[k].cur;//把新元素的下标赋值给第i个元素之前元素的cur
//        L[k].cur=j;//把新元素的下标赋值给第i个元素之前元素的cur
//        return OK;
//    }
//    return ERROR;
//}
//
//Status ListDelete(StaticLinkList L,int i){
//    int j,k;
//    if (i<1||i>ListLength(L))
//        return ERROR;
//    k=MAXSIZE-1;
//    for ( j = 1; j < i; ++j)
//        k=L[k].cur;
//    j=L[k].cur;     /*获取要删除结点的index*/
//    L[k].cur=L[j].cur; /*将上一个结点指向下一个结点*/
//    Free_SSL(L,j);
//    return OK;
//}
//
//Status ListTraverse(StaticLinkList L){
//    int i=L[MAXSIZE-1].cur;
//    while(i){
//        visit(L[i].data);
//        i=L[i].cur;
//    }
//    printf("\n");
//    return OK;
//}
//
//int main() {
//    StaticLinkList L;
//    Status i;
//    i=InitList(L);
//    printf("初始化L后：L.length=%d\n",ListLength(L));
//
//    i=ListInsert(L,1,'F');
//    i=ListInsert(L,1,'E');
//    i=ListInsert(L,1,'D');
//    i=ListInsert(L,1,'B');
//    i=ListInsert(L,1,'A');
//
//    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
//    ListTraverse(L);
//
//    i=ListInsert(L,3,'C');
//    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
//    ListTraverse(L);
//
//    i=ListDelete(L,2);
//    printf("\n在L的删除“B”后：\nL.data=");
//    ListTraverse(L);
//
//    printf("\n");
//
//    return 0;
//}