#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Dinh nghia cau truc cho thanh go
struct Wood {
    string type;  // Loai go
    int size;     // Kich thuoc
    int age;      // Tuoi
};

// Class quan ly kho thanh go
class KhoGo {
private:
    vector<Wood> stack;  // Su dung vector de lam kho stack

public:
    // Ham kiem tra kho co rong hay khong
    bool isEmpty() const {
        return stack.empty();
    }

    // Ham them thanh go vao kho
    void addWood(const string &type, int size, int age) {
        stack.push_back({type, size, age});
    }

    // Ham lay thanh go ra khoi kho
    void removeWood() {
        if (isEmpty()) {
            cout << "Kho rong, khong co thanh go nao de lay!" << endl;
            return;
        }
        stack.pop_back();
    }

    // Ham hien thi danh sach go trong kho
    void display() const {
        if (isEmpty()) {
            cout << "Kho hien tai khong co thanh go nao." << endl;
            return;
        }
        cout << "Danh sach thanh go trong kho:" << endl;
        for (int i = stack.size() - 1; i >= 0; i--) {
            cout << "- Loai: " << stack[i].type 
                 << ", Kich thuoc: " << stack[i].size 
                 << ", Tuoi: " << stack[i].age << endl;
        }
    }

    // Ham dem so luong thanh go theo tuoi
    int countByAge(int age) const {
        int count = 0;
        for (const auto &wood : stack) {
            if (wood.age == age) {
                count++;
            }
        }
        return count;
    }

    // Ham tim danh sach thanh go theo tuoi
    vector<Wood> findByAge(int age) const {
        vector<Wood> result;
        for (const auto &wood : stack) {
            if (wood.age == age) {
                result.push_back(wood);
            }
        }
        return result;
    }
};

int main() {
    KhoGo kho;

    // Them cac thanh go vao kho
    kho.addWood("Do", 5, 10);
    kho.addWood("Xoan", 3, 7);
    kho.addWood("Lim", 8, 10);

    // Hien thi danh sach thanh go
    kho.display();

    // Dem so luong thanh go co tuoi la 7
    int tuoiCanDem = 7;
    int soLuong = kho.countByAge(tuoiCanDem);
    cout << "So luong thanh go co tuoi " << tuoiCanDem << " la: " << soLuong << endl;

    // Lay thanh go ra kho
    kho.removeWood();

    // Hien thi danh sach thanh go sau khi lay
    kho.display();

    // Tim thanh go co tuoi 10
    int tuoiCanTim = 10;
    vector<Wood> ketQua = kho.findByAge(tuoiCanTim);
    cout << "Danh sach thanh go co tuoi " << tuoiCanTim << ":" << endl;
    for (const auto &wood : ketQua) {
        cout << "- Loai: " << wood.type 
             << ", Kich thuoc: " << wood.size 
             << ", Tuoi: " << wood.age << endl;
    }

    return 0;
}
