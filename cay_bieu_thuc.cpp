#include <iostream>
using namespace std;

// Cấu trúc Node 
struct Node {
    char data;        
    Node* left;       
    Node* right;      

    // tạo Node mới
    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm tạo cây biểu thức
Node* createTree(char bieuthuc[], int length) {
    Node* stack[100]; // Ngăn xếp 
    int top = -1;     

    // Duyệt qua từng ký tự trong biểu thức hậu tố
    for (int i = 0; i < length; i++) {
        char c = bieuthuc[i];

        // toán hạng: tạo Node và đẩy vào ngăn xếp
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            stack[++top] = new Node(c);
        }
        // toán tử: tạo Node cha
        else {
            Node* newNode = new Node(c);
            newNode->right = stack[top--]; 
            newNode->left = stack[top--];  
            stack[++top] = newNode;        
        }
    }

    // Phần tử cuối cùng trong ngăn xếp là gốc của cây
    return stack[top];
}

//Pre-order
void preOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";       
    preOrder(root->left);  
    preOrder(root->right); 
}

//In-order
void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);    
    cout << root->data << " ";       
    inOrder(root->right);   
}

//Post-order
void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);  
    postOrder(root->right); 
    cout << root->data << " ";       
}

int main() {
    
    char bieuthuc[] = {'a', '5', 'b', '*', 'c', '/', '+', 'c', '8', '^', '-', 'd', 'e', '1', '2', '/', '^', '*', '+'};
    int length = sizeof(bieuthuc) / sizeof(bieuthuc[0]);

    // Tạo cây biểu thức
    Node* root = createTree(bieuthuc, length);

    // In 
    cout << "Pre order: ";
    preOrder(root);
    cout << endl;

    cout << "In order: ";
    inOrder(root);
    cout << endl;

    cout << "Post order: ";
    postOrder(root);
    cout << endl;

    return 0;
}
