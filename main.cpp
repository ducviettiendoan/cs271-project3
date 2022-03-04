#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <sstream> 
#include <typeinfo>
#include<string>
#include "hashtable.cpp"
using namespace std;

template<typename T>
HashTable<T>createHashTableFromCSV(string csv){
	vector< vector<string> >contentCSV = readCSV(csv);
    long long size = (long long) contentCSV.size();
    HashTable<T> hashmap = HashTable<T>(size);
    for (int i=0; i<contentCSV.size(); i++){
        string userName = contentCSV[i][0];
        long long password = stoll(contentCSV[i][1]); //check this line!!! causing error 
        Element<T> *account = new Element<T>(password,userName);
        hashmap.insertItem(account);
    }
	return hashmap;
}

int main(){
	HashTable<string>hashmap = createHashTableFromCSV<string>("logins.csv");
	hashmap.printHashMap();
	// long long password;
	// string username;
	// cout<<"Please enter a username to login: "<<endl;
	// cin>>username;
	// cout<<"Please enter a password to login: "<<endl;
	// cin>>password;
	// if (hashmap.searchItem(password) && username.compare(hashmap.searchItem(password)->get_value()) == 0){
	// 	cout<<"You are logged in with username: "<<hashmap.searchItem(password)->get_value()<<endl;
	// }
	// else{
	// 	cout<<"User does not exist! Please check your password or username again."<<endl;
	// }
}
