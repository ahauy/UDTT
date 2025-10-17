#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int a[100], n;
int b[100], m;

void init(int a[], int n) {
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

void ketqua(int A[], int B[], int n, int m) {
  for(int i = 0; i < n; i ++) {
    int a = A[i];
    for(int j = 0; j < m; j ++) {
      int b = B[j];

      if(pow(a, b) < pow(b, a)) {
        cout << "(" << a << ", " << b << ")" << endl;
      }
    }
  }
}

int main() {

  n = 4;
  m = 2;
  init(a, n);
  init(b, m);

  cout << "Mang A: ";
  display(a, n);
  cout << "Mang B: ";
  display(b, m);
  ketqua(a, b, n, m);
  return 0;
}