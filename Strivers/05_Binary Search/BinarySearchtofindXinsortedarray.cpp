#include <iostream> 
#include <vector>

using namespace std; 
class Solution{
    public: 
    // My approach 
    int binarySearch(vector<int>& vec, int target){
        int front = 0; 
        int last = vec.size()-1;  

        while (front <= last){
            int middle = (front+last)/2; 
            if(vec[middle] == target) return middle; 
            else if (vec[middle] < target){
                front = middle+1; 
            }else{
                last = middle-1; 
            }
        }
        return -1; 
    }
};

int main(){
    Solution way; 
    vector <int> arr = {-1,0,3,5,9,12}; 
    cout << "Result : " << way.binarySearch(arr, -1); 
}