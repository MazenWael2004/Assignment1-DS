#include <bits/stdc++.h>
using namespace std;
template <class Type>
struct Node{
    Type Value;
    Node<Type>* Next;
};
template <class Type>
struct CircularLinkedList {
private:
    Node<Type>* head;
    Node<Type>* tail;
    int size;
public:
    CircularLinkedList() : head(nullptr),tail(nullptr), size(0) {}
    void insertAtHead(Type element){
        Node<Type>* NewNode =new Node<Type>;
        NewNode->Value=element;
        if(isEmpty()){
            NewNode->Next = NewNode;
            head = NewNode;
            tail = NewNode;
        }else{
            NewNode->Next = head;
            tail->Next = NewNode;
            head = NewNode;
        }
        size++;
    }
    void insertAtTail(Type element){
        Node<Type>* NewNode =new Node<Type>;
        NewNode->Value=element;
        if (isEmpty()){
            NewNode->Next = NewNode;
            head = NewNode;
            tail = NewNode;
        }else{
            NewNode->Next=head;
            tail->Next=NewNode;
            tail=NewNode;
        }
        size++;

    }
    void insertAt(Type element,Type index){
        if (index<0||index>size){cout<<"OUT OF RANGE"<<endl;return;}
        else if (index==0){insertAtHead(element);}
        else if (index==size){insertAtTail(element);}
        else{
            Node<Type>* NewNode =new Node<Type>;
            NewNode->Value=element;
            Node<Type>* Tmp=head;
            for(int i=0;i<index-1;i++){
                Tmp=Tmp->Next;
            }
            NewNode->Next=Tmp->Next;
            Tmp->Next=NewNode;
            size++;
        }

    }
    void removeAtHead (){
        if (isEmpty()){cout<<"THE LIST IS EMPTY";}
        else if (size==1){
            delete head;
            head= nullptr;
            size--;}
        else{
            Node<Type>* Tmp=head;
            head=head->Next;
            delete Tmp;
            size--;
        }
    }
    void removeAtTail () {
        if (isEmpty()) { cout << "THE LIST IS EMPTY"; }
        else if (size == 1) {
            delete tail;
            tail = nullptr;
            size--;
        } else {
            Node<Type>* Tmp = head;
            while (Tmp->Next != tail) {
                Tmp = Tmp->Next;
            }
            delete tail;
            tail = Tmp;
            tail->Next = head;
            size--;
        }
    }
    void removeAt (Type index){
        if (isEmpty()) {
            cout << "THE LIST IS EMPTY";
            return;}
        else if (size==1){
            delete head;
            head= nullptr;
            size--;}
        else if (index==0){removeAtHead();}
        else if (index==size-1){removeAtTail();}
        else{
            Node<Type>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->Next;
            }
            Node<Type>* Tmp = current->Next;
            current->Next = current->Next->Next;
            delete Tmp;
            size--;
        }
    }
    Type retrieveAt(Type index){
        if (index < 0 || index >= size) {
            cout << "out of range" << endl;
            return Type();}
        Node<Type>* Tmp = head;
        for (int i = 0; i < index; i++) {
            Tmp = Tmp->Next;
        }
        return Tmp->Value;
    }
    void replaceAt(Type newelement ,int index){
        if (index < 0 || index >= size) {
            cout << "OUT OF RANGE" << endl;
            return ;}
        else if (index ==0 ){head->Value=newelement;}
        else if( index == size-1 ){tail->Value = newelement;}
        else{
            Node<Type> *Tmp;
            Tmp = head;
            for(int i = 0 ; i<index ; i++)
                Tmp=Tmp->Next;
            Tmp->Value=newelement;}
    }
    bool isExist(Type element){
        Node<Type> *current;
        current = head;
        for(int i =0; i<size; i++){
            if(current->Value==element)
                return true ;
            else{
                current = current->Next;
            }
        }
        return false;
    }
    bool isItemAtEqual (Type element, int index){
        return retrieveAt(index) == element;}
    bool isEmpty(){
        return size==0;
    }
    int LinkedListSize(){
        return size;
    }
    void clear() {
        while (head!= nullptr) {
            removeAtHead();
        }
    }
    void print() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node<Type>* temp = head;
        for (int i = 0; i < size; i++) {
            cout << temp->Value << " ";
            temp = temp->Next;
        }
        cout << endl;

    }
};
int main (){
    CircularLinkedList <int> cll;
    cll.insertAtHead(2);
    cll.print();
    cll.insertAtHead(4);
    cll.print();
    cll.insertAtTail(6);
    cll.print();
    cll.insertAtTail(8);
    cll.print();
    cll.insertAtTail(10);
    cll.print();
    cll.insertAtTail(12);
    cll.print();
    cll.insertAtTail(14);
    cll.print();
    cll.insertAt(200,3);
    cll.print();
    cll.insertAt(200,10);
    cll.print();
    cll.removeAtHead();
    cll.print();
    cll.removeAtTail();
    cll.print();
    cout<<boolalpha<<cll.isExist(200)<<endl;
    cout<<boolalpha<<cll.isExist(23)<<endl;
    cll.removeAt(1);
    cll.print();
    cout <<cll.retrieveAt(2)<<endl;
    cll.replaceAt(16,3);
    cll.print();
    cout << boolalpha<<cll.isItemAtEqual(8,2)<<endl;
    cout << boolalpha<<cll.isItemAtEqual(9,2)<<endl;
    cout<<  cll.LinkedListSize()<<endl;
    cll.clear();
    cout<<  cll.LinkedListSize()<<endl;




}
