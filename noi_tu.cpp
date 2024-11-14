#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Node {
    string word;
    Node* next;
    
    Node(string w) : word(w), next(nullptr) {}
};

void addNode(Node*& head, const string& word) {
    Node* newNode = new Node(word);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

string timTuNhieuNhat(Node* head) {
    unordered_map<string, int> demTu;
    Node* temp = head;
    
    while (temp != nullptr) {
        demTu[temp->word]++;
        temp = temp->next;
    }
    
    string tuNhieuNhat;
    int maxCount = 0;
    
    for (const auto& cap : demTu) {
        if (cap.second > maxCount) {
            maxCount = cap.second;
            tuNhieuNhat = cap.first;
        }
    }
    
    return tuNhieuNhat;
}

void loaiBoTuLay(Node*& head) {
    Node* hienTai = head;
    
    while (hienTai != nullptr && hienTai->next != nullptr) {
        if (hienTai->word == hienTai->next->word) {
            Node* temp = hienTai->next;
            hienTai->next = temp->next;
            delete temp;
        } else {
            hienTai = hienTai->next;
        }
    }
}

int demSoTuVung(Node* head) {
    unordered_map<string, bool> tuVung;
    Node* temp = head;
    
    while (temp != nullptr) {
        tuVung[temp->word] = true;
        temp = temp->next;
    }
    
    return tuVung.size();
}

void xuLyCau(Node*& head, const string& cau) {
    stringstream ss(cau);
    string word;
    
    while (ss >> word) {
        addNode(head, word);
    }
}

int main() {
    string cau;
    cout << "Nhập câu: ";
    getline(cin, cau);
    Node* head = nullptr;

    // Xử lý câu 
    xuLyCau(head, cau);
    
    // Tìm từ xuất hiện nhiều nhất
    string tuNhieuNhat = timTuNhieuNhat(head);
    cout << "Từ xuất hiện nhiều nhất: " << tuNhieuNhat << endl;
    
    // Bỏ từ láy
    loaiBoTuLay(head);
    
    // Đếm số từ vựng
    int soTuVung = demSoTuVung(head);
    cout << "Số lượng từ vựng: " << soTuVung << endl;
    
    return 0;
}
