#include<bits/stdc++.h>
using namespace std;
template <typename T>

struct node
{
public:
    T data;
    node* next;
    node(T e)
    {
        data=e;
        next = NULL;
    }
};
template <typename T>
class Queue{
    node<T>* front;
    node<T>* end;
    int count=0;
public:
    Queue(): front(NULL),end(NULL){}
    bool isEmpty (){
        return (front==NULL && end==NULL);
    }
    int queueSize (){
        return count;
    }
   void enqueue (T element){
        node<T>*newnode=new node(element);
        newnode->next=NULL;
       if  (isEmpty()){
           front=newnode;
           end=newnode;
       } else{
           end->next=newnode;
           end=newnode;
       }

        count++;

    }
    T dequeue (){
        T delvalue ;
        if (isEmpty())
            cout << "The queue is empty \n";
        else if (front == end)
        {
            delete front;
            front = end = NULL;
            count--;
            return delvalue;
        }
        else
        {
            node<T>* delptr = front;
            front = front->next;
            delvalue = delptr->data;
            delete delptr;
            count--;
            return delvalue;
        }


    }
    T frist()
    {
        return front->data;
    }

    void  Clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }

    }
    void print(){
        node<T>*temp=front;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }



};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Queue after enqueue: ";
    myQueue.print();

    int dequeuedValue = myQueue.dequeue();
    cout << "Dequeued value: " << dequeuedValue << endl;

    cout << "Queue after dequeue: ";
    myQueue.print();

    if (myQueue.isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }

    cout << "Size of the queue: " << myQueue.queueSize() << endl;

    cout << "First element of the queue: " << myQueue.frist() << endl;
    myQueue.Clear();

    cout << "Queue after clearing: ";
    myQueue.print();

    return 0;
}
