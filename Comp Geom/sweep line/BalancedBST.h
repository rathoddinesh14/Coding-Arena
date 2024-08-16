#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
    // balance factor
    int bf;
};

class AVLTree {
private:
    Node *root;
    int height(Node *node);
    int balanceFactor(Node *node);
    Node *rotateLeft(Node *node);
    Node *rotateRight(Node *node);
    Node *insert(Node *node, int data);
    Node *remove(Node *node, int data);
    void inorder(Node *node);
    void preorder(Node *node);
    void postorder(Node *node);

public:
    AVLTree();
    ~AVLTree();
    void insert(int data);
    void remove(int data);
    void inorder();
    void preorder();
    void postorder();
};

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    // Clean up memory
}

void AVLTree::insert(int data) {
    root = insert(root, data);
}

void AVLTree::remove(int data) {
    root = remove(root, data);
}

void AVLTree::inorder() {
    inorder(root);
}

void AVLTree::preorder() {
    preorder(root);
}

void AVLTree::postorder() {
    postorder(root);
}

int AVLTree::height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int AVLTree::balanceFactor(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *AVLTree::rotateLeft(Node *node) {
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

Node *AVLTree::rotateRight(Node *node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

Node *AVLTree::insert(Node *node, int data) {
    if (node == nullptr) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->bf = 0;
        return newNode;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    node->bf = balanceFactor(node);
    if (node->bf > 1) {
        if (data < node->left->data) {
            node = rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    } else if (node->bf < -1) {
        if (data > node->right->data) {
            node = rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    }
    return node;
}

Node *AVLTree::remove(Node *node, int data) {
    if (node == nullptr) {
        return node;
    }
    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else {
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        Node *temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    node->bf = balanceFactor(node);
    if (node->bf > 1) {
        if (balanceFactor(node->left) >= 0) {
            node = rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    } else if (node->bf < -1) {
        if (balanceFactor(node->right) <= 0) {
            node = rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    }
    return node;
}

void AVLTree::inorder(Node *node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void AVLTree::preorder(Node *node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void AVLTree::postorder(Node *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}