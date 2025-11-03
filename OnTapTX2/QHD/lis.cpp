#include <iostream>
#include <math.h>

using namespace std;

int main() {

  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i ++) {
    cin >> a[i];
  }
  int l[n];
  for(int i = 0; i < n; i ++) {
    l[i] = 1;
  }

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < i; j ++) {
      if(a[i] > a[j]) {
        l[i] = max(l[i], l[j] + 1);
      }
    }
  }

  int result = 0;
  for(int i = 0; i < n; i ++) {
    if(l[i] > result) {
      result = l[i];
    }
  }

  cout << result;

  return 0;
}