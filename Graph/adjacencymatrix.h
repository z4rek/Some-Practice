#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H


//1.邻接矩阵: 一维数组存顶点信息，二维数组（邻接矩阵）存边或弧的信息
typedef int VertexType;
typedef int  EdgeType;

const int g_maxves = 100;
const int g_infinity = 65535;
const int g_vertex = 99;
const int g_edge = 98;

typedef struct
{
    //顶点
    VertexType vexs[g_maxves];
    //边
    EdgeType arc[g_maxves][g_maxves];
}graph1;

class AdjacencyMatrix
{
public:
    AdjacencyMatrix();
    void CreateGraph();

private:
    int m_numVertexes;
    int m_numEdges;

    graph1* m_graph;

};

#endif // ADJACENCYMATRIX_H
