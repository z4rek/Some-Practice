#include <iostream>
#include "parenttree.h"
#include "childtree.h"
#include "brothertree.h"
#include "bintree.h"

using namespace std;


#if 0
数据结构分为逻辑结构和物理结构:
    1.逻辑结构：数据对象中数据元素之间的相互关系。-----逻辑结构有4种基本类型：集合结构、线性结构、树状结构和网络结构。
        1.集合: 数据结构中的元素之间除了“同属一个集合” 的相互关系外，别无其他关系；
        2.线性结构: 数据结构中的元素存在一对一的相互关系;
        3.树形结构: 数据结构中的元素存在一对多的相互关系;
        4.图形结构: 数据结构中的元素存在多对多的相互关系;
    2.物理结构:（或者称为存储结构）数据的逻辑结构在计算机中的存储形式;
        1.顺序存储结构;
        2.链式存储结构;

线性结构：                                              树形结构：
    第一个数据元素：无前驱                                    根节点：无双亲，唯一结点
    中间数据元素：有前驱，有后继                               中间结点：一个双亲多个孩子
    最后一个数据元素：无后继                                  叶结点:无孩子，可以多个


一、树的逻辑结构分析
1.树的定义： 树是n(n>0&&n==0)个节点的有限集.n=0时称为空树,在任何一个非空树中:
    (1)有且仅有一个特定的称为根的节点(Root);
    (2)当n>1时候,其余节点可分为m(m>0)个互不相交有限集T1，T2，T3...TM。其中每一个集合本身又是一棵树，并且称为根的子树
    ！注意：a.根节点只有一个   b.子树是互不相交的
2.树的度(Degree)：结点拥有的子树数称为结点的度  （度为0的结点称为叶结点[Leaf]或者终端结点，度不为0的结点称为分支结点或者非终端结点）
    除根节点外，分支结点也称为内部结点
    树的度是树内各结点的度的最大值
3.树的层次(Level)：根为第一层，根的孩子在第二层，若某结点在第i层，其子树的根就在第i+1层。
    树中结点的最大层数称为树的深度(Depth)或者高度。
    如果树中结点的各子树从左至右是有次序，不能互换的，则称该树为有序树，否则称为无序树。
    森林是m(m>=0)颗互不相交的树的集合，对树中每个结点而言，其子树的集合即为森林
4.结点间关系：
    结点的子树的根称为节点的孩子(Child)，相应的该结点称为孩子的双亲(Parent)
    同一个双亲的孩子之间互相称为兄弟(Sibling)，同一层不同双亲的结点互相称为堂兄弟
    结点的祖先是从根到该结点所经分支上的所有结点，反之，以某结点为根的子树中的任一结点都称为该结点的子孙


二、树的物理存储结构分析
    //顺序存储结构：1.双亲表示法
    //链式存储结构：2.孩子表示法   3.孩子兄弟表示法
    上述注释存储结构分析错误：
    1.双亲表示法，完全采用数组方式，顺序存储
    2.孩子表示法，采用链表存储孩子结点，再采用数组存储头结点，顺序和链式存储结构都用到了。
         定义为：把每个结点的孩子结点排列起来，以单链表作存储结构，则n个结点有n个孩子链表,如果是叶子结点则此单链表
                为空。然后n个头指针又组成一个线性表，采用顺序存储结构，存放进一个一位数组中。
         疑问：书上是只有一个ChildHead指针，仅有一个孩子头指针，但是目前认为是错误的，结点除了需要孩子头指针串兄弟外必须还要有自己的孩子指针 (2016/4/22)
         对上面疑问解答：经过思考，想明白了，上面提出的疑问其实是孩子兄弟表示法的思路，两个指针都是指向结点。但现在孩子表示法，确实是只要一个孩子的头指针，
                      因为，这个指针不是指向结点而就是链表！   (16/04/22解答)
    3.孩子兄弟表示法：易和上述孩子表示法混为一谈，理不清楚，关键是指针的类型！孩子表示法，指针指向链表;孩子兄弟指针指向结点！
;
#endif


