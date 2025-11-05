#include <iostream>
#include <algorithm>

using namespace std;

// Hàm sắp xếp: GIỮ NGUYÊN TĂNG DẦN (để chọn bình nhỏ nhất trước)
void sapxep(int a[], int n) {
  for(int i = 0; i < n - 1; i++) {
    for(int j = n - 1; j > i; j --) {
      // Sắp xếp TĂNG DẦN (Tham lam: chọn bình nhỏ nhất)
      if(a[j] < a[j - 1]) { 
        swap(a[j], a[j - 1]);
      }
    }
  }
}

void hienthi(int a[], int n) {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Thay đổi hàm để trả về số lượng bình đã đổ (int)
int binhNuoc(int n, int m, int a[]) {
  // 1. Sắp xếp các bình theo dung tích TĂNG DẦN
  sapxep(a, m);
  
  int soBinhDaDo = 0; // Biến đếm số bình thành công
  
  for(int i = 0; i < m; i++) {
    // Lựa chọn Tham lam: Luôn cố gắng đổ đầy bình nhỏ nhất có thể
    if(n >= a[i]) {
      n = n - a[i]; // Trừ đi lượng nước của bình hiện tại (a[i])
      soBinhDaDo++; // Đếm bình này
    } else {
      // Nếu không đủ nước cho bình hiện tại (và các bình lớn hơn), dừng lại
      break; 
    }
  }
  
  return soBinhDaDo; // Trả về số lượng bình đã đổ
}

// ... (Hàm hienthi giữ nguyên) ...

int main() {
  int n, m;
  cout << "Nhập số nước trong bình chứa (lít): ";
  cin >> n;
  cout << "Nhập số lượng các bình cần đổ (m): ";
  cin >> m;
  
  // Khai báo mảng bằng biến m không phải là tiêu chuẩn C++ thuần túy, 
  // nhưng được hỗ trợ bởi một số trình biên dịch (VLA).
  int a[m]; 
  cout << "Nhập lượng nước trong mỗi bình: "; 
  for(int i = 0; i < m; i ++) {
    cin >> a[i];
  }
  
  // Gọi hàm và nhận kết quả là số lượng bình
  int ketQua = binhNuoc(n, m, a);
  
  if(ketQua > 0) {
    cout << "\nSố bình mà bình chứa có thể rót đầy nước là: " << ketQua << " bình." << endl;
    cout << "Danh sách các dung tích bình (đã sắp xếp tăng dần): ";
    hienthi(a, m);
  } else {
    cout << "\nBình chứa không thể rót đầy nước cho bất kỳ bình nào!" << endl;
    cout << "Danh sách các dung tích bình (đã sắp xếp tăng dần): ";
    hienthi(a, m);
  }
  
  return 0;
}