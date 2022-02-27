#include<iostream>
#include "element.cpp"
using namespace std;

int main(){
    Element<double> newEle = Element<double>(0,15.5);
    cout<<newEle.get_key()<<endl;
    cout<<newEle.get_value()<<endl;
    return 0;
}