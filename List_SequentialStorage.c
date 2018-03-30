//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 20 /*�洢�ռ��ʼ������*/
//
//typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int ElemType;  /* ElemType���͸���ʵ������������������Ϊint */
//
//Status visit(ElemType c)
//{
//    printf("%d ",c);
//    return OK;
//}
//
//typedef struct{
//    ElemType data[MAXSIZE]; //����洢����Ԫ�أ����ֵΪMAXSIZE��0~MAXSIZE-1��
//    int length; //���Ա�ǰ����
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
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
//Status ClearList(SqList *L) {
//    L->length=0;
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//int ListLength(SqList L) {
//    return L.length;
//}
//
///*
// * ˼·���ж��Ƿ�Խ�磬��������Ա���ȡ������
// * �˺���ֻ��Ϊ��ȡ�����Ա��е�һ�����ݣ�����ʹ��SqList L�����ַ�ʽֻ����L.data��ȡֵ�������ܸı�ԭʼ���ݵ�ֵ
// */
//Status GetElem(SqList L,int i,ElemType *e){
//    if (L.length==0||i<1||i>L.length)
//        return ERROR;
//    *e=L.data[i-1];
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
///* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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
// * ��ӽڵ�˼·��
// * 1���ж��Ƿ����Ա�����
// * 2���ж�ʱ���ڶ����У��������м��һ��λ��������
// * 3������Ҫ����λ�ú����������Ԫ�غ���һλ
// * 4������
// * 5��������+1
// * ���ɣ�Ϊ�˲���SqList��һ���ض�����ֵ������ʹ��ָ��SqList *L����ʱʹ��L->data�����޸����е�����
// */
//Status ListInsert(SqList *L, int i, ElemType e){
//    if (L->length>MAXSIZE){
//        printf("˳�����Ա�����");
//        return ERROR;
//    }
//    if (i<1||i>L->length+1){//����length+1���п��ܻ��ڿ��Դ洢�����򣬵����Ѿ��Ͷ��в�����
//        printf("���ڶ�����\n");
//        return ERROR;
//    }
//    if (i<=L->length){//�������λ�ò��ڱ�β
//        for (int j = L->length-1; j >= i-1 ; --j) //������λ���Ժ������Ԫ�������һλ
//            L->data[j+1]=L->data[j];
//    }
//    L->data[i-1]=e;//����Ԫ�ز���
//    L->length++;
//
//    return OK;
//}
//
///*
// * ɾ���ڵ�˼·��
// * 1�����ɾ��λ�ò������׳��쳣
// * 2��ɾ��Ԫ��
// * 3����ɾ��Ԫ��λ���Ժ������Ԫ����ǰ�ƶ�һλ
// * 4������-1
// */
//Status ListDelete(SqList *L,int i,ElemType *e){
//    if (L->length==0)//���Ա�Ϊ��
//        return ERROR;
//    if (i<1||i>L->length)//ɾ��λ�ò���ȷ
//        return ERROR;
//    *e=L->data[i-1];
//    if(i<L->length){//���ɾ����λ�ò������һλ
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
//    printf("��ʼ��L��L.length=%d\n",L.length);
//    for(j=1;j<=5;j++)
//        i=ListInsert(&L,1,j);
//    printf("��L�ı�ͷ���β���1��5��L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n",L.length);
//    i=ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
//
//    i=ClearList(&L);
//    printf("���L��L.length=%d\n",L.length);
//    i=ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
//
//    for(j=1;j<=10;j++)
//        ListInsert(&L,j,j);
//    printf("��L�ı�β���β���1��10��L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n",L.length);
//
//    ListInsert(&L,1,0);
//    printf("��L�ı�ͷ����0��L.data=");
//    ListTraverse(L);
//    printf("L.length=%d \n",L.length);
//
//    GetElem(L,5,&e);
//    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
//    for(j=3;j<=4;j++)
//    {
//        k=LocateElem(L,j);
//        if(k)
//            printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
//        else
//            printf("û��ֵΪ%d��Ԫ��\n",j);
//    }
//
//
//    k=ListLength(L); /* kΪ�� */
//    for(j=k+1;j>=k;j--)
//    {
//        i=ListDelete(&L,j,&e); /* ɾ����j������ */
//        if(i==ERROR)
//            printf("ɾ����%d������ʧ��\n",j);
//        else
//            printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
//    }
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    j=5;
//    ListDelete(&L,j,&e); /* ɾ����5������ */
//    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
//
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    //����һ����10������Lb
//    SqList Lb;
//    i=InitList(&Lb);
//    for(j=6;j<=15;j++)
//        i=ListInsert(&Lb,1,j);
//    ListTraverse(Lb);
//
//    unionL(&L,Lb);
//
//    printf("��������ϲ���Lb��L��Ԫ�أ�");
//    ListTraverse(L);
//
//    return 0;
//}
