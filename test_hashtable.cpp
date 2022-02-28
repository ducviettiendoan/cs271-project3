#include<iostream>
using namespace std;
#include"hashtable.cpp"

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