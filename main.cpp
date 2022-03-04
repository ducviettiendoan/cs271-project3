#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <sstream> 
#include <typeinfo>
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
	// hashmap.printHashMap();
	long long password;
	cout<<"Please enter a password to login: "<<endl;
	cin>>password;
	if (hashmap.searchItem(password)){
		cout<<"You are logged in with username: "<<hashmap.searchItem(password)->get_value()<<endl;
	}
	else{
		cout<<"User does not exist! Please check your password again."<<endl;
	}
}
