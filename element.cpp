#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Element{
    private: 
        long long key;
        T val;
    public:    
        // Element();        
        Element<T>* next;
        Element<T>* prev;
        Element(long long, T);  //change to int later plxx
        //create Destructor!!!
        ~Element();
        long long get_key();
        T get_value();
};

template<typename T>
Element<T>::Element(long long k, T value){  //change k to int later
    key = k;
    val = value;
}
template<typename T>
Element<T>::~Element(){
    next = nullptr;
    prev = nullptr;
    key = -1;
}

template<typename T>
long long Element<T>::get_key(){
    return key;
}

template<typename T>
T Element<T>::get_value(){
    return val;
}


