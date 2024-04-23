//
// Created by HP on 21/04/2024.
//
#include <bits/stdc++.h>
using namespace std;
template < class Type>
struct Node{
    Type item;
    Node<Type> *Next;
};

template<class Type>
class LinkedList{
private:
    int length;
    Node<Type> *Head;
    Node<Type> *Tile;
public:
    LinkedList(){
        length = 0;
        Head = NULL;
        Tile = NULL;
    }
    bool isEmpty(){
        if(length==0)
            return true;
        else
            return false;
    }
    void insertAtHead(Type element){
        Node<Type> *NewNode;
        NewNode = new Node<Type> ;
        NewNode->item = element ;
        if(isEmpty())
        {
            NewNode->Next = NULL ;
            Head = NewNode ;
            Tile = NewNode ;
        }
        else{
            NewNode->Next = Head ;
            Head = NewNode ;
        }
        length++;
    }
    void insertAtTile(Type element){
        Node<Type> *NewNode;
        NewNode = new Node<Type> ;
        NewNode->item = element ;
        if(isEmpty())
        {
            NewNode->Next = NULL ;
            Head = NewNode ;
            Tile = NewNode ;
        }
        else{
            NewNode->Next = NULL;
            Tile->Next=NewNode;
            Tile = NewNode;
        }
        length++;
    }
    void insetAt( Type element , int Pos){
        Node<Type> *NewNode;
        NewNode = new Node<Type> ;
        NewNode->item = element ;
        if(Pos<0 || Pos>length)
            cout<<"Out Of Range";
        else if(Pos==0)
            insertAtHead(element);
        else if(Pos==length)
            insertAtTile(element);
        else{
            Node<Type> *current;
            current=Head;
            for(int i = 1;i < Pos; i++){
                current=current->Next;
            }
            NewNode->Next=current->Next;
            current->Next=NewNode;
            length++;
        }
    }
    void RemoveAtHead(){
        if(isEmpty())
            cout<<"List Is Empty";
        else if(length == 1){
            delete Head;
            Head = NULL;
            length--;
        }
        else{
            Node<Type> *current;
            current=Head;
            Head=Head->Next;
            delete current;
            length--;
        }
    }
    void RemoveAtTile(){
        if(isEmpty())
            cout<<"List Is Empty";
        else if(length == 1){
            delete Head;
            Head = NULL;
            length--;
        }
        else{
            Node<Type> *current;
            current = Head;
            for(int i = 1; i < length-1 ; i++)
                current = current->Next;
            Tile =current;
            current = current->Next;
            delete current;
            Tile->Next = NULL;
            length--;
        }
    }
    void RemoveAt( int pos){
        if(isEmpty())
            cout<<"List Is Empty";
        else if(length == 1){
            delete Head;
            Head = NULL;
            length--;
        }
        else if( pos == 0)
            RemoveAtHead();
        else if( pos ==length-1)
            RemoveAtTile();
        else{
            Node<Type> *current,*index;
            current = Head;
            index = Head->Next;
            for(int i = 1 ; i < pos ; i++){
                current = current->Next;
                index = index->Next;
            }
            current->Next = index->Next;
            delete index;
            length--;
        }
    }

