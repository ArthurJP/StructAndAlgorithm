////
//// Created by �ſ��� on 2017/7/22.
////
//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//
//#define TElement char
//
//typedef struct BinaryTNode{
//    TElement data;
//    struct BinaryTNode *lchild,*rchild;
//}BinaryTNode,*BinaryTree;
//
////void PreOrderTraverse(BinaryTree T){
////    if(T==NULL)
////        return ;
////    printf("%c",T->data);
////    PreOrderTraverse(T->lchild);
////    PreOrderTraverse(T->rchild);
////}
//
//void visit(int data, int level);
//
////����ǰ�������˳�����룬Ҷ�ӽڵ���#��ʾ
//void CreateBinaryTree(BinaryTree *T){
//    TElement ch;
//    scanf("%c",&ch);
//    if ('#'==ch)
//        *T=NULL;
//    else{
//        *T=(BinaryTree)malloc(sizeof(BinaryTNode));
//        if (!*T)
//            exit(OVERFLOW);
//        (*T)->data=ch;
//        CreateBinaryTree(&(*T)->lchild);
//        CreateBinaryTree(&(*T)->rchild);
//    }
//}
//
//void PreOrderTraverse(BinaryTree T,int level){
//    if (T){
//        visit(T->data,level);
//        PreOrderTraverse(T->lchild,level+1);
//        PreOrderTraverse(T->rchild,level+1);
//    }
//}
//
//void visit(int data, int level) {
//    printf("%c �ڵ�%d��\n",data,level);
//}
//
//void main(){
//    int level=0;
//    BinaryTree T=NULL;
//
//    CreateBinaryTree(&T);
//    PreOrderTraverse(T,level);
//}
