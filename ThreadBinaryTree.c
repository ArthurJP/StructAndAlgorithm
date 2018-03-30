////
//// Created by �ſ��� on 2017/8/14.
////
//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;    /* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
//typedef char TElemType;
//typedef enum {
//    Link, Thread
//} PointerTag;    /* Link==0��ʾָ�����Һ���ָ��, */
///* Thread==1��ʾָ��ǰ�����̵����� */
//
//typedef struct BiThrNode {
//    TElemType data;     /*��������*/
//    struct BiThrNode *leftChild, *rightChild;    /*���ҽ��*/
//    PointerTag LTag, RTag;   /*���ұ�־������ָ��ָ��ָ��ָ�뻹������*/
//} BiThrNode, *BiThrTree;
//
//TElemType Nil = '#';
//
//Status visit(TElemType e) {
//    printf("%c", e);
//    return OK;
//}
//
///* ��ǰ����������������н���ֵ,�������������T */
///* 0(����)/�ո�(�ַ���)��ʾ�ս�� */
//Status CreateBiThrTree(BiThrTree *T) {
//    TElemType h;
//    scanf("%c", &h);
//
//    if (h == Nil)
//        *T = NULL;
//    else {
//        *T = (BiThrTree) malloc(sizeof(BiThrNode));
//        if (!*T)    /*����ڴ������ʧ��*/
//            exit(OVERFLOW);
//        (*T)->data = h;   /*���ɸ��ڵ�*/
//        CreateBiThrTree(&(*T)->leftChild);    /*�ݹ鴴�����ӣ������ӵĵ�ַ�ݹ����*/
//        /*������ɺ��ж���ָ�뻹������*/
//        if ((*T)->leftChild)
//            (*T)->LTag = Link;
//        /*ͬ�����Һ���*/
//        CreateBiThrTree(&(*T)->rightChild);
//        if ((*T)->rightChild)
//            (*T)->RTag = Link;
//    }
//    return OK;
//}
//
//BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
///* ��������������������� */
///*˼·������������Խ�Ҷ�ӽ�㾡���ܶ�ı�¶��������ʹ����������������
//    �����Ϊ�յ�ʱ�򣬷�����һ�εݹ飬�ҵ�Ҷ�ӽ��*/
///*���裺
//    ��������ΪҶ�ӽ���ʱ�򣬽�����������������Ϊǰ����㣨�˴���Ҫһ��ȫ�ֱ�������ǰ��������Ϣ��
//    ���ţ��ж�ǰ������Ƿ��������������������ڣ���ǰ�����ĺ������Ϊ��ǰ��Ҷ�ӽڵ�
//    ��󣬽���ǰ�������Ϊǰ����㣨ǰ�������һ��ʼ������������ǰ��Ҫָ���� */
//void InThreading(BiThrTree p) {
//    if (p) {
//        InThreading(p->leftChild);      /*�ҵ�����ߵ�Ҷ�ӽڵ�*/
//        if (!p->leftChild) {     /*��ǰ���û������*/
//            p->LTag = Thread;    /* ��ǰ�ڵ�ǰ������ */
//            p->leftChild = pre;
//        }
//        if (!pre->rightChild) {    /*ǰ��û���Һ��ӣ�ע������ʹ�õ�ǰ����ǰһ��������ú�� */
//            pre->RTag = Thread;     /* ǰ���ĺ������ */
//            pre->rightChild = p;    /* ǰ���Һ���ָ��ָ����(��ǰ���p) */
//        }
//        pre = p;  /*����preָ��p��ǰ��*/
//        InThreading(p->rightChild);     /* �ݹ������������� */
//    }
//}
//
///* �������������T,����������������,Theadָ��ͷ��� */
///*Ϊ�˱�֤���н���һ���ԣ����ǲ���˫���������ͷ��㣬�������һ��headͷ�����ڱ�֤������һ����*/
//Status InOrderThreading(BiThrTree *Thead,BiThrTree T){
//    *Thead= (BiThrTree )malloc(sizeof(BiThrNode));
//    if(!*Thead)
//        exit(OVERFLOW);
//    (*Thead)->LTag=Link;         /* ��ͷ��� */
//    (*Thead)->RTag=Thread;
//    (*Thead)->rightChild=(*Thead);      /* ��ָ���ָ */
//    if (!T)     /* ����������,����ָ���ָ */
//        (*Thead)->leftChild=(*Thead);
//    else{
//        (*Thead)->leftChild=T;
//        pre=(*Thead);
//        InThreading(T);
//        pre->RTag=Thread;       /* ���һ����������� */
//        pre->rightChild=(*Thead);
//        (*Thead)->rightChild=pre;       /*��ͷ����������ָ�����һ����㣬�����γ�һ��˫������*/
//    }
//    return OK;
//}
//
///* �����������������T(ͷ���)�ķǵݹ��㷨 */
//Status InOrderTraverse_Thr(BiThrTree T){
//    BiThrTree p=T->leftChild;   /*pָ����ڵ�*/
//    while(p!=T){    /*�������߱���������ʱ��p==T*/
//        while(p->LTag==Link)    /*�ҵ���һ����ʼ�Ľ��*/
//            p=p->leftChild;
//        if(!visit(p->data))    /*�������*/
//            return ERROR;        /*�����ǰ���Ϊ�գ������쳣*/
//        while(p->RTag==Thread&&p->rightChild!=T){   /*ѭ������������м���*/
//            p=p->rightChild;
//            visit(p->data);
//        }
//        p=p->rightChild;        /*��ָ��ָ���ҽڵ�*/
//    }
//    return OK;
//}
//
///*�����������*/
//Status InReverse(BiThrTree T){
//    BiThrTree p=T->rightChild;
//    while(p!=T){
//        while(p->RTag==Link)
//            p=p->rightChild;
//        if (!visit(p->data))
//            exit(OVERFLOW);
//        while(p->LTag==Thread&&p->leftChild!=T){
//            p=p->leftChild;
//            visit(p->data);
//        }
//        p=p->leftChild;
//    }
//    return OK;
//}
//
//void main() {
//    BiThrTree H,T;
//    printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
//    CreateBiThrTree(&T); /* ��ǰ����������� */
//    InOrderThreading(&H,T); /* �������,������������������ */
//    printf("�������(���)����������:\n");
//    InOrderTraverse_Thr(H); /* �������(���)���������� */
//    printf("\n");
//    InReverse(H);
//}
