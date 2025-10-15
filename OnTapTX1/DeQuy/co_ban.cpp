#include <iostream>

using namespace std;

int sum(int n) {
  if( n == 1 ) {
    return 1;
  } 
  return n + sum(n - 1);
}

int count(long n) {
  if(n < 10) {
    return 1;
  } else {
    return 1 + count(n/10);
  }
}

int main() {
  cout << sum(9) << endl;
  cout << count(24374638239) << endl;
  return 0;
}