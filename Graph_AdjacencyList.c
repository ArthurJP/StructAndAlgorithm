////
//// Created by �ſ��� on 2017/8/19.
////
//#include <stdio.h>
//#include <malloc.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */
//
//typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
//typedef char VertexType; /* ��������Ӧ���û����� */
//typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
//
///*�ڽӱ�ṹ*/
//typedef struct EdgeNode{    /*�߱���*/
//    int adjacencyVertex;    /*�ڽӵ��򣬴洢�ýڵ��Ӧ���±�*/
//    EdgeType weight;      /* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
//    struct EdgeNode *next;      /*����ָ����һ���ڽӵ�*/
//}EdgeNode;
//
//typedef struct VertexNode{      /* ������� */
//    VertexType data;        /*�����򣬴洢������Ϣ*/
//    EdgeNode *firstEdge;        /*�߱�ͷָ��*/
//}VertexNode,AdjacencyList[MAXVEX];
//
//typedef struct {
//    AdjacencyList adjacencyList;
//    int numNodes,numEdges;      /*ͼ�е�ǰ�ڵ����ͱ���*/
//}GraphAdjacencyList;
//
///*����ͼ���ڽӱ�ṹ*/
//void CreateALGraph(GraphAdjacencyList *G){
//    int a,b;
//    EdgeNode *e;
//    printf("�����붥�����ͱ�����\n");
//    scanf("%d %d",&G->numNodes,&G->numEdges);
//    printf("�����붥����Ϣ��");
//    for (int i = 0; i < G->numNodes; ++i) {
//        scanf(" %c",&G->adjacencyList[i].data);        /*���붥����Ϣ*/
//        G->adjacencyList[i].firstEdge=NULL;       /*���߱���Ϊ��*/
//    }
//    printf("�����(vi,vj)�ϵĶ������:\n");
//    for (int j = 0; j < G->numEdges; ++j) {
//        scanf("%d,%d",&a,&b); /* �����(vi,vj)�ϵĶ������ */
//        e=(EdgeNode *)malloc(sizeof(EdgeNode));  /* ���ڴ�����ռ�,���ɱ߱��� */
//        /*�˴�ʹ��ͷ�巨*/
//        e->adjacencyVertex=b;   /* �ڽ����Ϊj */
//        e->next=G->adjacencyList[a].firstEdge;  /* ��e��ָ��ָ��ǰ������ָ��Ľ�� */
//        G->adjacencyList[a].firstEdge=e;    /* ����ǰ�����ָ��ָ��e */
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
