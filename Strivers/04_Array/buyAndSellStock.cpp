#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 

int myApproachBuySell(vector<int>& arr){
    int profit = 0; 
    int buy = 0; 
    int sell = 0; 
    for(int i = 0; i < arr.size()-1; i++){
        for(int j = i+1; j < arr.size(); j++){
            if(arr[i] > arr[j]) continue; 
            else if(arr[i] < arr[j]){
                buy = arr[i]; 
                sell = arr[j]; 
                if(profit < (sell-buy)) profit = (sell-buy); 
            }
        }
    }
    return profit; 
}


int minMax(vector <int>& arr){
    int min = 100000; // 7, 6 
    int max = -INFINITY; 
    int minIdx; 

    // Buy
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < min){
            min = arr[i]; 
            minIdx = i; 
        }
    }

    if(minIdx == arr.size()-1) return 0; 

    // Sell 
    for(int i = minIdx+1; i < arr.size(); i++){
        if(arr[i] > max){
            max = arr[i]; 
        }
    }

    // profit
    int result = max-min; 
    return result; 
}

int main(){
    vector <int> arr = {7,1,5,3,6,4};  
    // cout << myApproachBuySell(arr); 
    cout << minMax(arr); 
}