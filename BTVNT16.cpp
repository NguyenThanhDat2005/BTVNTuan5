#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;
    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;
    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Không cho phép các khóa trùng lặp trong cây AVL
        return node;

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    int balance = getBalance(node);

    // Trường hợp Trái-Trái
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Trường hợp Phải-Phải
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Trường hợp Trái-Phải
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Trường hợp Phải-Trái
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int values[] = {13, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        root = insert(root, values[i]);
    }

    cout << "Duyet cay AVL theo thu tu trung (In-order): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

