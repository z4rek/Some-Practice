#include <iostream>
#include "cmutilist.h"

//测试develop分支

using namespace std;

CMutiList::CMutiList()
{
    m_head = new Node;
    m_head->data = 0;
    m_head->next = NULL;
    m_head->prev = NULL;


    m_curPostion = new Node;
    m_curPostion->data = 0;
    m_curPostion->next = NULL;
    m_curPostion->prev = NULL;

    cout<<"Construct m_head..."<<m_head<<endl;
    cout<<"Construct m_curPostion..."<<m_curPostion<<endl;
}

Node* CMutiList::TravToEnd(Node *head)
{
    Node* curPostion = head;
    for(; curPostion->next!=NULL; curPostion=curPostion->next);
    return curPostion;
}

Node* CMutiList::TravToTail(Node *head)
{   
    Node* curPostion = head;
    for(; curPostion->next->next!=NULL; curPostion=curPostion->next);
    return curPostion;
}

CMutiList::~CMutiList()
{
    while(NULL != m_head->next)
    {
        m_curPostion = TravToTail(m_head);

        cout<<"Delete Address..."<<m_curPostion->next<<endl;
        delete m_curPostion->next;
        m_curPostion->next = NULL;
    }

    cout<<"Delete m_curPostion..."<<m_curPostion<<endl;
    cout<<"Delete m_head..."<<m_head<<endl;

    delete m_curPostion;
    delete m_head;
}

void CMutiList::AddToilNode(int data)
{
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;

    m_curPostion = TravToEnd(m_head);
    m_curPostion->next = NewNode;
    NewNode->prev = m_curPostion;
}

//不考虑prev指针,当做单向链表实现
void CMutiList::ReturnList()
{
//    Node* newNode = new Node;
//    newNode->next = m_head;
//    newNode->prev = NULL;
//    newNode->data = 0;

    //Node* tempHead = m_head->next;
    Node* tempHead = new Node;
    tempHead->next = m_head->next;
    tempHead->prev = NULL;
    tempHead->data = 0;

    m_head->next = NULL;

    while(NULL != tempHead->next)
    {
        m_curPostion = TravToTail(tempHead);
        Node* newNode = TravToEnd(m_head);
        newNode->next = m_curPostion->next;
        m_curPostion->next = NULL;
        m_curPostion->prev = newNode;
    }

    delete tempHead;

    cout<<"===Return List Ok!==="<<endl;
}

void CMutiList::PrintList(Node* head)
{
    if(NULL == head)
    {
        head = m_head;
    }

    m_curPostion = head;
    while(NULL != m_curPostion)
    {
        cout<<"The node (Address)Data =   "<<m_curPostion<<"---"<<m_curPostion->data<<endl;
        m_curPostion = m_curPostion->next;
    }

//    for(m_curPostion=m_head; m_curPostion->next!=NULL; m_curPostion=m_curPostion->next)
//    {
//        cout<<"The node (Address)Data =   "<<m_curPostion<<"---"<<m_curPostion->data<<endl;
//    }
//    cout<<"The node (Address)Data =   "<<m_curPostion<<"---"<<m_curPostion->data<<endl;
}











