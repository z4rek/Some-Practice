#ifndef BROTHERTREE_H
#define BROTHERTREE_H

namespace NBrotherTree {

const int MAXNODE = 100;
typedef struct _TNode
{
    int data;
    _TNode* brother;
    _TNode* child;

}TNode;

class CbrotherTree
{
public:
    CbrotherTree();
    void AddNode(int parentPos, int data);
    void printTree();
    int Depth();
    int Degree();


private:
    int m_numNode;
    int m_rootPos;
    TNode m_tree[MAXNODE];
};

}


#endif // BROTHERTREE_H
