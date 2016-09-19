#include <iostream>
#include <clist.h>

using namespace std;

int main()
{
#if 0
    int a = 2;
    int *p  = &a;
    p = &a;
    p = &a;
    p = &a;
    p = &a;
    *p = 20;
    int *q = p;
    cout<<"&a="<<&a<<"   "<<"a="<<a<<endl;
    cout<<"&p="<<&p<<"   "<<"p="<<p<<endl;
    cout<<"&q="<<&q<<"   "<<"q="<<q<<endl;

    Node node1;
    Node* node2 = &node1;
    Node* node3 = node2;
    cout<<"&node1="<<&node1<<"   "<<"node1="<<node1.data<<endl;
    cout<<"&node2="<<&node2<<"   "<<"node2="<<node2<<endl;
    cout<<"&node3="<<&node3<<"   "<<"node3="<<node3<<endl;


#endif

#if 1
//test list_in_heap
    Clist list;
    list.AddItem(30);
    list.AddItem(1);
    list.AddItem(22);
    list.AddItem(222);
    list.AddItem(20, 2);
    list.PrintList(NULL);

    list.AddItem(3, 5);
    list.AddItem(5, 100);
    list.AddItem(5, 520);
    list.PrintList(NULL);

    Node* rHead = list.ReturnList();
    list.PrintList(rHead);


    list.SeekNode(30);
    list.SeekNode(12);
    cout<<"----NodeNum is = "<<list.GetNodes()<<endl;
#endif

#if 0
//test list_in_stack
    
    cout<<"================== Now Test Stack List ==================="<<endl;
    Node head;
    head.next = NULL;
    head.data = 0;
    cout<<"head->address = "<<&head<<endl;

    Node node1;
    node1.next = NULL;
    node1.data = 1;
    head.next = &node1;
    printf("node1->address = %p\n", &node1);
    //cout<<"node1->address = "<<&node1<<endl;

    Node StackNode;
    Node* node2 = &StackNode;
    //Node *node2;    //Release error but Debug Ok
    //Node *node2 = new Node;
    node2->next = NULL;
    node2->data = 2;
    node1.next = node2;
    cout<<"node2->address = "<<node2<<endl;
    //printf("%p\n", *node2);
    //cout<<"&node2 = "<<&node2;
    //cout<<"&node2="<<&node2<<" node2="<<node2<<endl;

    Node node3;
    node3.next = NULL;
    node3.data = 3;
    node2->next = &node3;
    cout<<"node3->address = "<<&node3<<endl;

    Node *tempNode=&head;
    for(; tempNode->next != NULL; )
    {
        cout<<"temoNode->address = "<<tempNode<<endl;
        cout<<"temoNode->data = "<<tempNode->data<<endl;
        tempNode = tempNode->next;
    }
    cout<<"temoNode->address = "<<tempNode<<endl;
    cout<<"temoNode->data = "<<tempNode->data<<endl;


    cout<<"====== Test Ptr ======"<<endl;
    int a = 2;
    int *p;
    //int *p = &a;
    cout<<"&a = "<<&a<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"&p = "<<&p<<endl;
    //cout<<"*p = "<<*p<<endl;

    int *q = NULL;
    cout<<"q = "<<q<<endl;
    cout<<"&q = "<<&q<<endl;
    //cout<<"*q = "<<*q<<endl;
    
    //cout << "Hello World!" << endl;
#endif

    cout << "Hello World!" << endl;
    return 0;
}

