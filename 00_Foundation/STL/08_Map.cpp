#include <iostream> 
#include <map> 
#include <unordered_map> 
using namespace std; 

int main(){
    unordered_map<string, string> uom; 

    // inserting 
    uom["in"] = "India";  // 1. Method 
    uom.insert(make_pair("en", "england"));  // 2. Method 

    pair <string,string> p; 
    p.first = "br";
    p.second = "Brazil"; 
    uom.insert(p); 


    // getting each  value; 
    // for(auto it : uom) {
    //     cout << it.first << "->" << it.second << endl;
    // }

    unordered_map <string,string>::iterator it = uom.begin(); 
    while(it!=uom.end()){
        pair <string,string> p = *it; 
        cout << p.first << " "  << p.second << " " << endl; 
        it++; 
    }


    cout << "Size : " << uom.size() << endl ; // 3
    uom.clear(); 
    cout << "Size : " << uom.size() << endl;  // 0

}