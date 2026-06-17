#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

void insertAtBottom(stack <int> &st, int bottomElement){
    if(st.empty()){
        st.push(bottomElement); 
        return; 
    }

    int topElement = st.top(); 
    st.pop(); 
    insertAtBottom(st,bottomElement); 
    st.push(topElement); 
}

void reverseStack(stack<int> &st) {
    if(st.empty()) return; 

    int topEle = st.top(); 
    st.pop(); 

    reverseStack(st); 


    insertAtBottom(st, topEle);

    /*
    stack<int> temp; 
    while(!st.empty()){
        int stackTop = st.top(); 
        st.pop(); 
        temp.push(stackTop); 
    }

    st.push(topEle); 
    while(!temp.empty()){
        int tempTop = temp.top(); 
        temp.pop(); 
        st.push(tempTop);
    }
    */
}





void printStack(stack<int> temp){
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl; 
}


int main(){
    stack<int> st; 
    st.push(1); 
    st.push(2); 
    st.push(3); 
    st.push(4); 

    printStack(st);

    // insertAtBottom(st, 34); 
    reverseStack(st); 

    printStack(st); 
}