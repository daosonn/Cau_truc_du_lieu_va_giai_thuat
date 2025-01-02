#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc đồ thị
struct Graph {
    vector<vector<int>> matran; // Ma trận kề
    vector<char> dinh;         // Danh sách đỉnh

    // Hàm khởi tạo đồ thị với số lượng đỉnh
    Graph(int sodinh) {
        matran.resize(sodinh, vector<int>(sodinh, 0));
    }

    // Hàm thêm cạnh vào đồ thị
    void addEdge(int u, int v) {
        matran[u][v] = 1;
        matran[v][u] = 1; // đồ thị vô hướng
    }

    // Hàm hiển thị ma trận kề
    void display() {
        cout << "   ";
        for (char vertex : dinh) {
            cout << vertex << " ";
        }
        cout << endl;
        for (int i = 0; i < matran.size(); i++) {
            cout << dinh[i] << ": ";
            for (int j = 0; j < matran[i].size(); j++) {
                cout << matran[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Khởi tạo đồ thị  8 đỉnh 
    int sodinh = 8;
    Graph g(sodinh);

    // Đặt tên đỉnh
    g.dinh = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    // Nhập ma trận kề từ hình ảnh
    int adj[8][8] = {
        {0, 1, 1, 0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1}
    };

    // Thêm các cạnh vào đồ thị
    for (int i = 0; i < sodinh; i++) {
        for (int j = 0; j < sodinh; j++) {
            if (adj[i][j] == 1) {
                g.addEdge(i, j);
            }
        }
    }

    // Hiển thị ma trận kề
    g.display();

    return 0;
}
