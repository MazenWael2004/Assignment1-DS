#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct node
{
    T info;
    node<T> *next;
    node<T> *prev;
    node(T data){
        info=data;
        next= NULL;
        prev= NULL;
    }
};
template <typename T>
class doublyLinkedList {
    node<T>*Head;
    node<T>*Tail;
    int count;
public:
    doublyLinkedList(): Head(NULL) ,Tail(NULL), count(0){
    }
   void insertAtHead (T element){
        node<T>*newNode=new node(element);
       if (Head!=NULL){
           newNode->prev=NULL;
           newNode->next=Head;
           Head->prev=newNode;
       }
       Head= newNode;
       Tail=newNode;
       count++;
    }
    void insertAtTail (T element) {
        if (Head==NULL){
            insertAtHead(element);
        } else{
            node<T>*newNode=new node(element);
            node<T>*temp=Head;
            while (temp->next!=NULL){
               temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next=NULL;
            Tail=newNode;
            count++;


        }
    }
   void insertAt (T element, int index){
       if (index < 0 || index > count) {
           cout << "Invalid index\n";
           return;
       }

       if (index == 0) {
           insertAtHead(element);
       } else if (index == count) {
           insertAtTail(element);
       }
       else{
           node<T>* newNode = new node(element);
           node<T>* temp = Head;
           int c=0;
           while (temp->next!=NULL && c!=index){
               temp = temp->next;
               c++;
           }
           if (c==index){
               temp->prev->next=newNode;
               newNode->prev=temp->prev;
               newNode->next=temp;
               temp->prev=newNode;
           }
           count++;
       }
    }
    void removeAtHead () {
        if (Head==NULL) return;
        node<T>* temp = Head;
        if (temp->next==NULL){
            Head=NULL;
            Tail=NULL;
        } else{
            Head=Head->next;
            Head->prev=NULL;
        }
        delete temp;
        count--;

    }
    void removeAtTail (){
        if (Head==NULL) return;
        if (Head->next==NULL){
            Head=NULL;
            Tail=NULL;
        }
        node<T>* temp = Head;
        while (temp->next!=NULL){
            temp= temp->next;
        }
        temp->prev->next=NULL;
        Tail=temp;
        delete temp;
        count--;
    }
    void removeAt (int index){
        if (index < 0 || index > count) {
            cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            removeAtHead();
        } else if (index == count) {
           removeAtTail();
        } else{
            node<T>* temp = Head;
            int c=0;
            while (temp->next!=NULL && c!=index){
                temp = temp->next;
                c++;
            }
            if (index==c){
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;

            }
            delete temp;

        }

    }
    T retrieveAt (int index){
        node<T>* temp = Head;
        int c=0;
        while (temp->next!=NULL && c!=index){
            temp = temp->next;
            c++;
        }
        if (c==index){
            return temp->info;
        } else
            cout<<"Invalid index\n";

    }
    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= count) {
            cout << "Invalid index\n";
            return false;
        }
        node<T>* temp = Head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return (temp->info == element);
    }
    bool isExist(T element) {
        node<T>* temp = Head;
        while (temp != NULL) {
            if (temp->info == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= count) {
            cout << "Invalid index\n";
            return;
        }

        node<T>* temp = Head;
        int c = 0;
        while (temp->next != NULL && c != index) {
            temp = temp->next;
            c++;
        }

        if (c == index) {
            temp->info = newElement;
        }
    }
    void print(){
        node<T>* temp = Head;
        while (temp != NULL) {
            cout<<temp->info<<" ";
            temp = temp->next;
        }
    }
    bool isEmptyList()
    {
        return (Head == NULL);
    }
   int linkedListSize () {
       return count;
    }
    void clear() {
        node<T>* current = Head;
        while (current != NULL) {
            node<T>* next = current->next;
            delete current;
            current = next;
        }
        Head = NULL;
        Tail = NULL;
        count = 0;
    }
    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= count || secondItemIdx < 0 || secondItemIdx >= count) {
            cout << "Invalid indices\n";
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            cout << "Indices are the same\n";
            return;
        }

        node<T>* firstNode = Head;
        node<T>* secondNode = Head;
        int c = 0;
        while (c != firstItemIdx) {
            firstNode = firstNode->next;
            c++;
        }
        c = 0;
        while (c != secondItemIdx) {
            secondNode = secondNode->next;
            c++;
        }

        if (firstNode->next == secondNode) {
            if (firstNode->prev != NULL) {
                firstNode->prev->next = secondNode;
            } else {
                Head = secondNode;
            }
            if (secondNode->next != NULL) {
                secondNode->next->prev = firstNode;
            } else {
                Tail = firstNode;
            }
            firstNode->next = secondNode->next;
            secondNode->prev = firstNode->prev;
            firstNode->prev = secondNode;
            secondNode->next = firstNode;
        }  else {
            node<T>* temp = firstNode->prev;
            firstNode->prev = secondNode->prev;
            secondNode->prev = temp;

            temp = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = temp;

            if (firstNode->next != NULL) {
                firstNode->next->prev = firstNode;
            } else {
                Tail = firstNode;
            }
            if (secondNode->next != NULL) {
                secondNode->next->prev = secondNode;
            } else {
                Tail = secondNode;
            }

            if (firstNode->prev != NULL) {
                firstNode->prev->next = firstNode;
            } else {
                Head = firstNode;
            }
            if (secondNode->prev != NULL) {
                secondNode->prev->next = secondNode;
            } else {
                Head = secondNode;
            }
        }
    }

};
int main() {
    doublyLinkedList<int> myList;

    myList.insertAtHead(5);
    myList.insertAtTail(10);
    myList.insertAt(7, 1);

    cout << "List after insertion: ";
    myList.print();
    cout << endl;


    if (myList.isExist(10)) {
        cout << "10 exists in the list.\n";
    } else {
        cout << "10 does not exist in the list.\n";
    }

    myList.removeAt(1);


    cout << "List after removal: ";
    myList.print();
    cout << endl;

    int element = myList.retrieveAt(0);
    cout << "Element at index 0: " << element << endl;

    myList.replaceAt(15, 0);

    cout << "List after replacement: ";
    myList.print();
    cout << endl;


    myList.swap(0, 1);


    cout << "List after swapping: ";
    myList.print();
    cout << endl;


    myList.clear();


    if (myList.isEmptyList()) {
        cout << "List is empty.\n";
    } else {
        cout << "List is not empty.\n";
    }


    return 0;
}
