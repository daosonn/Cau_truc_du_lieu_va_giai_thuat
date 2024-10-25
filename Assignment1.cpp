#include <iostream>
#include <cstring>  
using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[9];
    char hoTen[50];
    char gioiTinh[4]; 
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node* link;
};

struct List {
    Node* first;
    Node* last;
};

// Khởi tạo danh sách
void khoiTao(List &list) {
    list.first = list.last = nullptr;
}

// Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien &sv) {
    cout << "Mssv: ";
    cin >> sv.maSV;
    cin.ignore();  

    cout << "Ho ten: ";
    cin.getline(sv.hoTen, 50);

    cout << "Gioi tinh: ";
    cin >> sv.gioiTinh;
    cin.ignore();  

    cout << "Ngay thang nam: ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cin.ignore(); 

    cout << "Dia chi: ";
    cin.getline(sv.diaChi, 100);

    cout << "Lop: ";
    cin >> sv.lop;

    cout << "Khoa: ";
    cin >> sv.khoa;
}

// Tạo một nút mới
Node* taoNode(SinhVien sv) {
    Node* node = new Node;
    node->data = sv;
    node->link = nullptr;
    return node;
}

// Thêm sinh viên vào danh sách đã sắp xếp theo mã
void themSinhVien(List &list, SinhVien sv) {
    Node* node = taoNode(sv);
    if (list.first == nullptr || strcmp(sv.maSV, list.first->data.maSV) < 0) {
        node->link = list.first;
        list.first = node;
        if (list.last == nullptr) list.last = node;
    } else {
        Node* p = list.first;
        while (p->link != nullptr && strcmp(sv.maSV, p->link->data.maSV) >= 0) {
            p = p->link;
        }
        node->link = p->link;
        p->link = node;
        if (node->link == nullptr) list.last = node;
    }
}

// In danh sách sinh viên
void inDanhSach(List list) {
    Node* p = list.first;
    while (p != nullptr) {
        SinhVien sv = p->data;
        cout << "Mssv: " << sv.maSV << ", Ho Ten: " << sv.hoTen
             << ", Gioi Tinh: " << sv.gioiTinh
             << ", Ngay Sinh: " << sv.ngaySinh.ngay << "/"
             << sv.ngaySinh.thang << "/" << sv.ngaySinh.nam
             << ", Dia Chi: " << sv.diaChi << ", Lop: " << sv.lop
             << ", Khoa: " << sv.khoa << endl;
        p = p->link;
    }
}

// Phần 3: Tìm và in sinh viên có cùng ngày sinh
void timSinhVienTheoNgaySinh(List list, int ngay) {
    bool timThay = false;
    Node* p = list.first;

    cout << "Cac sinh vien sinh ngay " << ngay << ":\n";
    while (p != nullptr) {
        if (p->data.ngaySinh.ngay == ngay) {
            SinhVien sv = p->data;
            cout << "Mssv: " << sv.maSV << ", Ho Ten: " << sv.hoTen << endl;
            timThay = true;
        }
        p = p->link;
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien cung ngay sinh.\n";
    }
}

// Phần 4: Xóa sinh viên có cùng ngày sinh
void xoaSinhVienTheoNgaySinh(List &list, int ngay) {
    bool daXoa = false;

    // Xóa các sinh viên ở đầu danh sách nếu trùng ngày sinh
    while (list.first != nullptr && list.first->data.ngaySinh.ngay == ngay) {
        Node* temp = list.first;
        cout << "Da xoa sinh vien: " << temp->data.maSV << ", Ho Ten: " << temp->data.hoTen << endl;
        list.first = list.first->link;
        delete temp;
        daXoa = true;
    }

    // Xóa các sinh viên ở giữa danh sách nếu trùng ngày sinh
    Node* p = list.first;
    while (p != nullptr && p->link != nullptr) {
        if (p->link->data.ngaySinh.ngay == ngay) {
            Node* temp = p->link;
            cout << "Da xoa sinh vien: " << temp->data.maSV << ", Ho Ten: " << temp->data.hoTen << endl;
            p->link = p->link->link;
            delete temp;
            daXoa = true;
        } else {
            p = p->link;
        }
    }

    if (!daXoa) {
        cout << "Khong co sinh vien nao sinh ngay " << ngay << " de xoa.\n";
    }

    if (list.first == nullptr) {
        list.last = nullptr;
    }
}

// Menu điều khiển
void menu(List &listSV) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Them sinh vien vao danh sach\n";
        cout << "2. In danh sach sinh vien\n";
        cout << "3. Tim sinh vien theo ngay sinh\n";
        cout << "4. Xoa sinh vien theo ngay sinh\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                SinhVien sv;
                cout << "\nNhap sinh vien:\n";
                nhapSinhVien(sv);
                themSinhVien(listSV, sv);
                break;
            }
            case 2:
                cout << "\nDanh sach sinh vien:\n";
                inDanhSach(listSV);
                break;
            case 3: {
                int ngay;
                cout << "\nNhap ngay sinh can tim: ";
                cin >> ngay;
                timSinhVienTheoNgaySinh(listSV, ngay);
                break;
            }
            case 4: {
                int ngay;
                cout << "\nNhap ngay sinh can xoa: ";
                cin >> ngay;
                xoaSinhVienTheoNgaySinh(listSV, ngay);
                break;
            }
            case 5:
                cout << "Thoat chuong trinh.\n";
                break;
        }
    } while (choice != 5);
}

// Hàm main
int main() {
    List listSV;
    khoiTao(listSV);
    menu(listSV);
    return 0;
}
