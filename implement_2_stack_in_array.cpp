#include <cstdio>
#include <algorithm>

using namespace std;


class stack
{
    int *data;
    int top1,top2;
    unsigned int capacity;

public:

    stack(unsigned int capacity) : data( (capacity)?new int[capacity]:NULL ) , top1(-1) , capacity(capacity) , top2(capacity) {  } 

    bool isFull()
    {
        return ( (this->top1) - (this->top2)  == 1 );
    }

    bool isEmpty1()
    {
        return (this->top1==-1);
    }

    bool isEmpty2()
    {
        return (this->top2==capacity);
    }

    void push1(int data)
    {
        if(!(this->isFull()))
            this->data[++(this->top1)]=data;
        else
            printf("\nThe stack is already full\n");
    }

    void push2(int data)
    {
        if(!(this->isFull()))
            this->data[--(this->top2)]=data;
        else
            printf("\nThe stack is already full\n");
    }

    int pop1()
    {
        if(this->isEmpty1())
            return INT_MIN;
        return this->data[(this->top1)--];
    }

     int pop2()
    {
        if(this->isEmpty2())
            return INT_MIN;
        return this->data[(this->top2)++];
    }

};



int main()
{
    stack s(10);
    s.push1(100);
    printf("%d",s.pop1());

    return 0;
}