#include <iostream>

using namespace std;

int n, a[100];

void display() {
  for(int i = 1; i <= n; i++) {
    cout << a[i];
  }
  cout << endl;
}

void Try(int i) {
  for(int j = 0; j <= 1; j ++) {
    a[i] = j;
    if (i == n) {
      display();
    } else {
      Try(i + 1);
    }
  }
}

int main() {
  int n = 4;
  Try(1);
  return 0;
}