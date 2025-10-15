#include <iostream>

using namespace std;

int a[100];
int n = 5;
int k = 3;

void display_config() {
  for(int i = 1; i <= k; i ++) {
    cout << a[i];
  }
  cout << endl;
}

void next_config(int i) {
  a[i] +=  1;
  i++;
  while( i <= k) {
    a[i] = a[i - 1] + 1;
    i ++;
  }
}

void listing_config() {
  // cau hinh ban dau
  for(int i = 1; i <= k; i ++) {
    a[i] = i;
  }
  int i;
  do {
    display_config();
    i = k;
    while(i > 0 && a[i] == n - k + i) {
      i --;
    }
    if(i > 0) {
      next_config(i);
    }
  } while(i > 0);
}

int main() {
  listing_config();
  return 0;
}