    Type RetrieveAt (int pos){
        if( pos == 0 )
            return Head->item;
        else if( pos == length-1 )
            return Tile->item;
        else if( pos < 0 || pos >= length)
            cout<<"Out Of Range";
        else{
            Node<Type> *current;
            current = Head;
            for(int i = 1 ; i<=pos ; i++)
                current=current->Next;
            return current->item;
        }
    }
    void ReplaceAt(Type NewElement ,int pos){
        if( pos == 0 )
             Head->item = NewElement;
        else if( pos == length-1 )
             Tile->item = NewElement;
        else if( pos < 0 || pos >= length)
            cout<<"Out Of Range";
        else
        {
            Node<Type> *current;
            current = Head;
            for(int i = 1 ; i<=pos ; i++)
                current=current->Next;
             current->item=NewElement;
        }
    }
    bool isExist(Type element){
        Node<Type> *current;
        current = Head;
        for(int i =0; i<length; i++){
            if(current->item==element)
                return true ;
            else{
                current = current->Next;
            }
        }
        return false;
    }
    bool isItemAtEqual( Type element , int pos){
        if(pos == 0)
            return (Head->item == element);
        else if( pos == length-1 )
            return(Tile->item == element);
        else if( pos < 0 || pos >= length)
            cout<<"Out Of Range";
        else{
            Node<Type> *current;
            current = Head;
            for(int i = 1 ; i<=pos ; i++)
                current = current->Next;
            return (current->item==element);
        }
        return false;
    }
    void swap (int firstItemIdx, int secondItemIdx){
        if(firstItemIdx == secondItemIdx)
            return;
        else if(firstItemIdx==0 || secondItemIdx==0){
            if(firstItemIdx==0){
                Node<Type> *index1,*index2 ,*prev2,*Temp;
                index1=prev2=Head;
                for(int i=1 ;i<secondItemIdx; i++)
                    prev2=prev2->Next;
                index2=prev2->Next;
                Temp= index2->Next;
                index2->Next=index1->Next;
                Head=index2;
                prev2->Next=index1;
                index1->Next=Temp;
            }
            else{
                Node<Type> *index1,*index2 ,*prev1,*Temp;
                index2=prev1=Head;
                for(int i=1 ;i<firstItemIdx; i++)
                    prev1=prev1->Next;
                index1=prev1->Next;
                Temp= index1->Next;
                index1->Next=index2->Next;
                Head=index1;
                prev1->Next=index2;
                index2->Next=Temp;
            }
        }
        else if(firstItemIdx==length-1 || secondItemIdx==length-1){
            if(secondItemIdx==length-1){
                Node<Type> *index1,*index2,*prev1,*prev2;
                index2=Tile;
                prev2=prev1=Head;
                for(int i=1 ; i<length-1;i++)
                    prev2=prev2->Next;
                for(int i= 1 ; i<firstItemIdx;i++)
                    prev1=prev1->Next;
                index1=prev1->Next;
                prev1->Next=index2;
                index2->Next=index1->Next;
                prev2->Next=index1;
                index1->Next=NULL;
                Tile= index1;
            }
            else{
                Node<Type> *index1,*index2,*prev1,*prev2;
                index1=Tile;
                prev1=prev2=Head;
                for(int i=1 ; i<length-1;i++)
                    prev1=prev1->Next;
                for(int i= 1 ; i<secondItemIdx;i++)
                    prev2=prev2->Next;
                index2=prev2->Next;
                prev2->Next=index1;
                index1->Next=index2->Next;
                prev1->Next=index2;
                index2->Next=NULL;
                Tile= index2;

            }

        }
        else{
            Node<Type> *index1 ,*prev1,*index2,*prev2,*Temp;
            prev1=prev2=Head;
            for(int i=1;i<firstItemIdx ;i++)
                prev1=prev1->Next;
            index1=prev1->Next;
            for(int i=1 ;i<secondItemIdx; i++)
                prev2=prev2->Next;
            index2=prev2->Next;
            prev1->Next=index2;
            Temp=index2->Next;
            index2->Next=index1->Next;
            prev2->Next=index1;
            index1->Next=Temp;

        }
    }
    int LinkedListSize(){
        return length;
    }
    void clear(){
        if(isEmpty())
            cout<<" List Is Empty"<<endl;
        else if(length==1){
            Node<Type> *current,*Temp;
            current=Head;
            delete current;
            Head=Tile=NULL;
            length=0;
        }
        else {
            Node<Type> *current,*Temp;
            current=Head;
            for(int i=0;i<length;i++){
                Temp=current->Next;
                delete current;
                current=Temp;
            }
            Head=Tile=NULL;
            length=0;
        }
    }
    void Print(){
        if(isEmpty())
            cout<<" List Is Empty"<<endl;
        Node<Type> *current;
        current = Head;
        for(int i = 0;i < length; i++){
            cout<<current->item<<" ";
            current=current->Next;
        }
        cout<<"length is "<<length<<endl ;
    }

};
int main(){
    LinkedList <int> List;
    List.Print();
    List.insertAtHead(10);
    List.insertAtTile(20);
    List.insertAtTile(30);
    List.insertAtTile(40);
    List.insertAtTile(50);
    List.Print();
    List.insertAtHead(5);
    List.Print();
    List.insetAt(25,3);
    List.Print();
    cout<<List.LinkedListSize()<<endl;
    List.RemoveAtHead();
    List.Print();
    List.RemoveAtTile();
    List.Print();
    List.insertAtTile(70);
    List.Print();
    List.RemoveAt(3);
    List.Print();
    cout<<List.RetrieveAt(3)<<endl;
    List.ReplaceAt(30,2);
    List.Print();
    cout<<List.isExist(110)<<endl;
    cout<<List.isItemAtEqual(40,4)<<endl;
    List.swap(1,1);
    List.Print();
    List.swap(0,3);
    List.Print();
    List.swap(3,0);
    List.Print();
    List.swap(2,4);
    List.Print();
    List.swap(4,2);
    List.Print();
    List.swap(1,3);
    List.Print();
    List.swap(3,1);
    List.Print();
    List.clear();
    List.Print();
}
