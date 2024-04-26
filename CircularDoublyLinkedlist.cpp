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
class DoubleCircularLinkedList {
    node<T> *head;
    int size;

public:
    DoubleCircularLinkedList() : head(nullptr), size(0) {}

    void insertAtHead(T element) {
        node<T> *newNode = new node<T>(element);
        if (head != nullptr) {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        } else {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        size++;
    }

    void insertAtTail(T element) {
        if (head == nullptr) {
            insertAtHead(element);
            return;
        }
        node<T> *newNode = new node<T>(element);
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            node<T> *newNode = new node<T>(element);
            node<T> *temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    }

    void removeAtHead() {
        if (isEmpty()) return;
        node<T> *temp = head;
        if (size == 1) {
            head = nullptr;
        } else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        delete temp;
        size--;
    }

    void removeAtTail() {
        if (isEmpty()) return;
        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            node<T> *temp = head->prev;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
        size--;
    }

    void removeAt(int index) {
        if (isEmpty() || index < 0 || index >= size) return;
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == size - 1) {
            removeAtTail();
            return;
        }
        node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    void print() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        node<T> *temp = head;
        do {
            cout << temp->info << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    T retrieveAt(int index) {
        if (isEmpty() || index < 0 || index >= size) {
            cout << "Index out of range\n";
            return T();
        }
        node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->info;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return false;
        }
        node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return (temp->info == element);
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->info = newElement;
    }

    bool isExist(T element) {
        if (isEmpty()) return false;
        node<T> *temp = head;
        do {
            if (temp->info == element) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    int linkedListSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            removeAtHead();
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size|| secondItemIdx < 0 || secondItemIdx >= size) {
            cout << "Invalid indices\n";
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            cout << "Indices are the same\n";
            return;
        }

        node<T>* firstNode = head;
        node<T>* secondNode = head;
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
                head = secondNode;
            }
            if (secondNode->next != NULL) {
                secondNode->next->prev = firstNode;
            } else {
                tail = firstNode;
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
                tail = firstNode;
            }
            if (secondNode->next != NULL) {
                secondNode->next->prev = secondNode;
            } else {
                tail = secondNode;
            }

            if (firstNode->prev != NULL) {
                firstNode->prev->next = firstNode;
            } else {
                head = firstNode;
            }
            if (secondNode->prev != NULL) {
                secondNode->prev->next = secondNode;
            } else {
                head = secondNode;
            }
        }
    }
};

int main() {
    DoubleCircularLinkedList<int> cll;
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
    cll.insertAt(200, 3);
    cll.print();
    cll.insertAt(200, 10);
    cll.print();
    cll.removeAtHead();
    cll.print();
    cll.removeAtTail();
    cll.print();
    cout << boolalpha << cll.isExist(200) << endl;
    cout << boolalpha << cll.isExist(23) << endl;
    cll.removeAt(1);
    cll.print();
    cout << cll.retrieveAt(2) << endl;
    cll.replaceAt(16, 3);
    cll.print();
    cout << boolalpha << cll.isItemAtEqual(8, 2) << endl;
    cout << boolalpha << cll.isItemAtEqual(9, 2) << endl;
    cll.swap(1, 3);
    cll.print();
    cout << cll.linkedListSize() << endl;
    cll.clear();
    cout << cll.linkedListSize() << endl;

    return 0;
}
