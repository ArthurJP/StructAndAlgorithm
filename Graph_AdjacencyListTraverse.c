//
// Created by 张俊鹏 on 2017/8/29.
//

#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数,应由用户定义 */

#define MAXSIZE 9   /*队列最大长度*/
#define MAXEDGE 15   /*最大边数*/
#define MAXVEX 9    /*最大节点数*/
#define INFINITY 65535  /*定义不相连边的值*/

typedef int Status;     /*函数的返回值类型*/
typedef char VertexType;    /*定点类型*/
typedef int EdgeType;       /*边上的权值类型*/
typedef int Boolean;      /*图结点访问标记，值为TRUE或者FAlSE*/

/* 邻接矩阵结构，用于创建邻接链表 */
typedef struct
{
    VertexType vexs[MAXVEX]; /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵,可看作边表 */
    int numVertexes, numEdges; /* 图中当前的顶点数和边数 */
}MGraph;

/*边表*/
typedef struct EdgeNode{
    int adjacencyVertex;    /*临界点域，存储该节点对应的下标*/
    EdgeType weight;        /*权重信息*/
    struct EdgeNode *next;      /*链域，指向下一个邻接点*/
}EdgeNode;

/*定点顶点表*/
typedef struct VertexNode{
    int in;     /*顶点入度*/
    VertexType data;        /*顶点域，存储顶点信息*/
    EdgeNode *firstEdge;        /*边表头指针*/
}VertexNode,AdjacencyList[MAXVEX];

typedef struct {
    AdjacencyList adjacencyList;
    int numVertexes,numEdges;
}graphAdjacencyList,*GraphAdjacencyList;

/* 用到的队列结构与函数********************************** */
/* 循环队列的顺序存储结构 */
typedef struct
{
    int data[MAXSIZE];
    int front;    	/* 头指针 */
    int rear;		/* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
}Queue;

/* 初始化一个空队列Q */
Status InitQueue(Queue *Q)
{
    Q->front=0;
    Q->rear=0;
    return  OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{
    if(Q.front==Q.rear) /* 队列空的标志 */
        return TRUE;
    else
        return FALSE;
}

/* 若队列未满,则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue *Q,int e)
{
    if ((Q->rear+1)%MAXSIZE == Q->front)	/* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear]=e;			/* 将元素e赋值给队尾 */
    Q->rear=(Q->rear+1)%MAXSIZE;/* rear指针向后移一位置, */
    /* 若到最后则转到数组头部 */
    return  OK;
}

/* 若队列不空,则删除Q中队头元素,用e返回其值 */
Status DeQueue(Queue *Q,int *e)
{
    if (Q->front == Q->rear)			/* 队列空的判断 */
        return ERROR;
    *e=Q->data[Q->front];				/* 将队头元素赋值给e */
    Q->front=(Q->front+1)%MAXSIZE;	/* front指针向后移一位置, */
    /* 若到最后则转到数组头部 */
    return  OK;
}
/* ****************************************************** */

void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges=15;
    G->numVertexes=9;

    /* 读入顶点信息,建立顶点表 */
    G->vexs[0]='A';
    G->vexs[1]='B';
    G->vexs[2]='C';
    G->vexs[3]='D';
    G->vexs[4]='E';
    G->vexs[5]='F';
    G->vexs[6]='G';
    G->vexs[7]='H';
    G->vexs[8]='I';


    for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
    {
        for ( j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j]=0;
        }
    }

    G->arc[0][1]=1;
    G->arc[0][5]=1;

    G->arc[1][2]=1;
    G->arc[1][8]=1;
    G->arc[1][6]=1;

    G->arc[2][3]=1;
    G->arc[2][8]=1;

    G->arc[3][4]=1;
    G->arc[3][7]=1;
    G->arc[3][6]=1;
    G->arc[3][8]=1;

    G->arc[4][5]=1;
    G->arc[4][7]=1;

    G->arc[5][6]=1;

    G->arc[6][7]=1;


    for(i = 0; i < G->numVertexes; i++)
    {
        for(j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] =G->arc[i][j];
        }
    }
}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G,GraphAdjacencyList *GL){
    int i,j;
    EdgeNode *e;

    *GL = (GraphAdjacencyList)malloc(sizeof(graphAdjacencyList));

    (*GL)->numVertexes=G.numVertexes;
    (*GL)->numEdges=G.numEdges;
    for(i= 0;i <G.numVertexes;i++) {/* 读入顶点信息,建立顶点表 */
        (*GL)->adjacencyList[i].in=0;
        (*GL)->adjacencyList[i].data=G.vexs[i];
        (*GL)->adjacencyList[i].firstEdge=NULL; 	/* 将边表置为空表 */
    }

    for(i=0;i<G.numVertexes;i++) {/* 建立边表 */
        for(j=0;j<G.numVertexes;j++) {
            if (G.arc[i][j]==1) {
                e=(EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjacencyVertex=j;					/* 邻接序号为j */
                e->next=(*GL)->adjacencyList[i].firstEdge;	/* 将当前顶点上的指向的结点指针赋值给e */
                (*GL)->adjacencyList[i].firstEdge=e;		/* 将当前顶点的指针指向e */
                (*GL)->adjacencyList[j].in++;
            }
        }
    }

}













