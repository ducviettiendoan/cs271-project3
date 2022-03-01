#include<iostream>
#include "element.cpp"
using namespace std;

//Doubly Linked List for collision problem
template<typename T>
class DoublyLinkedList{
    public:
        Element<T>* head;
        Element<T>* tail;
        DoublyLinkedList();
        DoublyLinkedList(Element<T>*);
        void addElement(Element<T>*);
        Element<T>* searchElement(int key);
        void deleteElement(Element<T>*);
        void traverse();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(Element<T>* firstElement){
    head = firstElement;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::addElement(Element<T> *newElement){
    if (!head){
        head = newElement;
        tail = newElement;
        return;
    }
    newElement -> next = head;
    head -> prev = newElement;
    head = newElement;
}

template<typename T>
void DoublyLinkedList<T>::traverse(){
    Element<T>* curr = head;    
    while (curr){
        cout<<curr -> get_key()<<" : "<<curr->get_value()<<endl;
        curr = curr -> next;
    }
}

template<typename T>
Element<T>* DoublyLinkedList<T>::searchElement(int key){
    Element<T>* curr = head;
    while(curr){
        if (curr -> get_key() == key){
            break;
        }
        curr = curr -> next;
    }
    return curr;
}

template<typename T>
void DoublyLinkedList<T>::deleteElement(Element<T>* target){
    Element<T>* curr = head;
    while(curr){
        if (curr == target){
            if (curr == head){
                (curr -> next)->prev = nullptr;
                head = curr -> next;
            }
            else if (tail == target){
                (curr -> prev) -> next = nullptr;
                curr -> prev = tail;
            }
            else{
                (curr -> prev) -> next = curr -> next;
                (curr -> next) -> prev = curr -> prev;
            }
            break;
        }
        curr = curr -> next;
    }
    delete curr;
}

//Build a HashMap
template<typename T>
class HashTable{
    public:
        int size;
        //arr of element(not pointer)
        DoublyLinkedList<T>* arr;
        HashTable(int);
        int hashFunction(int);
        void insertItem(Element<T>*);
        void deleteItem(Element<T>*);
        T searchItem(int key);
        void printHashMap();
};

template<typename T>
HashTable<T>::HashTable(int s){
    size = s;
    //create an array of Elements (not pointer)
    arr = new DoublyLinkedList<T>[s];
}

template<typename T>
int HashTable<T>::hashFunction(int key){
    return key% size;
}

template<typename T>
void HashTable<T>::insertItem(Element<T>* newElement){
    int keyEle = hashFunction(newElement->get_key());
    // cout<<"Hash key:"<<keyEle<<endl;
    arr[keyEle].addElement(newElement);
}

template<typename T>
void HashTable<T>::printHashMap(){
    for (int i=0; i<size; i++){
         cout<<"At index:"<<i<<endl;
        (arr[i]).traverse();
    }
}

template<typename T>
T HashTable<T>::searchItem(int key){
    int hashKey = hashFunction(key);    
    Element<T>* returnElement = arr[hashKey].searchElement(key);
    cout<<"Key: "<<returnElement->get_key()<<" "<<"Value: "<<returnElement->get_value()<<endl;
    return returnElement->get_value();
}

template<typename T>
void HashTable<T>::deleteItem(Element<T>* toBeDelete){
    int hashKey = hashFunction(toBeDelete->get_key());
    arr[hashKey].deleteElement(toBeDelete);
}   