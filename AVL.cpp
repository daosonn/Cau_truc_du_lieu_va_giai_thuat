#include <iostream>
using namespace std;

// Cấu trúc của một node trong cây AVL
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Hàm lấy chiều cao của một node
int height(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

// Hàm tạo node mới
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Ban đầu chiều cao của node mới là 1
    return node;
}

// Hàm lấy giá trị cân bằng của một node
int getBalance(Node* n) {
    return (n == nullptr) ? 0 : height(n->left) - height(n->right);
}

// Hàm xoay phải
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // update chiều cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Hàm xoay trái
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // update chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// thêm node mới vào cây AVL
Node* insert(Node* node, int key) {
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    // Cập nhật chiều cao của node hiện tại
    node->height = 1 + max(height(node->left), height(node->right));

    // Tính giá trị cân bằng
    int balance = getBalance(node);

    // Nếu node mất cân bằng, có 4 trường hợp:

    // Trường hợp Left Left
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Trường hợp Right Right
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Trường hợp Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; 
}

// Hàm in cây theo thứ tự trung thứ tự (In-order traversal)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Thêm các node vào cây AVL
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 15);

    // In cây theo thứ tự trung thứ tự
    cout << "Cay: ";
    inOrder(root);

    return 0;
}
