////
//// Created by 张俊鹏 on 2017/11/17.
////
//#include <stdio.h>
//#include <malloc.h>
//
//#define TRUE 1
//#define FALSE 0
//#define TElement int
//typedef int Status;
//
//typedef struct BiNode {
//    TElement data;
//    struct BiNode *lchild, *rchild;
//} BiTNode, *BiTree;
//
///* 递归查找二叉排序树T中是否存在key, */
///* 指针f指向T的双亲，其初始调用值为NULL */
///* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
///* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
//Status SearchBST(BiTree T, TElement key, BiTree f, BiTree *p) {
//    if (!T) {   /*如果结点不存在，保存父节点，返回false*/
//        *p = f;
//        return FALSE;
//    } else if (key == T->data) {    /*如果存在，保存父节点，返回true*/
//        *p = f;
//        return TRUE;
//    } else if (key <= T->data)  /*如果比当前节点小，递归调用左子树*/
//        return SearchBST(T->lchild, key, T, p);
//    else
//        return SearchBST(T->rchild, key, T, p);
//}
//
///*  当二叉排序树T中不存在关键字等于key的数据元素时， */
///*  插入key并返回TRUE，否则返回FALSE */
//Status InsertBST(BiTree *T, TElement key) {
//    BiTree p, newNode;
//    if (!SearchBST(*T, key, NULL, &p)) {
//        newNode = (BiTree) malloc(sizeof(BiTNode));
//        newNode->data = key;
//        newNode->lchild = newNode->rchild = NULL;
//        if (!p)
//            *T = newNode;
//        else if (key < p->data)
//            p->lchild = newNode;
//        else
//            p->rchild = newNode;
//        return TRUE;
//    } else {
//        printf("插入的元素已存在\n");
//        return FALSE;
//    }
//}
//
//Status DeleteNode(BiTree *node) {
//    BiTree currentNode, precursorNode;
//    if (!(*node)->rchild) {/* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
//        currentNode = *node;
//        *node = (*node)->lchild;
//        free(currentNode);
//    } else if (!(*node)->lchild) {
//        currentNode = *node;
//        *node = (*node)->rchild;
//        free(currentNode);
//    } else {
//        currentNode = *node;
//        precursorNode = (*node)->lchild;
//        while (precursorNode->rchild) {
//            currentNode = precursorNode;
//            precursorNode = precursorNode->rchild;
//        }
//        (*node)->data = precursorNode->data;
//
//        /*如果，currentNode结点和node结点指向的地址一致
//         * 以防出现被删除结点的左子树，没有右子树的情况*/
//        if (currentNode == *node)
//            currentNode->lchild = precursorNode->lchild;
//        else
//            currentNode->rchild = precursorNode->lchild;
//        free(precursorNode);
//    }
//    return TRUE;
//}
//
//Status DeleteBST(BiTree *T, TElement key) {
//    if (!*T) {
//        return FALSE;
//    } else {
//        if (key == (*T)->data)
//            return DeleteNode(T);
//        else if (key < (*T)->data)
//            return DeleteBST(&(*T)->lchild, key);
//        else
//            return DeleteBST(&(*T)->rchild, key);
//    }
//}
//
//int main(void)
//{
//    int i;
//    int a[10]={62,88,58,47,35,73,51,99,37,93};
//    BiTree T=NULL;
//
//    for(i=0;i<10;i++)
//    {
//        InsertBST(&T, a[i]);
//    }
//    DeleteBST(&T,93);
//    DeleteBST(&T,47);
//    printf("本样例建议断点跟踪查看二叉排序树结构");
//    return 0;
//}
//
//
