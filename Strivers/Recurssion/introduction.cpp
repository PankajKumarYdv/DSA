#include <iostream> 
#include <vector>
using namespace std; 

class Recursion{
    public: 
    
    int factorial(int n){
        // base condition 
        if(n==0){
            return 1; 
        }
        return n * factorial(n-1); 
    }

    void name(int n){
        if(n==0) return; 
        cout << n << " Hey pankaj"  << endl; 
        name(n-1); 
    }

    void evenOnly(vector<int>& v, int n){
        if(n<0) return; 
        evenOnly(v,n-1); 
        if(v[n]%2 == 0) cout << v[n] << " is Even" << endl; 
    }

};

int main(){
    Recursion r; 
    int choice = 3; 
    
    // Factorial 
    switch(choice){
        case 1: 
            int n; 
            cout << "Enter a number : " << endl; 
            cin >> n;
            cout << "Factorial of " << n << " is : " << r.factorial(n) << endl; 
            break; 

        case 2: 
            r.name(5); 
            break; 
        
        case 3: 
            vector <int> v = {1,8,3,4,9,12,77,64}; 
            r.evenOnly(v,v.size()-1); 
            break; 

    }

    // 
}