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
    Element<double>* e6 = new Element<double>(11,99.2);
    //create HashTable size 6
    HashTable<double> hashmapTest = HashTable<double>(12);
    //insert Element object to hashtable
    hashmapTest.insertItem(e1);
    hashmapTest.insertItem(e2);
    hashmapTest.insertItem(e3);
    hashmapTest.insertItem(e4);
    hashmapTest.insertItem(e5);
    hashmapTest.insertItem(e6);
    //print hashmap after creating the table
    hashmapTest.printHashMap();
    //search for an Element object in the hashtable and return the value of the corresponding key
    cout<<hashmapTest.searchItem(7)->get_value()<<endl;
    //delete an object
    hashmapTest.deleteItem(e6);
    hashmapTest.printHashMap();
    return 0;
}