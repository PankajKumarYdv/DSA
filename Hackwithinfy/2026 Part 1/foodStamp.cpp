#include <iostream> 
#include <vector> 
using namespace std; 

class FS{
    public: 
    int maxTestPoint(vector<int>& v, vector<int>& d, int n, int m){
        int maxTest = 0; 
        int i = 0;  
        while(m>0){
            if(i < n){
                maxTest += v[i]; 
                i++; 
            }else{
                int idx = i%n; 
                int t = i/n;
                maxTest += (v[idx] - d[idx]) * t; 
                i++; 
            }
            m--; 
        }

        return maxTest; 
    }

};

int main(){
    FS s; 
    int n = 3; 
    int m = 5; 
    vector<int> v = {5,7,9}; 
    vector<int> d = {2,4,6}; 

    cout << "Result : " << s.maxTestPoint(v, d, n, m) << endl; 
}