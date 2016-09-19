#include "cstack.h"

CStack::CStack()
{
    m_stack = new Stack;
    m_stack->top = 0;
    m_stack->data[0] = 0;

}

CStack::~CStack()
{
    delete  m_stack;
}

int CStack::Push(int data)
{
    if(STACKTOP == m_stack->top)
        return -1;
    else
    {
        m_stack->top++;
        m_stack->data[m_stack->top] = data;

    }
    return 0;
}

int CStack::Pop()
{
    int popData = 0;
    if(STACKBOTTOM == m_stack->top)
        return -1;
    else
    {
        popData = m_stack->data[m_stack->top];
        m_stack->top--;
    }
    return  popData;
}
