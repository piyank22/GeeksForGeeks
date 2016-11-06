#include <cstdio>
#include <algorithm>

using namespace std;


class queue
{
    int *data;
    int front,rear,size;
    unsigned int capacity;

public:

    queue(unsigned int capacity) : data( (capacity)?new int[capacity]:NULL ) , capacity(capacity) , front(0) , rear(capacity-1) , size(0) { } 

    bool isFull()
    {
        return (this->size==this->capacity);
    }

    bool isEmpty()
    {
        return (this->size==0);
    }

    void enqueue(int d)
    {
        if(isFull())
        {
            printf("Cannot add more elements to the queue!!\n");
        }
        else
        {
            this->rear=(this->rear+1)%this->capacity;
            data[this->rear]=d;
            this->size++;
        }
    }

    int dequeue()
    {
        if(isEmpty())
        {
            printf("Already empty stupid\n");
            return -1;
        }
        else
        {
            int temp=this->data[this->front];
            this->size--;
            this->front=(this->front + 1)%this->capacity;
            return temp;
        }
    }

    void print()
    {
        if(size==0)
            printf("Enpty\n");
        else
        {
            printf("The Queue at current state\n");
            for(int i=front;i<=rear;i=(i+1)%capacity)
                printf("%d\t",data[i]);
            printf("\n");
        }
    }

};

int main()
{
    queue q(10);
    q.enqueue(10);
    printf("%d\n",q.dequeue());
    q.enqueue(100);
    q.enqueue(12);
    q.enqueue(111);
    q.print();
    printf("%d\n",q.dequeue());
    printf("%d\n",q.dequeue());
    printf("%d\n",q.dequeue());
    printf("%d\n",q.dequeue());
    return 0;
}