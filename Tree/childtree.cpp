#include <iostream>
#include "childtree.h"

using namespace std;
using namespace childTree;

CChildTree::CChildTree()
{
    m_rootPos = 0;
    m_nodeNum = 1;

    m_tree[m_rootPos].childHead = NULL;
    m_tree[m_rootPos].data = 0;
}

void CChildTree::AddNode(int parentPos, int data)
{
    if(parentPos<0 || parentPos>m_nodeNum)
    {
        cout<<"parentPos error!\n";
        return;
    }
    //先考虑新增的子节点  这是针对 树上 的结点
    m_tree[m_nodeNum].data = data;
    m_tree[m_nodeNum].childHead = NULL;
    //这是针对新增的链表！ 再考虑将这个子节点应该是哪个结点的后代，注意，关键就是放入的是pos,并新增一个结点串入头结点的next内。而不是该结点的地址
    TNodeChild* newNode = new TNodeChild;
    newNode->pos = m_nodeNum;
    newNode->next = NULL;

    TNodeChild* curNode = m_tree[parentPos].childHead;
    if(curNode == NULL)
    {
        //下面这句话是个坑！遇到NULL节点时，操作链表时一定注意了,别再弄错了！
        //curNode = newNode;
        m_tree[parentPos].childHead = newNode;
    }
    else
    {
        while (curNode->next != NULL)
        {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }

    m_nodeNum++;
}

void CChildTree::PrintTree()
{
    cout<<"curPos---childHeadPos---data\n";

    for(int i=0; i<m_nodeNum; i++)
    {
        if(m_tree[i].childHead == NULL)
        {
            cout<<i<<"---NoChild---"<<m_tree[i].data<<endl;
            continue;
        }
        cout<<i<<"   "<<m_tree[i].childHead->pos<<"   "<<m_tree[i].data<<endl;
    }
}

//求深度。貌似孩子表示法不太适合求深度，先跳过
int CChildTree::Depth()
{
    //int tempDepth = 1;
    //int maxDepth = 1;

    for(int i=0; i<m_nodeNum; i++)
    {

    }

    return 0;
}

int CChildTree::Degree()
{
    int tempDegree = 0;
    int maxDegree = 0;

    for(int i=0; i<m_nodeNum; i++)
    {
        tempDegree = 0;

        TNodeChild* curNode = m_tree[i].childHead;
        if(curNode == NULL)
            continue;

        tempDegree = 1;
        while(curNode->next != NULL)
        {
            curNode = curNode->next;
            tempDegree++;
        }

        if(tempDegree > maxDegree)
        {
            maxDegree = tempDegree;
        }

    }

    return maxDegree;
}




























