#include <iostream> 

using namespace std; 
class Learning{
    // private variable and method can't accessed in main
    int b = 23; 

    public: 
    int a = 232; 

    // method 
    // integer return 
    int square(int num){
        num *= num; 
        return num; 
    }
};


int main(){
    Learning learn; 
    cout << learn.a;
    cout << "\nSquare of given number : "<< learn.square(5); 
}