#ifndef CLIST_H
#define CLIST_H

typedef struct _Node
{
    int    data;
    _Node* next;

}Node;


class Clist
{
public:
    Clist();
    ~Clist();


    //参数：NewData 输入新增节点int型数据
    //返回值：增加完节点后的链表的头节点
    void AddItem(int NewData);
    void AddItem(int pos, int NewData);

    Node* ReturnList();
    Node* TravToEnd(Node* head);

    int   GetNodes();

    void  PrintList(Node* head);
    void  SeekNode(int data);


private:
    int   m_testData;
    int   m_data;
    Node* m_head;
    Node* m_curNode;

};

#endif // CLIST_H
