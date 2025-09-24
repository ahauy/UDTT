#include <iostream>

using namespace std;

int n, a[100];

void generationArr() {
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % 11;
  }
}

// 1 3 4 9 | 6 7 5 4
// 1 3 | 4 9  || 6 7 | 5 4

// 0 1 2 3   4 5 6 7
int sumOdd(int a[], int l, int r) {
  if(l == r) {
    if(a[l] % 2 != 0) {
      return a[l];
    } else {
      return 0;
    }
  }

  int mid = (l + r) / 2;
  int left = sumOdd(a, l, mid);
  int right = sumOdd(a, mid + 1, r);
  return left + right;
}

int countOdd(int a[], int l, int r) {
  if(l == r) {
    if(a[l] % 2 != 0) {
      return 1;
    } else {
      return 0;
    }
  }

  int mid = (l + r) / 2;
  int left = countOdd(a, l, mid);
  int right = countOdd(a, mid + 1, r);
  return left + right;
}

// thuật toán tìm phẩn tử lớn nhất bằng thuật toán chia để trị
int max(int a[], int l, int r) {

  if(l > r) {
    return 0;
  } else {
    return a[l] > a[r] ? a[l] : a[r];
  }

  int mid = (l + r) / 2;
  int maxLeft = max(a, l, mid);
  int maxRight = max(a, mid + 1, r);
  return maxLeft > maxRight ? maxLeft : maxRight;
}

int main() {

  cin >> n;
  generationArr();
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  } 

  cout << endl;
  cout << "Phần tử max là: " << max(a, 0, n - 1) << endl;
  // cout << "\n";
  // cout << "Tổng các số lẻ trong mảng là: " << sumOdd(a, 0, n - 1);
  // cout << "\n";
  // cout << "Trung bình cộng các số lẻ là: " << (double)sumOdd(a, 0, n - 1)/countOdd(a, 0, n - 1);
  return 0;
}