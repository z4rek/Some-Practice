#ifndef CSTACK_H
#define CSTACK_H

const int MAXSIZE = 100;
const int MINSIZE = 0;
const int STACKTOP = (MAXSIZE-1);
const int STACKBOTTOM = (MINSIZE-1);

typedef struct _Stack
{
    int top;
    int data[MAXSIZE];
}Stack;

class CStack
{
public:
    CStack();
    ~CStack();

    void*   ClearStack();
    int     Pop();
    int     Push(int data = 0);

private:
    Stack*  m_stack;
};

#endif // CSTACK_H
