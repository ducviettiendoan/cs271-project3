#include<iostream>
#include "element.cpp"
using namespace std;

//Doubly Linked List for collision problem
template<typename T>
class DoublyLinkedList{
    public:
        Element<T>* head;
        DoublyLinkedList();
        DoublyLinkedList(Element<T>*);
        void addElement(Element<T>*);
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
        void searchItem(int key);
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

int main(){
    //create 5 Elements type double:
    Element<double>* e1 = new Element<double>(0,12.6);
    Element<double>* e2 = new Element<double>(1,2.4);
    Element<double>* e3 = new Element<double>(2,78.5);
    Element<double>* e4 = new Element<double>(6,11.9);
    Element<double>* e5 = new Element<double>(7,34.1);
    //create HashTable size 5
    HashTable<double> hashmap = HashTable<double>(5);
    hashmap.insertItem(e1);
    hashmap.insertItem(e2);
    hashmap.insertItem(e3);
    hashmap.insertItem(e4);
    hashmap.insertItem(e5);
    hashmap.printHashMap();
    return 0;
}