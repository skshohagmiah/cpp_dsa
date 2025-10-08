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
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    Node* insert(Node* root, int value) {
        if (!root) return new Node(value);

        if (value < root->val)
            root->left = insert(root->left, value);
        else if (value > root->val)
            root->right = insert(root->right, value);

        return root;
    }

    Node* minNode(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int value) {
        if (!root) return NULL;

        if (value < root->val)
            root->left = deleteNode(root->left, value);
        else if (value > root->val)
            root->right = deleteNode(root->right, value);
        else {
            // Found the node
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* successor = minNode(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }

    void inOrder(Node* root) {
        if (!root) return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
};

int main() {
    BST bst;
    Node* root = NULL;
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int v : values)
        root = bst.insert(root, v);

    cout << "Inorder before deletion: ";
    bst.inOrder(root);
    cout << endl;

    root = bst.deleteNode(root, 10);

    cout << "Inorder after deleting 10: ";
    bst.inOrder(root);
    cout << endl;

    return 0;
}
