////
//// Created by 张俊鹏 on 2017/8/19.
////
//#include <stdio.h>
//#include <malloc.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXVEX 100 /* 最大顶点数,应由用户定义 */
//
//typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
//typedef char VertexType; /* 顶点类型应由用户定义 */
//typedef int EdgeType; /* 边上的权值类型应由用户定义 */
//
///*邻接表结构*/
//typedef struct EdgeNode{    /*边表结点*/
//    int adjacencyVertex;    /*邻接点域，存储该节点对应的下标*/
//    EdgeType weight;      /* 用于存储权值,对于非网图可以不需要 */
//    struct EdgeNode *next;      /*链域，指向下一个邻接点*/
//}EdgeNode;
//
//typedef struct VertexNode{      /* 顶点表结点 */
//    VertexType data;        /*顶点域，存储顶点信息*/
//    EdgeNode *firstEdge;        /*边表头指针*/
//}VertexNode,AdjacencyList[MAXVEX];
//
//typedef struct {
//    AdjacencyList adjacencyList;
//    int numNodes,numEdges;      /*图中当前节点数和边数*/
//}GraphAdjacencyList;
//
///*建立图的邻接表结构*/
//void CreateALGraph(GraphAdjacencyList *G){
//    int a,b;
//    EdgeNode *e;
//    printf("请输入顶点数和边数：\n");
//    scanf("%d %d",&G->numNodes,&G->numEdges);
//    printf("请输入顶点信息：");
//    for (int i = 0; i < G->numNodes; ++i) {
//        scanf(" %c",&G->adjacencyList[i].data);        /*输入顶点信息*/
//        G->adjacencyList[i].firstEdge=NULL;       /*将边表置为空*/
//    }
//    printf("输入边(vi,vj)上的顶点序号:\n");
//    for (int j = 0; j < G->numEdges; ++j) {
//        scanf("%d,%d",&a,&b); /* 输入边(vi,vj)上的顶点序号 */
//        e=(EdgeNode *)malloc(sizeof(EdgeNode));  /* 向内存申请空间,生成边表结点 */
//        /*此处使用头插法*/
//        e->adjacencyVertex=b;   /* 邻接序号为j */
//        e->next=G->adjacencyList[a].firstEdge;  /* 将e的指针指向当前顶点上指向的结点 */
//        G->adjacencyList[a].firstEdge=e;    /* 将当前顶点的指针指向e */
//
//        e=(EdgeNode *)malloc(sizeof(EdgeNode));
//        e->adjacencyVertex=a;
//        e->next=G->adjacencyList[b].firstEdge;
//        G->adjacencyList[b].firstEdge=e;
//    }
//}
//
//int main(void)
//{
//    GraphAdjacencyList G;
//    CreateALGraph(&G);
//
//    return 0;
//}
//
