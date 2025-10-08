#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node(int value) {
            val = value;
            left = NULL;
            right = NULL;
        };
};

 int idx = -1;

Node* buildTree(vector<int>& sq){
    idx++;
    if(sq[idx] == -1 || idx >= sq.size()) {
        return NULL;

    }
    Node* root = new Node(sq[idx]);
    root->left = buildTree(sq);
    root->right = buildTree(sq);
    return root;

};


void inOrder(Node* root){
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
    
};

int main () {
    
    vector<int> sequence = {2,1,3,-1,5,3, -1, -1, 7, -1, 9};
    Node* root = buildTree(sequence);
    inOrder(root);
    cout << endl;
    return 0;
}