int main()
{

#if 0
/*
    int a = 20;
    int b = a;
    cout<<&b<< &a<<endl;
    int *p = &a;
    int *q = p;
    cout<<&q<<"---"<<*q<<endl;
    *q = 22;
    cout<<&p<<"---"<<*p<<endl;
*/

    int *p = NULL;
    int *q = p;
    cout<<p<<"---"<<&p<<"========"<<q<<"---"<<&q<<endl;
    p = new int;
    cout<<p<<"---"<<&p<<"========"<<q<<"---"<<&q<<endl;

    int a =0;
    int b =1;
    int *p2 = &a;
    int *q2 = p2;
    cout<<p2<<"---"<<&p2<<"========"<<q2<<"---"<<&q2<<endl;
    p2 = &b;
    cout<<p2<<"---"<<&p2<<"========"<<q2<<"---"<<&q2<<endl;

    return 0;
#endif

    cout<<"--------------ParentTree-----------\n";
    parentTree::CParentTree tree1;
    tree1.AddNode(0, 1);
    tree1.AddNode(0, 2);
    tree1.AddNode(2, 3);
    tree1.AddNode(2, 3);
    tree1.AddNode(2, 3);
    tree1.AddNode(2, 3);
    //tree1.AddNode(2, 3);
    tree1.AddNode(0, 3);
    tree1.printTree();
    int depth = tree1.Depth();
    cout<<"tree1.Depth = "<<depth<<endl;
    int degree = tree1.Degree();
    cout<<"tree1.Degree = "<<degree<<endl;

    cout<<"-------------- ChildTree ----------\n";
    childTree::CChildTree tree2;
    tree2.PrintTree();
    tree2.AddNode(200, 2);
    tree2.AddNode(0, 2);
    tree2.AddNode(0, 2);
    tree2.AddNode(1, 2);
    tree2.PrintTree();
    degree = tree2.Degree();
    cout<<"tree2.Degree = "<<degree<<endl;

    cout<<"--------------BrotherTree-----------\n";
    NBrotherTree::CbrotherTree brotherTree;
    brotherTree.AddNode(0,1);
    brotherTree.AddNode(0,2);
    brotherTree.AddNode(1,3);
    brotherTree.AddNode(1,4);
    brotherTree.AddNode(1,5);
    brotherTree.AddNode(3,6);
    brotherTree.printTree();
    degree = brotherTree.Degree();
    cout<<"brother.Degree = "<<degree<<endl;
    depth = brotherTree.Depth();
    cout<<"brother.Depth = "<<depth<<endl;

    cout<<"--------------BinaryTreeArray-----------\n";
    NBinTree::CBinTreeArr  binTree;
    cout<<"---PreOrder---"<<endl;
    binTree.PreOrder();
    cout<<"\n---InOrder---"<<endl;
    binTree.InOrder();
    cout<<"\n---PostOrder---"<<endl;
    binTree.PosrOrder();

    cout<<"\n--------------BinaryTreeList-----------\n";
    NBinTree::CBinTreeList  binTreeList;
    NBinTree::TNodeList* rootNode = binTreeList.GetRoot();
    cout<<"---PreOrder---"<<endl;
    binTreeList.PreOrder(rootNode);
    cout<<"\n---InOrder---"<<endl;
    binTreeList.InOrder(rootNode);
    cout<<"\n---PostOrder---"<<endl;
    binTreeList.PosrOrder(rootNode);

    NBinTree::TNodeList* testRootNode = NULL;
    NBinTree::CBinTreeList  binTreeList2("1234567", testRootNode);
    cout<<"\n---PreOrder---"<<endl;
    binTreeList2.PreOrder(testRootNode);
/*
    std::string str1 = "1234567";
    cout<<endl<<str1<<"   "<<str1[0]<<"   "<<str1.size()<<endl;
*/

/*
    const char* str2 = "12345678";
    cout<<endl<<str2<<"---"<<str2+1<<endl;
*/

    cout<<endl<<endl;
    cout << "Hello World!" << endl;

    return 0;

}





























