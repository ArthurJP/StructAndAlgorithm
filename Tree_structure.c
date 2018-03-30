////
//// Created by 张俊鹏 on 2017/7/20.
////
//#define MAX_TREE_SIZE 100
//typedef int TElemType;
//
///*双亲表示法*/
//typedef struct PTNode{  /*结点结构*/
//    TElemType data; /*结点数据*/
//    int parent; /*双亲位置*/
//}PTNode;
//
//typedef struct{ /*树结构*/
//    PTNode nodes[MAX_TREE_SIZE];    /*结点数组*/
//    int r,n;    /*根的位置和节点数*/
//}PTree;
//
///*孩子表示法*/
//typedef struct CTNode{  /*孩子结点*/
//    int child;  /*孩子结点的下标*/
//    struct CTNode *next;    /*指向下一个孩子结点的指针*/
//}*ChildPtr;
//
//typedef struct{     /*表头结构*/
//    TElemType data;     /*存放在树中的结点数据*/
//    int parent;     /*存放双亲结点*/
//    ChildPtr firstChild;    /*指向第一个孩子的指针*/
//}CTBox;
//
//typedef struct{ /*树结构*/
//    CTBox nodes[MAX_TREE_SIZE];     /*结点数组*/
//    int r,n;    /*根节点位置和结点数*/
//}CTree;
//
///*孩子兄弟表示法*/
//typedef struct CSNode{
//    TElemType data;
//    struct CSNode *firstChild,rightSib;
//}CSNode,*CSTrss;
