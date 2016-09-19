#include <iostream>
#include <string.h>
#include "bintree.h"

using namespace std;
using namespace NBinTree;

//====================BinTreeArray start========================
CBinTreeArr::CBinTreeArr()
{
    m_nodeNum = 1;
    m_rootPos = 0;

    m_tree[m_rootPos].data = 0;
    m_tree[m_rootPos].lchildPos = -1;
    m_tree[m_rootPos].rchildPos = -1;
}

//先序遍历口诀：根左右
void CBinTreeArr::PreOrder(int node)
{
   if(node == -1)
       return;

   cout<<m_tree[node].data<<"   ";
   PreOrder(m_tree[node].lchildPos);
   PreOrder(m_tree[node].rchildPos);
}

//中序遍历口诀：左根右
void CBinTreeArr::InOrder(int node)
{
    if(node == -1)
        return;

    InOrder(m_tree[node].lchildPos);
    cout<<m_tree[node].data<<"   ";
    InOrder(m_tree[node].rchildPos);
}

//后序遍历口诀:左右根
void CBinTreeArr::PosrOrder(int node)
{
    if(-1 == node)
        return;
    PosrOrder(m_tree[node].lchildPos);
    PosrOrder(m_tree[node].rchildPos);
    cout<<m_tree[node].data<<"   ";
}

void CBinTreeArr::LevelOrder()
{

}

//====================BinTreeList start========================
CBinTreeList::CBinTreeList()
{
    m_rootNode = new TNodeList;
    m_rootNode->data = 0;
    m_rootNode->lchild = NULL;
    m_rootNode->rchild = NULL;
}

#if 1
CBinTreeList::CBinTreeList(const char* treeData, TNodeList* curRootNode)
{
    int i = strlen(treeData);
    if(i == 0)
    {
        return;
    }

    if(treeData[0] == '#')
    {
        curRootNode = NULL;
        treeData = treeData+1;
    }
    else
    {
        curRootNode = new TNodeList;
        curRootNode->data = static_cast<int>(treeData[0]);
        curRootNode->lchild = NULL;
        curRootNode->rchild = NULL;

        treeData = treeData+1;
        CBinTreeList(treeData, curRootNode->lchild);
        CBinTreeList(treeData, curRootNode->rchild);
    }
}
#endif

//先序:根左右
void CBinTreeList::PreOrder(TNodeList* node)
{
    if(node == NULL)
        return;

    cout<<node->data<<"   ";
    PreOrder(node->lchild);
    PreOrder(node->rchild);
}

//中序：左根右
void CBinTreeList::InOrder(TNodeList *node)
{
    if(node == NULL)
        return;

    PreOrder(node->lchild);
    cout<<node->data<<"   ";
    PreOrder(node->rchild);
}

//后序：左右根
void CBinTreeList::PosrOrder(TNodeList *node)
{
    if(node == NULL)
        return;

    PreOrder(node->lchild);
    PreOrder(node->rchild);
    cout<<node->data<<"   ";
}



























