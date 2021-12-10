// subSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>  

using namespace std;


void longest_Common(string a, string b) {  // Hàm tìm xâu con lớn nhất và in ra màn hình
    int n = a.size();  // n chiều dài xâu a, m chiều dài xâu b
    int m = b.size();
    int max_Size;     // Biến lưu độ dài con chung lớn nhất
    string subsequence = "";  // Biến lưu con chung dùng khi truy vết
    int L[10][10];   // Khai báo mảng lưu kết quả:  n+1 hàng, m+1 cột

    for (int i = 0; i <= n; i++)   // Gán cột đầu tiên bằng 0
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)   // Gán hàng đầu tiên = 0
        L[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {  // Nếu có phần tử bằng nhau
                L[i][j] = L[i - 1][j - 1] + 1;   // Áp dụng công thức
            }
            else {   // Trường hợp a[i-1] khác b[j-1]
                if (L[i - 1][j] >= L[i][j - 1])     // Tìm max giữa L[i-1][j] và L[i][j-1]
                    L[i][j] = L[i - 1][j];
                else
                    L[i][j] = L[i][j - 1];
            }
        }
    }

    max_Size = L[n][m];  // Tìm được độ dài con lớn nhất
    int i = n;
    int j = m;
    while (L[i][j] != 0) { // Điều kiện dừng
        if (a[i - 1] == b[j - 1]) {  // Nếu bằng nhau
            subsequence += a[i - 1];   // Cộng a[i-1] vào xâu con
            i--;
            j--;
        }
        else {  // Nếu khác nhau
            if (L[i - 1][j] >= L[i][j - 1]) // So sánh
                i--;
            else
                j--;
        }
    }

    cout << "\nDo dai xau lon nhat: " << max_Size;  // In ra độ dài con lớn nhất
    cout << "\nXau con: ";
    for (int t = max_Size - 1; t >= 0; t--)  // In ngược từ cuối về đầu để xâu con đúng thứ tự
        cout << subsequence[t];
}
int main() {
    string a, b;
    cout << "Nhap xau a: "; cin >> a;
    cout << "Nhap xau b: "; cin >> b;
    longest_Common(a, b);
    return 0;
}