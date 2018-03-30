////
//// Created by 张俊鹏 on 2017/8/14.
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
//typedef int Status;    /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
//typedef char TElemType;
//typedef enum {
//    Link, Thread
//} PointerTag;    /* Link==0表示指向左右孩子指针, */
///* Thread==1表示指向前驱或后继的线索 */
//
//typedef struct BiThrNode {
//    TElemType data;     /*数据内容*/
//    struct BiThrNode *leftChild, *rightChild;    /*左右结点*/
//    PointerTag LTag, RTag;   /*左右标志，用于指定指针指向指针还是线索*/
//} BiThrNode, *BiThrTree;
//
//TElemType Nil = '#';
//
//Status visit(TElemType e) {
//    printf("%c", e);
//    return OK;
//}
//
///* 按前序输入二叉线索树中结点的值,构造二叉线索树T */
///* 0(整型)/空格(字符型)表示空结点 */
//Status CreateBiThrTree(BiThrTree *T) {
//    TElemType h;
//    scanf("%c", &h);
//
//    if (h == Nil)
//        *T = NULL;
//    else {
//        *T = (BiThrTree) malloc(sizeof(BiThrNode));
//        if (!*T)    /*如果内存溢出，失败*/
//            exit(OVERFLOW);
//        (*T)->data = h;   /*生成根节点*/
//        CreateBiThrTree(&(*T)->leftChild);    /*递归创建左孩子，将左孩子的地址递归调用*/
//        /*创建完成后判断是指针还是索引*/
//        if ((*T)->leftChild)
//            (*T)->LTag = Link;
//        /*同理创建右孩子*/
//        CreateBiThrTree(&(*T)->rightChild);
//        if ((*T)->rightChild)
//            (*T)->RTag = Link;
//    }
//    return OK;
//}
//
//BiThrTree pre; /* 全局变量,始终指向刚刚访问过的结点 */
///* 中序遍历进行中序线索化 */
///*思路：中序遍历可以将叶子结点尽可能多的暴露出来，故使用中序遍历添加线索
//    当结点为空的时候，返回上一次递归，找到叶子结点*/
///*步骤：
//    当左子树为叶子结点的时候，将左子树的左孩子设置为前驱结点（此处需要一个全局变量保存前驱结点的信息）
//    接着，判断前驱结点是否存在右子树，如果不存在，则将前驱结点的后继设置为当前的叶子节点
//    最后，将当前结点设置为前驱结点（前驱结点在一开始进入索引函数前需要指定） */
//void InThreading(BiThrTree p) {
//    if (p) {
//        InThreading(p->leftChild);      /*找到最左边的叶子节点*/
//        if (!p->leftChild) {     /*当前结点没有左孩子*/
//            p->LTag = Thread;    /* 当前节点前驱线索 */
//            p->leftChild = pre;
//        }
//        if (!pre->rightChild) {    /*前驱没有右孩子，注意这里使用当前结点的前一个结点设置后继 */
//            pre->RTag = Thread;     /* 前驱的后继线索 */
//            pre->rightChild = p;    /* 前驱右孩子指针指向后继(当前结点p) */
//        }
//        pre = p;  /*保持pre指向p的前驱*/
//        InThreading(p->rightChild);     /* 递归右子树线索化 */
//    }
//}
//
///* 中序遍历二叉树T,并将其中序线索化,Thead指向头结点 */
///*为了保证所有结点的一致性，我们参照双向链表添加头结点，即多出来一个head头，用于保证操作的一致性*/
//Status InOrderThreading(BiThrTree *Thead,BiThrTree T){
//    *Thead= (BiThrTree )malloc(sizeof(BiThrNode));
//    if(!*Thead)
//        exit(OVERFLOW);
//    (*Thead)->LTag=Link;         /* 建头结点 */
//    (*Thead)->RTag=Thread;
//    (*Thead)->rightChild=(*Thead);      /* 右指针回指 */
//    if (!T)     /* 若二叉树空,则左指针回指 */
//        (*Thead)->leftChild=(*Thead);
//    else{
//        (*Thead)->leftChild=T;
//        pre=(*Thead);
//        InThreading(T);
//        pre->RTag=Thread;       /* 最后一个结点线索化 */
//        pre->rightChild=(*Thead);
//        (*Thead)->rightChild=pre;       /*将头结点的右子树指向最后一个结点，最终形成一个双向链表*/
//    }
//    return OK;
//}
//
///* 中序遍历二叉线索树T(头结点)的非递归算法 */
//Status InOrderTraverse_Thr(BiThrTree T){
//    BiThrTree p=T->leftChild;   /*p指向根节点*/
//    while(p!=T){    /*空树或者遍历结束的时候，p==T*/
//        while(p->LTag==Link)    /*找到第一个开始的结点*/
//            p=p->leftChild;
//        if(!visit(p->data))    /*输出左结点*/
//            return ERROR;        /*如果当前结点为空，发生异常*/
//        while(p->RTag==Thread&&p->rightChild!=T){   /*循环遍历，输出中间结点*/
//            p=p->rightChild;
//            visit(p->data);
//        }
//        p=p->rightChild;        /*将指针指向右节点*/
//    }
//    return OK;
//}
//
///*逆序中序输出*/
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
//    printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
//    CreateBiThrTree(&T); /* 按前序产生二叉树 */
//    InOrderThreading(&H,T); /* 中序遍历,并中序线索化二叉树 */
//    printf("中序遍历(输出)二叉线索树:\n");
//    InOrderTraverse_Thr(H); /* 中序遍历(输出)二叉线索树 */
//    printf("\n");
//    InReverse(H);
//}
