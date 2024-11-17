#include <iostream>
#include <string>
#include <algorithm> // dùng cho swap

using namespace std;

// Node 
struct Node {
    string name;   
    int size;      
    int year;      
    Node *next;    
};

// Cấu trúc Folder 
struct Folder {
    Node *first;   
    Node *last;    
};

// add file
void addFile(Folder *f, string name, int size, int year) {
    Node *newNode = new Node{name, size, year, nullptr};
    if (f->first == nullptr) {
        f->first = f->last = newNode;
    } else {
        f->last->next = newNode;
        f->last = newNode;
    }
}

// sort file
void sortFiles(Folder *f) {
    if (f->first == nullptr) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node *current = f->first;

        while (current != nullptr && current->next != nullptr) {
            if (current->size > current->next->size) {
                // swap các node
                swap(current->name, current->next->name);
                swap(current->size, current->next->size);
                swap(current->year, current->next->year);
                swapped = true;
            }
            current = current->next;
        }
    }
}

// Hàm xóa file có dung lượng bé nhất và năm nhỏ nhất
void deleteSmallestFiles(Folder *f) {
    if (f->first == nullptr) return;

    // Tìm dung lượng nhỏ nhất
    int minSize = f->first->size;
    Node *current = f->first;
    while (current != nullptr) {
        if (current->size < minSize) {
            minSize = current->size;
        }
        current = current->next;
    }

    // Xóa các file có dung lượng bằng minSize và năm nhỏ nhất
    while (f->first != nullptr && f->first->size == minSize) {
        Node *temp = f->first;
        f->first = f->first->next;
        delete temp;
    }

    current = f->first;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->size == minSize) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// hiển thị danh sách file
void displayFiles(Folder *f) {
    Node *current = f->first;
    while (current != nullptr) {
        cout << "Name: " << current->name 
             << ", Size: " << current->size 
             << ", Year: " << current->year << endl;
        current = current->next;
    }
}

int main() {
    Folder folder = {nullptr, nullptr};

    int n;
    cout << "So luong file: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int size, year;
        cout << "Nhap ten, dung luong, nam: ";
        cin >> name >> size >> year;
        addFile(&folder, name, size, year);
    }

    // Sắp xếp file theo dung lượng
    sortFiles(&folder);

    cout << "\nDanh sach file sau khi sap xep:\n";
    displayFiles(&folder);

    // Xóa file nhỏ nhất
    deleteSmallestFiles(&folder);

    cout << "\nDanh sach file sau khi xoa file:\n";
    displayFiles(&folder);

    return 0;
}
