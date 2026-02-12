#include <iostream> 
// include map 
#include <map> 

using namespace std;

int main(){
    map<string, int> people = {{"Pankaj" , 23}, {"Alok", 54}}; 
    
    //  accessing data with key
    cout << people["Pankaj"] << "\n";  // 23
    cout << people["Alok"]; 

    // access data with .at() function 
    cout << "\n" << people.at("Pankaj"); 

    /*The .at() function is often preferred
    over square brackets [] because it throws
    an error message if the element does not 
    exist:
    */

    // Change value 
    people.at("Pankaj") = 90; 
    cout << "\n" << people.at("Pankaj");

    // Add element 
    people["Arun"] = 43; 
    cout << "\n" << people.at("Arun"); 
    // Check exist of not
    cout << "\n" << people.count("Pankaj"); 
}
