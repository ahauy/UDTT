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

void insertSort() {
  for(int i = 1; i < n; i ++) {
    int temp = a[i];
    int j = i - 1;
    while(j >= 0 && temp < a[j]) {
      a[j + 1] = a[j];
      j --;
    }
    a[j + 1] = temp;
  }
}


int main() {

  cin >> n;
  ktao();
  display();
  insertSort();
  display();

  return 0;
}