#include "clist.h"
#include <iostream>

//Test GitOsc
using namespace std;

Clist::Clist()
{
    m_testData = 0;

    m_head = new Node;
    m_head->next = NULL;
    m_head->data = 0;

    m_curNode = new Node;
    m_curNode->next = NULL;
    m_curNode->data = 0;

    cout<<"In construct....               "<<endl;
    cout<<"m_head Address = "<<m_head<<"     ";
    cout<<"m_curNode Address = "<<m_curNode<<endl;

}

Clist::~Clist()
{

    cout<<"Now Destroy..."<<endl;
    int deleteTimes = 0;
    while(NULL != m_head->next)
    {
        for(m_curNode=m_head; m_curNode->next->next != NULL; m_curNode=m_curNode->next);


        cout<<"delete  "<<m_curNode->next<<endl;
        delete m_curNode->next;
        m_curNode->next = NULL;
        deleteTimes++;
    }

    cout<<"delete Head  "<<m_head<<endl;
    delete m_head;
    deleteTimes++;

    delete m_curNode;
    deleteTimes++;
    cout<<"deleteTimes = "<<deleteTimes<<endl;

    cout<<"===Test m_testData==== "<<m_testData<<" ====="<<endl;
}

Node* Clist::TravToEnd(Node *head)
{
    for(m_curNode=head; m_curNode->next!=NULL; m_curNode=m_curNode->next);
    return m_curNode;
}

void Clist::AddItem(int NewData)
{
    m_testData++;
    Node *NewNode = new Node;
    cout<<"Now AddNode..."<<endl;
    cout<<"AddNode Address = "<<NewNode<<endl;

    if(NULL == m_head->next)
    {
        m_head->next = NewNode;
        NewNode->next = NULL;
        NewNode->data = NewData;
    }
    else
    {
        m_curNode = TravToEnd(m_head);
        m_curNode->next = NewNode;
        NewNode->next = NULL;
        NewNode->data = NewData;
    }
}

void Clist::AddItem(int pos, int NewData)
{

    cout<<"m_head Address = "<<m_head <<endl;
    cout<<"m_cur Address = "<<m_curNode <<endl;

    Node *NewNode = new Node;
    NewNode->data = NewData;
    NewNode->next = NULL;
    cout<<"Now AddNode..."<<endl;
    cout<<"AddNode Address = "<<NewNode<<endl;

    if(pos>this->GetNodes() || pos<0)
    {
        delete NewNode;
        cout<<"pos error!"<<endl;
        return;
    }


    m_curNode = m_head;
    for(int i=1; i<pos; i++)
    {
        cout<<"m_curNode Adress = "<<m_curNode<<"   ";
        m_curNode = m_curNode->next;
        cout<<"mov! m_curNode Adress = "<<m_curNode<<endl;
    }

    NewNode->next = m_curNode->next;
    m_curNode->next = NewNode;
}

void Clist::PrintList(Node* head)
{
    if(NULL == head)
    {
        head = m_head;
    }
    m_testData++;
    cout<<"Now Printf List..."<<endl;
    if(NULL == head->next)
    {
        cout<<"CurNode Adress = "<<head<<endl;
        cout<<"CurNode Data = "<<head->data<<endl;
    }
    else
    {
        for(m_curNode=head->next; m_curNode->next != NULL;)
        {
            std::cout<<"CurNode Address = "<<m_curNode<<"     ";
            cout<<"CurNode Data = "<<m_curNode->data<<endl;
            m_curNode = m_curNode->next;
        }
        std::cout<<"CurNode Address = "<<m_curNode<<"     ";
        cout<<"CurNode Data = "<<m_curNode->data<<endl;
    }
}

void Clist::SeekNode(int data)
{
    cout<<"Now SeekNode..."<<endl;
    int flag = 0;
    for(m_curNode=m_head; m_curNode->next != NULL;)
    {
        if(data == m_curNode->data)
        {
            flag = 1;
            cout<<"the match nodeAddress is = "<<m_curNode<<endl;
        }
        m_curNode = m_curNode->next;
    }
    if(data == m_curNode->data)
    {
        flag = 1;
        cout<<"the match nodeAddress is = "<<m_curNode<<endl;
    }

    if(flag == 0)
    {
        cout<<"No match"<<endl;
    }
}

int Clist::GetNodes()
{
    int num = 1;
    for(m_curNode=this->m_head; m_curNode->next!=NULL; )
    {
        num++;
        m_curNode = m_curNode->next;
    }

    return num;
}

Node* Clist::ReturnList()
{
    Node *tempHead = new Node;
    tempHead->next = m_head->next;
    m_head->next = NULL;
    Node *tempNode = m_head;

    while(tempHead->next != NULL)
    {
        //偏移到倒数第二个节点
        for(m_curNode=tempHead; m_curNode->next->next!=NULL; m_curNode=m_curNode->next);

        for(tempNode=m_head; tempNode->next!=NULL; tempNode=tempNode->next);

        tempNode->next = m_curNode->next;
        m_curNode->next = NULL;
    }

    delete tempHead;

    return m_head;
}








