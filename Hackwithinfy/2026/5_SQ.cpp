#include <string>
#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <numeric>
using namespace std; 

class StringPieces {
public:
    int maxPieces(string S) {
        unordered_map<char, int> freq_map;
        for (char c : S) {
            freq_map[c]++;
        }
        
        int ans = 0;
        for (auto const& [character, count] : freq_map) {
            if (ans == 0) {
                ans = count;
            } else {
                ans = std::gcd(ans, count);
            }
        }
        
        return ans;
    }
};

int main(){
    StringPieces sp; 
    string word = "zzzzz";
    cout << "Total Pieces : " << sp.maxPieces(word) << endl;
    cout << "Total Pieces : " << sp.maxPieces("ababcc") << endl;
    cout << "Total Pieces : " << sp.maxPieces("abccdcabacda") << endl; 
}