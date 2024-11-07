#include <iostream>
using namespace std;

// Cấu trúc Node cho danh sách liên kết
struct Node {
    float heSo; // Hệ số 
    int soMu;   // Số mũ 
    Node* lienKet; // Con trỏ trỏ đến nút tiếp theo
};

// Cấu trúc DanhSachDT 
struct DanhSachDT {
    Node* first;  
    Node* last; 
};

// Hàm khởi tạo danh sách đa thức
void khoiTaoDanhSach(DanhSachDT* ds) {
    ds->first = ds->last = NULL;
}

// Hàm tạo một nút mới
Node* taoNode(float heSo, int soMu) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->heSo = heSo;
    p->soMu = soMu;
    p->lienKet = NULL;
    return p;
}

// Hàm thêm nút vào danh sách
void themNode(DanhSachDT* ds, float heSo, int soMu) {
    Node* p = taoNode(heSo, soMu);
    if (ds->first == NULL) {
        ds->first = ds->last = p;
    }
    else {
        ds->last->lienKet = p;
        ds->last = p;
    }
}

// Hàm nhập đa thức từ bàn phím
void nhapDaThuc(DanhSachDT* ds) {
    float heSo;
    int soMu;
    cout << "bat dau nhap da thuc: " << endl;
    do {
        cout << "Nhap he so: ";
        cin >> heSo;
        if (heSo == 0) break;
        cout << "Nhap so mu: ";
        cin >> soMu;
        themNode(ds, heSo, soMu);
    } while (heSo != 0);
}

// Hàm in đa thức ra màn hình
void inDaThuc(DanhSachDT ds) {
    Node* p = ds.first;
    cout << "\nf(x) = ";
    while (p != NULL) {
        cout << p->heSo << "x^" << p->soMu;
        if (p->lienKet != NULL) cout << " + ";
        p = p->lienKet;
    }
    cout << endl;
}

// Hàm cộng hai đa thức
DanhSachDT congDaThuc(DanhSachDT ds1, DanhSachDT ds2) {
    DanhSachDT ketQua;
    khoiTaoDanhSach(&ketQua);
    Node* p1 = ds1.first;
    Node* p2 = ds2.first;

    while (p1 != NULL && p2 != NULL) {
        if (p1->soMu > p2->soMu) {
            themNode(&ketQua, p1->heSo, p1->soMu);
            p1 = p1->lienKet;
        }
        else if (p1->soMu < p2->soMu) {
            themNode(&ketQua, p2->heSo, p2->soMu);
            p2 = p2->lienKet;
        }
        else {
            float tongHeSo = p1->heSo + p2->heSo;
            if (tongHeSo != 0) {
                themNode(&ketQua, tongHeSo, p1->soMu);
            }
            p1 = p1->lienKet;
            p2 = p2->lienKet;
        }
    }

    while (p1 != NULL) {
        themNode(&ketQua, p1->heSo, p1->soMu);
        p1 = p1->lienKet;
    }

    while (p2 != NULL) {
        themNode(&ketQua, p2->heSo, p2->soMu);
        p2 = p2->lienKet;
    }

    return ketQua;
}

// Hàm chính
int main() {
    DanhSachDT f, g, h;
    khoiTaoDanhSach(&f);
    khoiTaoDanhSach(&g);

    cout << "f(x):" << endl;
    nhapDaThuc(&f);

    cout << "g(x):" << endl;
    nhapDaThuc(&g);

    cout << "da thuc f(x):";
    inDaThuc(f);

    cout << "da thuc g(x):";
    inDaThuc(g);

    // Tính h(x) = f(x) + g(x)
    h = congDaThuc(f, g);

    cout << "da thuc h(x) = f(x) + g(x):";
    inDaThuc(h);

    return 0;
}