#include <iostream> 
#include <stack>

// (', ')', '{', '}', '[' and ']

using namespace std; 

class Leetcode{

    public: 
    char pc(char c){
        if(c == '(') return ')'; 
        else if(c == '{') return '}'; 
        else return ']'; 
    }

    bool validParameter(string s){
        stack <char> stk; 

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(stk.empty()) return false; 
                if(s[i] == pc(stk.top())) stk.pop(); 
                else return false;
            }
        }

        if(stk.empty()) return true; 
        return false; 
    }


    // Leetcode Best Solution 
    bool isValid(string s) {
        if(s.empty() || s.size() % 2 != 0){
            return false;
        }
        stack<char> st;
        for(char& c : s)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(c == ')' && top != '(') return false;
                if(c == ']' && top != '[') return false;
                if(c == '}' && top != '{') return false;
            }
        }

        return st.empty() ? true : false;
    }
};

int main(){
    Leetcode Solution; 
    string s = "}";
    // cout << s.size() << endl; 
    cout << Solution.validParameter(s) << endl; 

    return 0; 
}