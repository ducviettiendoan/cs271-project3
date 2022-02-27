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
        Element(int, T);
        int get_key();
        T get_value();
};

// template<typename T>
// Element<T>::Element(){

// }
template<typename T>
Element<T>::Element(int k, T value){
    key = k;
    val = value;
}

template<typename T>
int Element<T>::get_key(){
    return key;
}

template<typename T>
T Element<T>::get_value(){
    return val;
}
