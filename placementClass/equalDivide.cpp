#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <algorithm> 
using namespace std; 

class info{
    public: 
    int equalDivision(string word){
        unordered_map <char,int> freq; 
        int ans; 
        // 
        for (auto  i : word){
            freq[i]++; 
        }

        for(auto i : freq){
            ans = __gcd(ans, i.second); 
        }

        return ans; 
    }


    // gcd 
    int calculate_gcd(int a, int b){
        while(b!=0){
            int temp = b; 
            b = a%b; 
            a = temp; 
        }
        return a; 
    }
}; 

int main(){
    string word = "zzzzz"; 
    info m; 

    cout << "Output : " << m.equalDivision(word) << endl; 

}