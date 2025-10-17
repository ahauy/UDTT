#include <iostream>
#include <time.h>

using namespace std;

int n;

int b[9] = {1, 2, 4, 9, 8, 7, 6, 5, 3}; // -> 1, 2, 5, 3, 4

void display(int b[]) {
  for(int i = 0; i <= n - 1; i ++) {
    cout << b[i] << " ";
  }
  cout << endl;
}

void next_config(int b[], int i) {
  int k = n - 1;
  while(k > 0 && b[i] > b[k]) {
    k --;
  }
  swap(b[i], b[k]);
  int m  = n - 1;
  i ++;
  while( m >  i) {
    swap(b[i], b[m]);
    m --;
    i++;
  }
}

void listing_config(int b[]) {
  int i;
  do {
    i = n - 2;
    display(b);
    while(i > 0 && b[i] > b[i + 1]) {
      i --;
    }
    if(i > 0) {
      next_config(b, i);
      return;
    }
  } while(i > 0);
}

int main(int argc, const char * argv[]) {

  n = 9;
  listing_config(b);
  display(b);
  return 0;
}