#include "parenttree.h"
#include <iostream>
using namespace std;
using namespace parentTree;

//双亲表示法
CParentTree::CParentTree()
{
    m_rootPos = 0;
    m_nodeNum = 1;

    m_tree[m_rootPos].parentPos = -1;
    m_tree[m_rootPos].data = 0;

}

void CParentTree::AddNode(int parentPos, int data)
{
    m_nodeNum++;
    m_tree[m_nodeNum-1].parentPos = parentPos;
    m_tree[m_nodeNum-1].data = data;
}

void CParentTree::printTree()
{
    cout<<"curPos---parentPos---data\n";
    for(int i=0; i<m_nodeNum; i++)
    {
        cout<<i<<"   "<<m_tree[i].parentPos<<"   "<<m_tree[i].data<<endl;
    }
}

int CParentTree::Depth()
{
    int tempDepth = 1;
    int maxDepth = 1;
    int curPos = 0;

    for(int i=1; i<m_nodeNum; i++)
    {
        tempDepth = 1;
        curPos = i;

        while(m_tree[curPos].parentPos != -1)
        {
           curPos = m_tree[curPos].parentPos;
           tempDepth++;
        }

        if(tempDepth > maxDepth)
        {
            maxDepth = tempDepth;
        }
    }
    return maxDepth;
}

int CParentTree::Degree()
{
    int tempDegree = 0;
    int maxDegree = 0;

    for(int i=0; i<m_nodeNum; i++)
    {
        tempDegree = 0;
        for(int j=1; j<m_nodeNum; j++)
        {
            if(m_tree[j].parentPos == i)
            {
                tempDegree++;
            }
        }

        if(tempDegree > maxDegree)
        {
            maxDegree = tempDegree;
        }
    }

    return maxDegree;
}








