#include <iostream>

using namespace std;

//m: so dong tien
//c[]: mang luu tru gia tri cac dong tien
//n: so tien can doi
//s[]: so dong tien cua cac to tien 
int m, n, c[100], s[100];

void nhap(int a[], int n) {
  for(int i = 0; i < n; i ++) {
    cin >> a[i];
  }
}

void hienthi(int a[], int n) {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void sapxep(int a[], int n) {
  for(int i = 0; i < n - 1; i ++) {
    for(int j = n - 1; j > i; j --) {
      if(a[j] > a[j - 1]) {
        swap(a[j], a[j - 1]);
      }
    }
  }
}

bool coinChanging(int c[], int s[], int m, int n) {
  sapxep(c, m);
  s[m] = {0};
  int i = 0;
  while (n > 0 && i < m) {
    s[i] = n / c[i];
    n = n - s[i] * c[i];
    i ++;
  }
  if(n > 0) return false;
  else return true;
}

int main() {

  cout << "Nhập số tờ tiền: ";
  cin >> m;
  cout << "Nhập giá trị của mỗi tờ tiền: ";
  nhap(c, m);
  cout << "Nhập số tiền cần đổi: ";
  cin >> n;
  if(coinChanging(c, s, m, n)) {
    cout << "Đổi được các tờ tiền sau: " << endl;
    for(int i = 0; i < m; i ++) {
      if(s[i] != 0) {
        cout << s[i] << " tờ " << c[i] << endl;
      }
    }
    // hienthi(s, m);
    // hienthi(c, m);
  } else {
    cout << "Không thể đổi tiền !!!" << endl;
  }

  return 0;
}