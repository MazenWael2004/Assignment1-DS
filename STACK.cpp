#include <bits/stdc++.h>
using namespace std;

template<class Type>
struct Node{
    Type item;
    Node<Type> *Next;
};

template<class Type>
class Stack {
private:
    int Top;
    Node<Type> *stackTop;
public:
    Stack(){
        Top = -1;
        stackTop = NULL;
    }
    bool isEmpty(){
        if(Top==-1)
            return true ;
        return false;
    }
    int stackSize(){
        return Top+1;
    }
    void push(Type element){
        Node<Type> *NewNode;
        NewNode = new Node<Type>;
        NewNode->item=element;
        if(isEmpty()){
            NewNode->Next = NULL;
            stackTop = NewNode;
        }
        else{
            NewNode->Next = stackTop;
            stackTop = NewNode ;
        }
        Top++;
    }
    Type pop(){
        if(isEmpty())
            cout<< "The Stack is Empty"<<endl;
        else{
            Node<Type> *current;
            current = stackTop ;
            Type TopElement = stackTop->item;
            stackTop = stackTop->Next ;
            delete current ;
            Top--;
            return TopElement ;
        }
    }
    Type top(){
        if(isEmpty())
            cout<<"The stack is Empty";
        else{
            return stackTop->item;
        }
    }
    void print(){
        if(isEmpty())
            cout<<"The stack is Empty";
        else {
            Node<Type> *current;
            current = stackTop;
            for (int i = Top; i >= 0; i--) {
                cout << current->item << endl;
                current = current->Next;
            }
        }
    }
    void clear(){
        if(isEmpty())
            return;
        else{
        Node<Type> *current,*temp;
        current = stackTop ;
        for(int i=Top ;i >= 0 ; i--){
            temp = current->Next;
            delete current;
            current = temp;
        }
        Top=-1;
        stackTop = NULL;
        }
    }
};
int main(){
    Stack<int> my_stack;
    my_stack.print();
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    my_stack.push(40);
    my_stack.print();
    cout<<"Top element "<<my_stack.top()<<endl;
    cout<<my_stack.stackSize()<<endl;
    cout<<my_stack.pop()<<"pop element"<<endl;
    my_stack.print();
    my_stack.clear();
    ///////////////
    my_stack.push(3);
    my_stack.push(4);
    my_stack.print();
    cout<<my_stack.stackSize();
}