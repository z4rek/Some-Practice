#include "brothertree.h"
#include "iostream"

using namespace std;
using namespace NBrotherTree;


CbrotherTree::CbrotherTree()
{
    m_rootPos = 0;
    m_numNode = 1;

    m_tree[m_rootPos].data = 0;
    m_tree[m_rootPos].child = NULL;
    m_tree[m_rootPos].brother = NULL;
}

void CbrotherTree::AddNode(int parentPos, int data)
{
    if(parentPos<0 || parentPos>m_numNode)
    {
        cout<<"parentPos error!\n";
        return;
    }

    //还是老规矩，先考虑新增结点的数据初始化，再考虑挂到哪个父结点上
    m_tree[m_numNode].data = data;
    m_tree[m_numNode].brother = NULL;
    m_tree[m_numNode].child = NULL;

    TNode* curNode = &m_tree[parentPos];
    if(curNode->child == NULL)
    {
        curNode->child = &m_tree[m_numNode];
    }
    else
    {
        curNode = m_tree[parentPos].child;
        while(curNode->brother != NULL)
        {
            curNode = curNode->brother;
        }
        curNode->brother = &m_tree[m_numNode];
    }

    m_numNode++;
}

void CbrotherTree::printTree()
{
    cout<<"curPos---child---brother---brother..."<<endl;
    for(int i=0; i<m_numNode; i++)
    {
        if(m_tree[i].brother==NULL && m_tree[i].child==NULL)
        {
            cout<<i<<"---NoChild---NoBrother---"<<endl;
        }
        else if(m_tree[i].brother!=NULL && m_tree[i].child!=NULL)
        {
            cout<<i<<"---"<<m_tree[i].child->data<<"---"<<m_tree[i].brother->data<<"---"<<endl;
        }
        else if(m_tree[i].brother == NULL)
        {
            cout<<i<<"---"<<m_tree[i].child->data<<"---NoBrother---"<<endl;
        }
        else
        {
            cout<<i<<"---NoChild---"<<m_tree[i].brother->data<<"---"<<endl;
        }
    }
}


int CbrotherTree::Degree()
{
    int tempDegree = 0;
    int maxDegree = 0;

    TNode* curNode = NULL;
    for(int i=0; i<m_numNode; i++)
    {
        tempDegree = 0;
        curNode = &m_tree[i];
        if(curNode->child != NULL)
        {
            tempDegree = 1;
            curNode = curNode->child;
            while(curNode->brother != NULL)
            {
                curNode = curNode->brother;
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

int CbrotherTree::Depth()
{
    int tempDepth = 0;
    int maxDepth = 0;
    TNode* curNode = NULL;

    for(int i=0; i<m_numNode; i++)
    {
        tempDepth = 0;
        curNode = &m_tree[i];
        while(curNode->child != NULL)
        {
            tempDepth++;
            curNode = curNode->child;
        }

        if(tempDepth > maxDepth)
        {
            maxDepth = tempDepth;
        }
    }

    return maxDepth;
}












