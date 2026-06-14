#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class BinaryTree{
    public:
    // -------- Traversals --------
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (!curr->left) {
                curr->left = new Node(val);
                return root;
            } else q.push(curr->left);

            if (!curr->right) {
                curr->right = new Node(val);
                return root;
            } else q.push(curr->right);
        }
        return root;
    }

    void inorderHelper(Node* root, vector<int>& res) {
        if (!root) return;
        inorderHelper(root->left, res);
        if(root->data > 0) res.push_back(root->data);
        inorderHelper(root->right, res);
    }

    vector<int> inorder(Node* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }

    void preorderHelper(Node* root, vector<int>& res) {
        if (!root) return;
        if(root->data > 0) res.push_back(root->data);
        preorderHelper(root->left, res);
        preorderHelper(root->right, res);
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        preorderHelper(root, res);
        return res;
    }

    void postorderHelper(Node* root, vector<int>& res) {
        if (!root) return;
        postorderHelper(root->left, res);
        postorderHelper(root->right, res);
        if(root->data > 0) res.push_back(root->data);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }


};


int main(){
    BinaryTree bt; 
    Node* root = NULL;
    // vector <int> data = {10,5,15,3,7,-1,18};
    for(auto ele : data){
        root = bt.insert(root, ele); 
    }


    vector<int> in = bt.inorder(root);
    vector<int> pre = bt.preorder(root);
    vector<int> post = bt.postorder(root);

    vector<vector<int>> result(3,vector<int>(7)); 


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < in.size(); j++){
            if(i == 0) result[i][j] = in[j]; 
            if(i == 1) result[i][j] = pre[j]; 
            if(i == 2) result[i][j] = post[j]; 

        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < in.size(); j++){
            cout << result[i][j] << " "; 
        }
        cout << endl; 
    }
    return 0; 

}