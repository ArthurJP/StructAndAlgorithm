////
//// Created by 张俊鹏 on 2017/8/19.
////
//
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
//#define INFINITY 65535
//
//typedef int Status;
//typedef char VertexType;    /*定点类型*/
//typedef int EdgeType;       /*边上的权值类型*/
//
//typedef struct {
//    VertexType vertex[MAXVEX];      /*顶点表*/
//    EdgeType arc[MAXVEX][MAXVEX];       /*邻接矩阵*/
//    int numNodes, numEdges;      /*节点数，边数*/
//} MGraph;
//
//void CreateMGraph(MGraph *G) {
//    int i, j , w;
//    printf("输入顶点数和边数:\n");
//    scanf("%d %d", &G->numNodes, &G->numEdges); /* 输入顶点数和边数 */
//    for (i = 0; i < G->numNodes; ++i) {   /* 读入顶点信息,建立顶点表 */
//        printf("请输入顶点的信息：");
//        scanf(" %c",&G->vertex[i]);
//    }
//    for (i = 0; i < G->numNodes; ++i)
//        for (j = 0; j < G->numNodes; ++j)
//            G->arc[i][j] = INFINITY;      /* 邻接矩阵初始化 */
//    for (int k = 0; k < G->numEdges; ++k) {     /* 读入numEdges条边，建立邻接矩阵 */
//        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
//        scanf(" %d %d %d", &i, &j,&w);       /* 输入边(vi,vj)上的权w */
//        G->arc[i][j]=w;
//        G->arc[j][i]=G->arc[i][j];      /* 因为是无向图，矩阵对称 */
//    }
//}
//
//int main(void)
//{
//    MGraph G;
//    CreateMGraph(&G);
//
//    return 0;
//}