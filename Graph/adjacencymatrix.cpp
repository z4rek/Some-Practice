#include "adjacencymatrix.h"


AdjacencyMatrix::AdjacencyMatrix()
{
    m_graph = new graph1;
    m_numVertexes = 5;
    m_numEdges = 5;

}

void AdjacencyMatrix::CreateGraph()
{
    int i, j;
    //vertex
    for(i=0; i<m_numVertexes; i++)
    {
        m_graph->vexs[i] = g_vertex;
    }
    //Edge
    for(i=0; i<m_numVertexes; i++)
    {
        for(j=0; j<m_numVertexes; j++)
        {
            m_graph->arc[i][j] = g_infinity;
        }
    }
    //边赋权值 这里简化为x,y为固定值，没有输入改变，知道意思就行
    for(i=0; i<m_numEdges; i++)
    {
        int x = 0;
        int y = 1;
        m_graph->arc[x][y] = g_edge;
        //无向图，矩阵对称
        m_graph->arc[y][x] = m_graph->arc[x][y];
    }

}

