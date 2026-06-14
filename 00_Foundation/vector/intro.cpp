#include <iostream> 
#include <vector> 

using namespace std; 

int main(){
    vector <string> cars = {"bmw", "audi", "volvo"}; 
    /*
    for (int i = 0; i < 3; i++){
        cout <<  cars[i] << " "; 
    }*/

    cout << cars.front() << " " ;
    cout << cars.back();
    cars.push_back("Tesla"); 
    cout << cars.at(3); 
    cout << "Size of vector : " << cars.size(); 

    // for each look 
    for (string ele : cars){
        cout << ele << "\n"; 
    }
}
