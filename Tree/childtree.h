#ifndef CHILDTREE_H
#define CHILDTREE_H

//孩子表示法
namespace childTree {

const int MaxNode = 100;
typedef struct _TNodeChild
{
    int pos;
    _TNodeChild* next;
}TNodeChild;
typedef struct _TNode
{
    int data;
    //_TNode* brother;    //双亲孩子结点指针，用来指向自己的兄弟  思维混乱了，孩子表示法和孩子兄弟表示法弄混淆了！
    _TNodeChild* childHead; //自己孩子的头指针，用来指向自己的孩子

}TNode;

class CChildTree
{
public:
    CChildTree();
    void AddNode(int parentPos, int data);
    void PrintTree();
    int Depth();
    int Degree();

private:
    TNode m_tree[MaxNode];
    int m_nodeNum;
    int m_rootPos;

};

}
#endif // CHILDTREE_H
