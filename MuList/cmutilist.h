#ifndef CMUTILIST_H
#define CMUTILIST_H


typedef struct _Node
{
    int     data;
    _Node*  next;
    _Node*  prev;

}Node;

class CMutiList
{
public:
    CMutiList();
    ~CMutiList();

    void    AddToilNode(int data);
    void    PrintList(Node* head);
    Node*   TravToEnd(Node* head);
    Node*   TravToTail(Node* head);
    void    ReturnList();

private:
    Node*   m_head;
    Node*   m_curPostion;


};

#endif // CMUTILIST_H
