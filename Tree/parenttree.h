#ifndef PARENTTREE_H
#define PARENTTREE_H

//双亲表示法
namespace parentTree {

const int MaxNode = 100;

typedef struct
{
    int data;
    int parentPos;

}TNode;

class CParentTree
{
public:
    CParentTree();
    void AddNode(int parentPos, int data);
    int Depth();
    int Degree();

    void printTree();

private:
    TNode m_tree[MaxNode];  //这棵树可包含的最大结点个数
    int m_rootPos;  //根的位置
    int m_nodeNum;  //结点个数
};

#endif // PARENTTREE_H

}
