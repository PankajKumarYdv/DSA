#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

class SQ{
    public: 
    
    int totalExercise(vector<int>& arr, int e){
        sort(arr.begin(), arr.end()); 
        // reverse(arr.begin(), arr.end()); 
        int count = 0; 
        for(int i = arr.size()-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                e -= arr[i]; 
                count++; 
                if(e <= 0){
                    return count; 
                }
            }
        }

        return -1; 
    }
}; 

int main(){
    SQ s; 

    int e, n; 
    cout << "Energy and Number of Exercises  (Space separated) :  ";
    cin >> e >> n; 
    cout << endl; 
    vector<int> arr; 
    cout << "Elements " << endl; 
    for(int i = 0; i < n; i++){
        int ele; 
        cin >> ele; 
        arr.push_back(ele); 
    }

    // 
    cout << "Total Exercise : " << s.totalExercise(arr,e) << endl;
}