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

class BinaryTree {
public:

    // -------- Traversals --------

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

    // Level Order (BFS)
    vector<int> levelOrder(Node* root) {
        vector<int> res;
        if (!root) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            res.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return res;
    }

    // -------- Basic Operations --------

    // Insert (Level Order insertion)
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

    // Search
    bool search(Node* root, int key) {
        if (!root) return false;
        if (root->data == key) return true;

        return search(root->left, key) || search(root->right, key);
    }

    // Height of tree
    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Count total nodes
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Count leaf nodes
    int countLeaves(Node* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        return countLeaves(root->left) + countLeaves(root->right);
    }

    // -------- Deletion --------
    // (Delete by replacing with deepest node)

    Node* deleteNode(Node* root, int key) {
        if (!root) return NULL;

        if (!root->left && !root->right) {
            if (root->data == key) return NULL;
            else return root;
        }

        queue<Node*> q;
        q.push(root);

        Node* keyNode = NULL;
        Node* curr;

        while (!q.empty()) {
            curr = q.front();
            q.pop();

            if (curr->data == key) keyNode = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (keyNode) {
            int x = curr->data; // deepest node
            deleteDeepest(root, curr);
            keyNode->data = x;
        }

        return root;
    }

    void deleteDeepest(Node* root, Node* delNode) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) {
                if (curr->left == delNode) {
                    curr->left = NULL;
                    delete delNode;
                    return;
                } else q.push(curr->left);
            }

            if (curr->right) {
                if (curr->right == delNode) {
                    curr->right = NULL;
                    delete delNode;
                    return;
                } else q.push(curr->right);
            }
        }
    }
};

int main() {
    BinaryTree bt;

    Node* root = NULL;

    // Insert nodes
    vector <int> data = {10,5,15,3,7,-1,18};
    for(auto ele : data){
        root = bt.insert(root, ele); 
    }

    /*
    root = bt.insert(root, 1);
    root = bt.insert(root, 2);
    root = bt.insert(root, 3);
    root = bt.insert(root, 4);
    root = bt.insert(root, 5);
    */

    // Traversals
    vector<int> in = bt.inorder(root);
    vector<int> pre = bt.preorder(root);
    vector<int> post = bt.postorder(root);
    vector<int> level = bt.levelOrder(root);

    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << endl;

    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << endl;

    cout << "Level Order: ";
    for (int x : level) cout << x << " ";
    cout << endl;

    // Other operations
    cout << "Search 3: " << bt.search(root, 3) << endl;
    cout << "Height: " << bt.height(root) << endl;
    cout << "Total Nodes: " << bt.countNodes(root) << endl;
    cout << "Leaf Nodes: " << bt.countLeaves(root) << endl;

    // Delete node
    root = bt.deleteNode(root, 3);

    cout << "Level Order after deletion: ";
    vector<int> level2 = bt.levelOrder(root);
    for (int x : level2) cout << x << " ";
    cout << endl;

    return 0;
}