#include <iostream>

using namespace std;

void chuyen(int n, char a, char b, char c) {
  if(n == 1) {
    cout << "Chuyen 1 dia tu " << a << " sang " << c << endl;
  } else {
    chuyen(n - 1, a, c, b);
    chuyen(1, a, b, c);
    chuyen(n - 1, b, a, c);
  }
}

int main() { 

  chuyen(3, 'a', 'b', 'c'); 
  return 0;
}