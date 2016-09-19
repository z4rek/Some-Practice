#include <iostream>
#include "cstack.h"

using namespace std;

int main()
{
    CStack  stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    cout<<stack.Pop()<<endl;
    cout << "Hello World!" << endl;
    return 0;
}

