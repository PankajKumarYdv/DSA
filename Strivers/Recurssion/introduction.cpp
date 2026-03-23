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

    int power(int n, int exp){
        if(exp == 0) return 1; 
        return n * power(n,exp-1); 
    }

    void fibonnacciNumber(int upto, int count, int a, int b){
        if(count == upto && a != 1 && b != 1){
            cout << a+b << endl; 
            return;
        } 
        if(count == 1){
            cout << "0 "; 
            count++;
        }
        if(count == 2){
            cout << "1 "; 
            a = 1;
            count++;
        }
        if(count == 3){
            cout << "1 ";
            b = 1;
            count++;
        }
        

        // 
        cout << a+b << " "; 
        count++;
        fibonnacciNumber(upto, count, b, a+b); 


    }

};

int main(){
    Recursion r; 
    int choice = 5; 
    int base; 
    int pow; 
    vector <int> v; 
    
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
            v = {1,8,3,4,9,12,77,64}; 
            r.evenOnly(v,v.size()-1); 
            break; 

        case 4: 
            base = 5; 
            pow = 80; 
            cout << base<<"^"<<pow <<  "is : " << r.power(base,pow) << endl; 
            break;
        
        case 5: 
            r.fibonnacciNumber(1,1,1,1); 
            break; 

        default: 
            cout << "Wrong Input" << endl; 
            break; 
        
    }

    // 
}