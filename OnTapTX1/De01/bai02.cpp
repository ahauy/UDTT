#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int a[100], n;

void init() {
  srand(time(NULL));
  for(int i = 0; i <  n; i ++) {
    a[i] = rand() % 20 - 8;
  }
}

void display() {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// tong cac so le trong mang = de quy
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

// tim mang con lien tuc co tong max bang chia de tri
int subMax(int b[], int l, int r) {
  if(l == r) {
    return a[l];
  } else {return 0;}
  int m = (l + r) / 2;
  int left = subMax(b, l, m);
  int right = subMax(b, m + 1, r);
}

int main() {

  n = 5;
  init();
  display();
  cout << "Tong cac so le trong mang: " << sumLe(a, n - 1) << endl;
  return 0;
}