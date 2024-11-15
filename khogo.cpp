#include <iostream>
#include <string>

using namespace std;

struct Wood {
    string type;  
    int size;     
    int age;      
    Wood *next;   
};

// Dinh nghia kho go theo kieu stack
class KhoGo {
private:
    Wood *top;  // Con tro den thanh go tren cung cua stack

public:
    KhoGo() {
        top = nullptr;
    }

    // Kiem tra kho rong
    bool isEmpty() const {
        return top == nullptr;
    }

    // Ham them mot thanh go vao kho 
    void push(const string &type, int size, int age) {
        Wood *newWood = new Wood{type, size, age, top};
        top = newWood;
    }

    // Ham lay mot thanh go ra khoi kho 
    void pop() {
        if (isEmpty()) {
            cout << "Kho rong, khong the lay ra!" << endl;
            return;
        }
        Wood *temp = top;
        top = top->next;
        delete temp;
    }

    // Ham hien thi cac thanh go trong kho
    void display() const {
        if (isEmpty()) {
            cout << "Kho rong." << endl;
            return;
        }
        Wood *current = top;
        cout << "Danh sach cac thanh go hien co trong kho:" << endl;
        int index = 1;
        while (current != nullptr) {
            cout << "Thanh go " << index << ": [Loai: " << current->type 
                 << ", Kich thuoc: " << current->size 
                 << ", Tuoi: " << current->age << "]" << endl;
            current = current->next;
            index++;
        }
    }

    // Ham dem so luong thanh go co cung tuoi go
    int demtuoi(int age) const {
        int count = 0;
        Wood *current = top;
        while (current != nullptr) {
            if (current->age == age) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    // Destructor de giai phong bo nho
    ~KhoGo() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    KhoGo kho;

    // Them cac thanh go vao kho
    kho.push("Do", 5, 10);
    kho.push("Xoan", 3, 7);
    kho.push("Tau", 8, 10);

    // Hien thi danh sach go trong kho
    kho.display();

    // Dem so luong thanh go co tuoi la 7
    int tuoiCanDem = 7;
    int soLuong = kho.demtuoi(tuoiCanDem);
    cout << "So luong thanh go co tuoi " << tuoiCanDem << " la: " << soLuong << endl;

    // Lay mot thanh go ra khoi kho
    kho.pop();

    // Hien thi danh sach go sau khi lay ra
    kho.display();

    return 0;
}
