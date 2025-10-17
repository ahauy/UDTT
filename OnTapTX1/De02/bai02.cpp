#include <iostream>
#include <time.h>

using namespace std;

int n, a[100];

void init() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % n + 1;
  }
}

void display() {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// tinh tong cac so le trong mang bang chien luoc de quy
int sumLe(int a[], int n) {
  if(n < 0) {
    return 0;
  }
  if(a[n] % 2 != 0) {
    return a[n] + sumLe(a, n - 1);
  } else {
    return sumLe(a, n - 1);
  }
}


// tim vi tri xuat hien cua k bang thuat toan chia de tri
int search(int a[], int k, int l, int r) {
  if(l > r) {
    return -1;
  } 

  int m = (l + r) / 2;
  if(a[m] == k) {
    return m;
  }

  int left = search(a, k, l, m - 1);
  if(left != -1) {
    return left;
  }

  return search(a, k, m + 1, r);
}

int main() {

  n = 10;
  init();
  display();
  cout << "Tong cac so le trong mang: " << sumLe(a, n - 1) << endl;
  int c;
  cout << "Nhap so can tim: ";
  cin >> c;
  if(search(a, c, 0, n - 1) != -1) {
    cout << "Vi tri cua " << c << " la: " << search(a, c, 0, n - 1) << endl;
  } else {
    cout << "Khong tim thay !!!" << endl;
  }
  return 0;
}