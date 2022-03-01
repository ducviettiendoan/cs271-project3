#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Element{
    private: 
        int key;
        T val;
    public:    
        // Element();        
        Element<T>* next;
        Element<T>* prev;
        Element(int, T);
        //create Destructor!!!
        ~Element();
        int get_key();
        T get_value();
};

template<typename T>
Element<T>::Element(int k, T value){
    key = k;
    val = value;
}
template<typename T>
Element<T>::~Element(){
    cout<<"Delete element with "<<"Key: "<<key<<" and Value: "<<val<<endl;
    next = nullptr;
    prev = nullptr;
    key = -1;
}

template<typename T>
int Element<T>::get_key(){
    return key;
}

template<typename T>
T Element<T>::get_value(){
    return val;
}


