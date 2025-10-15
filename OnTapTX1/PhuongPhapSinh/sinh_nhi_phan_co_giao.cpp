#include <iostream>

using namespace std;

int a[100], n;

void view_config() {
  for(int i = 1; i <= n; i ++) {
    cout << a[i];
  }
  cout << endl;
}


void next_config(int i) {
  a[i] = 1;
  i ++;
  while( i <= n) {
    a[i] = 0;
    i ++;
  }
}

void listing_config() {
  int i;
  // ktao cau hinh ban dau
  a[n + 1] = {0};
  do {
    view_config();
    i = n;
    while(a[i] == 1 && i > 0) {
      i --;
    }
    if(i > 0) {
      next_config(i);
    }
  } while(i > 0);
}


int main() {

  n = 3;
  listing_config();
  return 0;
}