////
//// Created by 张俊鹏 on 2017/8/26.
////
//
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;     /*函数的返回值类型*/
//typedef char VertexType;    /*定点类型*/
//typedef int EdgeType;       /*边上的权值类型*/
//typedef int Boolean;      /*图结点访问标记，值为TRUE或者FAlSE*/
//
//#define MAXSIZE 9   /*队列最大长度*/
//#define MAXEDGE 15   /*最大边数*/
//#define MAXVEX 9    /*最大节点数*/
//#define INFINITY 65535  /*定义不相连边的值*/
//
///*邻接表结构*/
//typedef struct{
//    VertexType vertex[MAXVEX];  /*顶点表*/
//    EdgeType arc[MAXVEX][MAXVEX];   /*邻接矩阵，用来记录边之间的信息*/
//    int numVertexes,numEdges;   /*图中当前的顶点数和边数*/
//}MGraph;
//
///*循环队列的顺序存储结构*/
//typedef struct{
//    int data[MAXSIZE];
//    int front;      /*头指针*/
//    int rear;       /*尾指针，指向下一个该插入的位置*/
//}Queue;
//
///*初始化一个空队列Q*/
//Status InitQueue(Queue *Q){
//    Q->front=0;
//    Q->rear=0;
//    return OK;
//}
//
///*判断队列是否为空*/
//Status QueuqEmpty(Queue Q){
//    return Q.front==Q.rear;
//}
//
///*入队列*/
//Status EnQueue(Queue *Q,int e){
//    if((Q->rear+1)%MAXSIZE==Q->front)
//        return ERROR;
//    Q->data[Q->rear]=e;
//    Q->rear=(Q->rear+1)%MAXSIZE;    /*尾指针后移，取余使结尾指针可以返回0下标*/
//    return OK;
//}
//
///*出队列*/
//Status DeQueue(Queue *Q,int *e){
//    if(Q->front==Q->rear)
//        return ERROR;
//    *e=Q->data[Q->front];           /*取出头结点数据*/
//    Q->front=(Q->front+1)%MAXSIZE;  /*头指针后移*/
//    return OK;
//}
//
//void CreateMGraph(MGraph *G)
//{
//    int i, j;
//
//    G->numEdges=15;
//    G->numVertexes=9;
//
//    /* 读入顶点信息，建立顶点表 */
//    G->vertex[0]='A';
//    G->vertex[1]='B';
//    G->vertex[2]='C';
//    G->vertex[3]='D';
//    G->vertex[4]='E';
//    G->vertex[5]='F';
//    G->vertex[6]='G';
//    G->vertex[7]='H';
//    G->vertex[8]='I';
//
//    for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//    {
//        for ( j = 0; j < G->numVertexes; j++)
//        {
//            G->arc[i][j]=0;
//        }
//    }
//
//    G->arc[0][1]=1;
//    G->arc[0][5]=1;
//
//    G->arc[1][2]=1;
//    G->arc[1][8]=1;
//    G->arc[1][6]=1;
//
//    G->arc[2][3]=1;
//    G->arc[2][8]=1;
//
//    G->arc[3][4]=1;
//    G->arc[3][7]=1;
//    G->arc[3][6]=1;
//    G->arc[3][8]=1;
//
//    G->arc[4][5]=1;
//    G->arc[4][7]=1;
//
//    G->arc[5][6]=1;
//
//    G->arc[6][7]=1;
//
//    for(i = 0; i < G->numVertexes; i++)
//    {
//        for(j = i; j < G->numVertexes; j++)
//        {
//            G->arc[j][i] =G->arc[i][j];
//        }
//    }
//}
//
//Boolean visited[MAXVEX]; /* 记录顶点是否被访问 */
//
///*初始化遍历的情况*/
//void InitRoad(MGraph G){
//    for (int i = 0; i < G.numVertexes; ++i)
//        visited[i]=FALSE;   /*将所有顶点都是设置为未访问*/
//    for (int i = 0; i < G.numVertexes; ++i)
//        if (!visited[i])    /*对未访问过的顶点调用深度遍历算法，若是连通图则只调用一次*/
//            DFSTraverse(G,i);   /*开始深度优先遍历*/
//}
//
///* 邻接矩阵的深度优先递归算法 */
//void DFSTraverse(MGraph G, int i)
//{
//    int j;
//    visited[i] = TRUE;
//    printf("%c ", G.vertex[i]);/* 打印顶点，也可以其它操作 */
//    for(j = 0; j < G.numVertexes; j++)
//        if(G.arc[i][j] == 1 && !visited[j]) /*如果两顶点有通路，且未被访问过*/
//            DFSTraverse(G, j);/* 对为访问的邻接顶点递归调用 */
//}
//
//
//
//
//
//
//
//
//
//
