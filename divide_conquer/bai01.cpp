#include <iostream>

using namespace std;

double a;
int n;

double powHandler(double a, int n) {
  if(n == 0) {
    return 1;
  } else if(n % 2 == 0) {
    double half = powHandler(a, n / 2);
    return half * half;
  } else {
    double half = powHandler(a, (n - 1) / 2);
    return a * half * half;
  }
}

int main() {

  cin >> a >> n;
  cout << powHandler(a, n) << "\n";
  return 0;
}