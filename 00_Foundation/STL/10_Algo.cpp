#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std; 

void printDouble(int a){
    cout << 2*a << " "; 
}

bool checkEven(int a ){
    return a%2 == 0; 
}

int main(){
    vector <int> arr = {15,65,25,78,25,15,32,25}; 
    /*
    // For Each 
    for_each(arr.begin(), arr.end(), printDouble);
    cout << endl;
    // Find 
    int target = 65; 
    auto it = find(arr.begin(), arr.end(), target);
    if(it == arr.end())  cout << "Not Exist";
    else cout << "Exist" << endl;

    

    // Find if // Return first element which satisfies the criteria  
    auto it = find_if(arr.begin(), arr.end(), checkEven); 
    cout << *it; 

   

    int target = 25;
    int frequency = count(arr.begin(), arr.end(), target); 
    cout << "Frequency : " << frequency << endl; 
    

    // count number of elements that satisfies criteria  
    int ans = count_if(arr.begin(), arr.end(), checkEven); 
    cout << ans << endl; // 2
    

    sort(arr.begin(), arr.end()); 
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl; 
    

    reverse(arr.begin(), arr.end());
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl; 
    

    cout << "Before Rotating : ";
    for(auto ele : arr){
        cout << ele << " ";
    }
    cout << endl; 
    rotate(arr.begin(), arr.begin()+3, arr.end()); 

    cout << "After Rotating : "; 
    for(auto ele : arr){
        cout << ele << " ";
    }
    cout << endl; 
    */


    // Remove duplicate elements 
    auto it = unique(arr.begin(), arr.end()); 
    /*
    It iterator k phle saara unique element hai
    It k baad saare duplicate element hai
    */
    arr.erase(it, arr.end()); 
    for(int a : arr){
        cout << a << " "; 
    }
    cout << endl; 

}