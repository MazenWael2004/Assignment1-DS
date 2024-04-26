#include<bits/stdc++.h>
using namespace std;
const int capacity=1e5;
template <typename T>
class Queue{
    T arr[capacity];
    int front ;
    int end;
    int size;
public:
    Queue(): front(-1) , end(-1) , size(0){}
    bool isEmpty(){
        return (front==-1);
    }
    int queueSize (){
        return size ;
    }
    void enqueue (T element){
        if (isEmpty()){
            front++ , end++;
        } else{
            end++;
        }
        arr[end]=element;
    }
   T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return T();
        }
        T element = arr[front++];
        size--;
        return element;
    }

    T first() {
        if (isEmpty()) {
            cout << "Queue is empty. No first element.\n";
            return T();
        }
        return arr[front];
    }
    void clear() {
        front = -1;
        end = -1;
        size = 0;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index++] << " ";

        }
        cout << "\n";
    }

};
int main() {
    Queue<int> myQueue;

    // Enqueue elements
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
    cout << "First element of the queue: " << myQueue.first() << endl;

    myQueue.clear();
    cout << "Queue after clearing: ";
    myQueue.print();


    return 0;
}
