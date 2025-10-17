#include <iostream>
#include <time.h>

using namespace std;

int a[100], n;

void init(int a[], int n) {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % 9 + 1;
  }
}

void display(int a[], int n) {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// tinh tong cac so le trong mang bang DE QUY
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


// dem cac phan tu khong lon hon k bang CHIA DE TRI
int count(int a[], int k, int l, int r) {
  if(l == r) {
    if(a[l] < k) {
      return 1;
    } else {
      return 0;
    }
  }
  int m = (l + r) / 2;
  int left = count(a, k, l, m);
  int right = count(a, k, m + 1, r);
  return left + right;
}

int main() {
  n = 15;
  init(a, n);
  display(a, n);
  cout << "Tong cac so le trong mang la: " << sumLe(a, n - 1) << endl;
  int k;
  cin >> k;
  cout << "So phan tu khong lon hon k = " << k << " trong mang la: " << count(a, k, 0, n - 1) << endl;
  return 0;
}