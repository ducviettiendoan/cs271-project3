#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <sstream> 
#include <typeinfo>
#include<cmath>
using namespace std;

long long setBitNumber(long long n)
{
    if (n == 0)
        return 0;
 
    long long msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}

void printVector(vector< vector<string> > content){
    for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
		}
		cout<<"\n";
	}
}

vector< vector<string> >readCSV(string filePath){
    vector< vector<string> > content;
	vector<string> row;
	string line, word;
 
	fstream file (filePath, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
			stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
    return content;
}

vector<int> decToBinary(long long n) 
{ 
    // array to store binary number 
	vector<int> binaryNum;
  
    // counter for binary array 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum.push_back((int)(n % 2)); 
        n = n / 2; 
    } 
    vector<int>returnBinary;
    for (int i = binaryNum.size()-1; i>=0; i--){
        returnBinary.push_back(binaryNum[i]);
    }
	return returnBinary;
} 

int binaryToDec(vector<int> binarySeries){
    int returnNum = 0;
    int curr = -1;
    for (int i = binarySeries.size()-1; i>=0; i--){
        curr = binarySeries.size()-1 - i;
        returnNum += pow(2,curr)*binarySeries[i];
    }
    return returnNum;
}