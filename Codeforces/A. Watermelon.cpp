#include <iostream> 
#include <cstdlib>


using namespace std; 

int main(int argc, char* argv[]){
    
    int num = atoi(argv[1]);
    if(num == 2){
        cout << "NO" << endl; 
    }else if(num % 2 == 0) {
        cout << "YES" << endl; 
    }else{
        cout << "NO" << endl; 
    }
}