#include <iostream>

using namespace std;

int n, a[100];

void view_config() {
  for(int i = 1; i <= n; i++) {
    cout << a[i];
  }
  cout << endl;
}


void next_config(int i) {
  int k = n;
  while(a[i] > a[k]) {
    k --;
  }
  swap(a[i], a[k]);
  i ++;
  int j = n;
  while(i < j) {
    swap(a[i], a[j]);
    i ++;
    j --;
  }
}

void listing_config() {
  int i;
  // cau hinh ban dau
  for(int i = 1; i <= n; i ++) {
    a[i] = i;
  }
  do {
    view_config();
    i = n - 1;
    while(i > 0 && a[i] > a[i + 1]) {
      i --;
    }
    if(i > 0) {
      next_config(i);
    }
  } while(i > 0);
}

int main() {

  cin >> n;
  listing_config();
  return 0;
}