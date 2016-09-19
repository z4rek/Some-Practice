#include <iostream>
#include "cmutilist.h"

//测试推送

using namespace std;

int main()
{
#if 0
    int a = 2;
    int *p = new int;
    p = &a;
    cout<<"&p..."<<&p<<"...p="<<p<<endl;
    delete p;
    cout<<"&p..."<<&p<<"...p="<<p<<endl;
    cout<<"&a..."<<&a<<"...a="<<a<<endl;
    p = &a;
    cout<<"&p..."<<&p<<"...p="<<p<<endl;

    int *q = NULL;
    cout<<"&q..."<<&q<<"...q="<<q<<endl;
    delete q;
    cout<<"&q..."<<&q<<"...q="<<q<<endl;
#endif

    CMutiList muList;
    muList.AddToilNode(30);
    muList.AddToilNode(300);
    muList.AddToilNode(3000);

    muList.PrintList(NULL);
    muList.ReturnList();
    muList.PrintList(NULL);




    cout << "Hello World!" << endl;
    return 0;
}

