#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}

void preOrderTraversal(Node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    arr.push_back(root->data);
    preOrderTraversal(root->left, arr);
    preOrderTraversal(root->right, arr);
}

void postOrderTraversal(Node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left, arr);
    postOrderTraversal(root->right, arr);
    arr.push_back(root->data);
}

void MedianArray(Node* root) {
    vector<int> inOrder;
    vector<int> preOrder;
    vector<int> postOrder;

    inOrderTraversal(root, inOrder);
    preOrderTraversal(root, preOrder);
    postOrderTraversal(root, postOrder);

    int n = inOrder.size();
    vector<int> ans;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        temp.push_back(inOrder[i]);
        temp.push_back(preOrder[i]);
        temp.push_back(postOrder[i]);

        sort(temp.begin(), temp.end());
        ans.push_back(temp[1]);
    }
    for(auto v: inOrder) cout << v << " ";
    cout << endl;
    for(auto v : preOrder) cout << v << " ";
    cout << endl;
    for(auto v : postOrder) cout << v << " ";
    cout << endl;
    for(auto v : ans) cout << v << " ";
}

int main() { 
    struct Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
   
    MedianArray(root); 
   
    return 0; 
}