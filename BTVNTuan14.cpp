#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() {
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void insert(char value) {
        if (isEmpty()) {
            root = new Node(value);
        } else {
            insertRecursive(root, value);
        }
    }

    void insertRecursive(Node* currentNode, char value) {
        if (currentNode->left == nullptr) {
            currentNode->left = new Node(value);
        } else if (currentNode->right == nullptr) {
            currentNode->right = new Node(value);
        } else {
            insertRecursive(currentNode->left, value);
        }
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }
};

ExpressionTree buildExpressionTree() {
    ExpressionTree tree;

    tree.insert('+');
    tree.root->left = new Node('-');
    tree.root->right = new Node('*');

    // Cây bên trái
    tree.root->left->left = new Node('*');
    tree.root->left->right = new Node('/');
    tree.root->left->left->left = new Node('a');
    tree.root->left->left->right = new Node('5');
    tree.root->left->right->left = new Node('b');
    tree.root->left->right->right = new Node('^');
    tree.root->left->right->right->left = new Node('c');
    tree.root->left->right->right->right = new Node('6');
    tree.root->left->right->right->right->right = new Node('d');

    // Cây bên phải
    tree.root->right->left = new Node('-');
    tree.root->right->left->left = new Node('h');
    tree.root->right->left->right = new Node('f');
    tree.root->right->right = new Node('^');
    tree.root->right->right->left = new Node('e');
    tree.root->right->right->right = new Node('1');

    return tree;
}

int main() {
    ExpressionTree expressionTree = buildExpressionTree();

    cout << "Infix Traversal: ";
    expressionTree.inorder(expressionTree.root);
    cout << endl;

    cout << "Prefix Traversal: ";
    expressionTree.preorder(expressionTree.root);
    cout << endl;

    cout << "Postfix Traversal: ";
    expressionTree.postorder(expressionTree.root);
    cout << endl;

    return 0;
}
