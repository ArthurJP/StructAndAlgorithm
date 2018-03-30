///*
////
//// Created by �ſ��� on 2017/8/16.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define OK 1
//#define ERROR 0
//
//typedef int Status;
//typedef char TElement;
//typedef enum{
//    Thread,Link
//}PointerType;
//
//typedef struct BiThrNode{
//    TElement data;
//    struct BiThrNode *lchild,*rchild;
//    PointerType LTag,RTag;
//}*BiThrTree,BiThrNode;
//
//Status Visit(TElement e){
//    printf("%c",e);
//    return OK;
//}
//
//TElement Nil='#';
//
//Status CreateTree(BiThrTree *T){
//    TElement h;
//    scanf("%c",&h);
//
//    if (h==Nil){
//        *T=NULL;
//    }else{
//        *T=(BiThrTree)malloc(sizeof(BiThrNode));
//        if (!(*T))
//            exit(OVERFLOW);
//        (*T)->data=h;
//        CreateTree(&(*T)->lchild);
//        if ((*T)->lchild)
//            (*T)->LTag=Link;
//        CreateTree(&(*T)->rchild);
//        if ((*T)->rchild)
//            (*T)->RTag=Link;
//    }
//    return OK;
//}
//
//BiThrTree pre;
//Status InThreading(BiThrTree T){
//    if (T){
//        InThreading(T->lchild);
//        if (!T->lchild) {
//            T->LTag=Thread;
//            T->lchild = pre;
//        }
//        if (!pre->rchild){
//            pre->RTag=Thread;
//            pre->rchild=T;
//        }
//        pre=T;
//        InThreading(T->rchild);
//    }
//    return OK;
//}
//
//Status InOrderThreading(BiThrTree *Thead,BiThrTree T){
//    *Thead=(BiThrTree)malloc(sizeof(BiThrNode));
//    if (!(*Thead))
//        exit(OVERFLOW);
//    (*Thead)->LTag=Thread;
//    (*Thead)->RTag=Thread;
//    (*Thead)->rchild=(*Thead);
//
//    if(!T){
//        (*Thead)->lchild=*Thead;
//    } else{
//        (*Thead)->lchild=T;
//        pre=(*Thead);
//        InThreading(T);
//        pre->RTag=Thread;
//        pre->rchild=*Thead;
//        (*Thead)->rchild=pre;
//    }
//    return OK;
//}
//
//Status InTraverse(BiThrTree T){
//    BiThrTree p=T->lchild;
//    while(p!=T){
//        while(p->LTag==Link)
//            p=p->lchild;
//        if (!Visit(p->data))
//            exit(OVERFLOW);
//        while(p->RTag==Thread&&p->rchild!=T){
//            p=p->rchild;
//            Visit(p->data);
//        }
//        p=p->rchild;
//    }
//    return OK;
//}
//
//Status InReverse(BiThrTree T){
//    BiThrTree p=T->rchild;
//    while(p!=T){
//        while(p->RTag==Link)
//            p=p->rchild;
//        if (!Visit(p->data))
//            exit(OVERFLOW);
//        while(p->LTag==Thread&&p->lchild!=T){
//            p=p->lchild;
//            Visit(p->data);
//        }
//        p=p->lchild;
//    }
//    return OK;
//}
//
//void main(){
//    BiThrTree H,T;
//    printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
//    CreateTree(&T); */
///* ��ǰ����������� *//*
//
//    InOrderThreading(&H,T); */
///* �������,������������������ *//*
//
//    printf("�������(���)����������:\n");
//    InTraverse(H); */
///* �������(���)���������� *//*
//
//    printf("\n");
//    InReverse(H);
//}*/
