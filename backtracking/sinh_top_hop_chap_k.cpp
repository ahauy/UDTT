#include <iostream>

using namespace std;

int a[100], k, n;

void display() {
  for(int i = 1; i <= k; i ++) {
    cout << a[i];
  }
  cout << endl;
}

void Try(int i) {
  for(int j = a[i - 1] + 1; j <= n - k + i; j ++) {
    a[i] = j;
    if(i == k) {
      display();
    } else {
      Try(i + 1);
    }
  }
}

int main() {
  cin >> n >> k;
  Try(1);
  return 0;
}