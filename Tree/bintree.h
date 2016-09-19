#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>

#if 0
//二叉树
1.二叉树（Binary Tree)定义：
    二叉树是n(n>=0)个结点的有限集合，该集合或者为空集(称为空二叉树),或者由一个根节点和两颗互不相交的分别称为根节点的左子树和右子树的二叉树组成。
2.二叉树特点：
    每个结点最多有两颗子树，所以二叉树中不存在度大于2的结点。注意不是只有2颗子树，而是最多，没有或者1棵都是可以的;
    左右子树是有顺序的，次序不能颠倒;
    即使树中某结点只有一棵子树，也要区分是左子树还是右子树;
3.二叉树的五种 基本 形态：
    a.空二叉树  b.只有1个根节点   c.根节点只有左子树  d.根节点只有右子树  e.根节点既有左子树又有右子树;
4.特殊二叉树:
    a.斜树：所有的结点都只有左子树的二叉树叫左斜树，反之，叫右斜树。
        特点：每层只有一个结点，结点的个数与二叉树的深度相同(大话数据书上说，线性表结构是树的一种极其特殊的表现形式);
    b.满二叉树：所有分支都存在左子树和右子树，并且所有叶子都在同一层上
        特点：1.叶子只能出现在最下层 2.非叶子结点的度一定是2   3.在同样深度的二叉树中，满二叉树的结点个数和叶子书最多
    c.完全二叉树:对于一颗具有n个结点的二叉树按层序编号，如果编号为i(1<=i<=n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同，则称为完全二叉树
        特点：1.叶子结点只能出现在最下两层 2.最下层的叶子一定集中在左部连续位置 3.倒数第二层，若有叶子一定都在右部连续位置
             4.如果结点度为1，则该结点只有左孩子，即不存在只有右子树的情况 5.同样二叉树，完全二叉树深度最下 （未完全理解4.5）;
5.二叉树性质:
    性质1:在二叉树的第i层上至多有2^(i-1)个结点(n>=1);
    性质2:深度为K的二叉树至多有(2^k)-1个结点(k>=1);
    性质3:对任何一棵二叉树T,如果其终端结点数为n,度为2的节点数为m,则n=m+1;
    性质4:具有n个结点的完全二叉树的深度为(log2^n)+1。 (具体看书)
    性质5:如果对一颗有n个结点的完全二叉树（其深度为k)的结点按层序编号（从第1层到K层，每层从左到右），对任一结点i(1<=i<=n)有:
         1.如果i=1,则结点i是二叉树的根，无双亲，如果i>1,则其双亲是结点(i/2);
         2.如果2i>n,则结点i无左孩子(结点i为叶子结点);否则其左孩子是结点2i;
         3.如果2i+1>n,则结点i无右孩子;否则其右孩子是结点2i+1;
    其他性质：1.已知二叉树 前序和中序 遍历，可以唯一确定一棵二叉树
            2.已知二叉树 后序和中序 遍历，可以唯一确定一棵二叉树
            3.已知二叉树 前序和后序 遍历，不能确定一棵二叉树。换句话说要唯一确定二叉树，必须要有 中序遍历！
;
#endif

namespace NBinTree {

const int MAXNODE = 100;

//数组顺序存储的二叉树
typedef struct _TNodeArr
{
    int data;
    int lchildPos;
    int rchildPos;
}TNodeArr;

class CBinTreeArr
{
public:
    CBinTreeArr();
    void PreOrder(int node=0);
    void InOrder(int node=0);
    void PosrOrder(int node=0);
    void LevelOrder();

private:
    int m_rootPos;
    int m_nodeNum;
    TNodeArr m_tree[MAXNODE];
};


//链式存储二叉树
typedef struct _TNodeList
{
    int data;
    _TNodeList* lchild;
    _TNodeList* rchild;
}TNodeList;

class CBinTreeList
{
public:
    CBinTreeList();
    CBinTreeList(const char* treeData, TNodeList* curRootNode);

    inline TNodeList* GetRoot()const   {return m_rootNode;}

    void PreOrder(TNodeList* node);
    void InOrder(TNodeList* node);
    void PosrOrder(TNodeList* node);
    void LevelOrder(TNodeList* node);

private:
    TNodeList* m_rootNode;
};



}
#endif // BINTREE_H





















