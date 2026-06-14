#include <iostream> 
#include <string>   
#include <bits/stdc++.h> 
using namespace std; 

void printName5Time(string name, int cnt){
    if(cnt == 0) return ; 
    printName5Time(name, cnt-1); 
    cout << cnt << " : "<< name << endl; 
}

int main(){
    string name = "pankaj";
    printName5Time(name,5); 
    return 0; 
}