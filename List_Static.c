////
//// Created by �ſ��� on 2017/7/1.
////
//
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//
//#define MAXSIZE 8//�Է��������
//
//typedef int ElemType; //�����������ͣ������Ժ��޸�
//typedef char Status;
//
//Status visit(ElemType c){
//    printf("%c ",c);
//    return OK;
//}
//
//typedef struct{
//    ElemType data;
//    int cur;//�α꣨Cursor����Ϊ0ʱ��ʾ��ָ��
//}StaticLinkList[MAXSIZE];
//
///* ��һά����space�и���������һ����������space[0].curΪͷָ�룬"0"��ʾ��ָ�� */
//Status InitList(StaticLinkList space){
//    for (int i = 0; i < MAXSIZE - 1; ++i)
//        space[i].cur=i+1;
//    space[MAXSIZE-1].cur=0;
//    return OK;
//}
//
///*
// * ��ÿ��з������±�
// */
///* �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0 */
//int Malloc_SSL(StaticLinkList space){
//    int i=space[0].cur;/* ��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صĵ�һ�����ÿ��е��±� */
//    if (space[0].cur)//����ó���һ������ʹ���ˣ�����������ָ��������һ������
//        space[0].cur=space[i].cur;
//    return i;
//}
//
//void Free_SSL(StaticLinkList space,int k){
//    space[k].cur=space[0].cur;//����һ��Ԫ�ص�cur��ֵ��Ҫɾ���ķ���cur������Ҫɾ���ķ���curָ���ÿռ�ĵ�һ��
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
// * �����i��Ԫ��
// */
//Status ListInsert(StaticLinkList L,int i,ElemType e){
//    int j,k,l;
//    k=MAXSIZE-1;  //k������һ��Ԫ�ص��±�
//    if(i<1||i>ListLength(L)+1)/*����ֵ�쳣���߲����Ӷ���*/
//        return ERROR;
//    j=Malloc_SSL(L);//��ÿ��з������±�
//    if(j){
//        L[j].data=e;//�����ݸ�ֵ���˷�����data
//        for ( l = 1; l < i ; ++l)//�ҵ���i��Ԫ��֮ǰ��λ��
//            k=L[k].cur;
//        L[j].cur=L[k].cur;//����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur
//        L[k].cur=j;//����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur
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
//    j=L[k].cur;     /*��ȡҪɾ������index*/
//    L[k].cur=L[j].cur; /*����һ�����ָ����һ�����*/
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
//    printf("��ʼ��L��L.length=%d\n",ListLength(L));
//
//    i=ListInsert(L,1,'F');
//    i=ListInsert(L,1,'E');
//    i=ListInsert(L,1,'D');
//    i=ListInsert(L,1,'B');
//    i=ListInsert(L,1,'A');
//
//    printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
//    ListTraverse(L);
//
//    i=ListInsert(L,3,'C');
//    printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
//    ListTraverse(L);
//
//    i=ListDelete(L,2);
//    printf("\n��L��ɾ����B����\nL.data=");
//    ListTraverse(L);
//
//    printf("\n");
//
//    return 0;
//}