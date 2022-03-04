#include <iostream>
#include "element.cpp"
#include "utility.cpp"
#include <typeinfo>
#include <cmath>
#include <bitset>
using namespace std;

// Doubly Linked List for collision problem
template <typename T>
class DoublyLinkedList
{
public:
    Element<T> *head;
    Element<T> *tail;
    DoublyLinkedList();
    DoublyLinkedList(Element<T> *);
    void addElement(Element<T> *);
    Element<T> *searchElement(long long key); // could change back to int
    void deleteElement(Element<T> *);
    void traverse();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(Element<T> *firstElement)
{
    head = firstElement;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::addElement(Element<T> *newElement)
{
    if (!head)
    {
        head = newElement;
        tail = newElement;
        // cout<<"Added"<<endl;
        return;
    }
    newElement->next = head;
    head->prev = newElement;
    head = newElement;
}

template <typename T>
void DoublyLinkedList<T>::traverse()
{
    Element<T> *curr = head;
    if (!curr)
    {
        return;
    }
    while (curr != tail)
    {
        cout << curr->get_key() << " : " << curr->get_value() << endl;
        curr = curr->next;
    }
    if (tail)
    {
        cout << tail->get_key() << " : " << tail->get_value() << endl;
    }
}

template <typename T>
Element<T> *DoublyLinkedList<T>::searchElement(long long key)
{ // try long could change back to int
    Element<T> *curr = head;
    while (curr)
    {
        if (curr->get_key() == key)
        {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

template <typename T>
void DoublyLinkedList<T>::deleteElement(Element<T> *target)
{
    Element<T> *curr = head;
    while (curr)
    {
        if (curr == target)
        {
            if (curr == head)
            {
                (curr->next)->prev = nullptr;
                head = curr->next;
            }
            else if (tail == target)
            {
                (curr->prev)->next = nullptr;
                curr->prev = tail;
            }
            else
            {
                (curr->prev)->next = curr->next;
                (curr->next)->prev = curr->prev;
            }
            break;
        }
        curr = curr->next;
    }
    delete curr;
}

// Build a HashMap
template <typename T>
class HashTable
{
public:
    int size; // back to int later plz
    // arr of element(not pointer)
    DoublyLinkedList<T> *arr;
    HashTable(int);
    // Cormen's Method
     int hashFunction(long long);
    void insertItem(Element<T> *);
    void deleteItem(Element<T> *);
    Element<T> *searchItem(long long key);
    void printHashMap();
};

template <typename T>
HashTable<T>::HashTable(int s)
{
    size = s;
    // create an array of Elements (not pointer)
    arr = new DoublyLinkedList<T>[s];
}

// template<typename T>
// int HashTable<T>::hashFunction(long long key){
//     // cout<<"Key: "<<typeid(key).name()<<key<<" size: "<<typeid(size).name()<<" Remainder: "<<key%size<<endl;
//     long long sizeLong = (long long)size;
//     int hashKey = int(key%sizeLong);
//     return hashKey;
// }

// Most significant bits
template <typename T>
int HashTable<T>::hashFunction(long long key)
{
    int hashKey;
    vector<int> binary = decToBinary(key);
    vector<int> pMostSignificantBits;
    for (int i = 0; i < 6; i++)
    {
        if (i<binary.size()){
            pMostSignificantBits.push_back(binary[i]);
        }
        else{
            pMostSignificantBits.insert(pMostSignificantBits.begin(),0);
        }
    }

    hashKey = binaryToDec(pMostSignificantBits);
    return hashKey;
}

// Cormen Method
// template<typename T>
// int HashTable<T>::hashFunction(long long key){
//     double A = (pow(5,0.5)-1)/2;
//     double x = A*key;
//     double fractionX = x - (long long)x;
//     // cout<<"fraction: "<<fractionX<<endl;
//     int hashKey = (int)(fractionX*pow(2,6));  //since 64 is the nearest power of 2 that < 100 (size of csv)
//     return hashKey;
// }

//

template <typename T>
void HashTable<T>::insertItem(Element<T> *newElement)
{
    int keyEle = hashFunction(newElement->get_key()); // back to int later
    arr[keyEle].addElement(newElement);
}

template <typename T>
void HashTable<T>::printHashMap()
{
    for (int i = 0; i < size; i++)
    { // change to int later plzz
        cout << "At index:" << i << endl;
        (arr[i]).traverse();
    }
}

template <typename T>
Element<T> *HashTable<T>::searchItem(long long key)
{ // could change back to int later
    int hashKey = hashFunction(key);
    Element<T> *returnElement = arr[hashKey].searchElement(key);
    // cout<<"Key: "<<returnElement->get_key()<<" "<<"Value: "<<returnElement->get_value()<<endl;
    if (returnElement)
    {
        return returnElement;
    }
    return nullptr;
}

template <typename T>
void HashTable<T>::deleteItem(Element<T> *toBeDelete)
{
    int hashKey = hashFunction(toBeDelete->get_key()); // change back to int later
    arr[hashKey].deleteElement(toBeDelete);
}