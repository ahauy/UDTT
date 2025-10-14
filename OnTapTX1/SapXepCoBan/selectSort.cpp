#include <iostream>

using namespace std;

int a[100], n;

void ktao() {

  for(int i = 0; i < n; i ++) {
    a[i] = rand() % n;
  }
}
void display() {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void selectionSort() {
  for(int i = 0; i < n; i ++) {
    int m = i;
    for(int j = i + 1; j < n; j ++) {
      if(a[m] > a[j]) {
        m = j;
      }
    }
    if( m != i ) {
      swap(a[i], a[m]);
    }
  }
}

int main() {

  cin >> n;
  ktao();
  display();
  selectionSort();
  display();

  return 0;
}