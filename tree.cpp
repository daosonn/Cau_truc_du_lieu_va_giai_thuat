#include <iostream>
#include <string>
using namespace std;

// Khai bao cau truc Node
struct Node {
    string title;
    int pages;
    Node *firstChild;
    Node *nextSibling;

    Node(string t, int p) : title(t), pages(p), firstChild(nullptr), nextSibling(nullptr) {}
};

// Them mot node con vao node cha
void addChild(Node *parent, Node *child) {
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        Node *temp = parent->firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Dem so chuong cua cuon sach
int countChapters(Node *root) {
    int count = 0;
    Node *temp = root->firstChild;
    while (temp != nullptr) {
        count++;
        temp = temp->nextSibling;
    }
    return count;
}

// Tim chuong dai nhat
Node* findLongestChapter(Node *root) {
    Node *temp = root->firstChild;
    Node *longest = nullptr;
    int maxPages = 0;
    while (temp != nullptr) {
        if (temp->pages > maxPages) {
            maxPages = temp->pages;
            longest = temp;
        }
        temp = temp->nextSibling;
    }
    return longest;
}

// Xoa mot node
bool deleteNode(Node *parent, const string &title) {
    Node *temp = parent->firstChild;
    Node *prev = nullptr;
    while (temp != nullptr) {
        if (temp->title == title) {
            if (prev == nullptr) {
                parent->firstChild = temp->nextSibling;
            } else {
                prev->nextSibling = temp->nextSibling;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->nextSibling;
    }

    temp = parent->firstChild;
    while (temp != nullptr) {
        if (deleteNode(temp, title)) {
            return true;
        }
        temp = temp->nextSibling;
    }

    return false;
}

// Tinh tong so trang
int calculatePages(Node *node) {
    if (node == nullptr) return 0;
    int totalPages = node->pages;
    Node *temp = node->firstChild;
    while (temp != nullptr) {
        totalPages += calculatePages(temp);
        temp = temp->nextSibling;
    }
    node->pages = totalPages;
    return totalPages;
}

// In cay
void printTree(Node *node, int level) {
    if (node == nullptr) return;
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << "- " << node->title << " (" << node->pages << " trang)\n";
    printTree(node->firstChild, level + 1);
    printTree(node->nextSibling, level);
}

int main() {
    // Tao cay muc luc
    Node *book = new Node("Cuon Sach", 0);
    Node *chapter1 = new Node("Chuong 1", 10);
    Node *chapter2 = new Node("Chuong 2", 20);
    Node *chapter3 = new Node("Chuong 3", 15);

    addChild(book, chapter1);
    addChild(book, chapter2);
    addChild(book, chapter3);

    Node *section1 = new Node("Muc 1.1", 5);
    Node *section2 = new Node("Muc 1.2", 3);
    addChild(chapter1, section1);
    addChild(chapter1, section2);

    // In muc luc
    cout << "Muc luc ban dau:\n";
    printTree(book, 0);

    // Dem chuong
    cout << "\nSo chuong cua sach: " << countChapters(book) << "\n";

    // Tim chuong dai nhat
    Node *longestChapter = findLongestChapter(book);
    if (longestChapter != nullptr) {
        cout << "Chuong dai nhat: " << longestChapter->title << " (" << longestChapter->pages << " trang)\n";
    }

    // Xoa mot muc
    cout << "\nXoa 'Muc 1.1'...\n";
    if (deleteNode(book, "Muc 1.1")) {
        calculatePages(book);
        printTree(book, 0);
    } else {
        cout << "Khong tim thay muc can xoa!\n";
    }

    return 0;
}
