#include <iostream>
#include <time.h>

using namespace std;

int a[100], n;

void ktao() {
  srand(time(NULL));
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

void bubbleSort() {
  for(int i = 0; i < n; i ++) {
    for(int j = n - 1; j > i; j --) {
      if(a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
      }
    }
  }
}


int main() {

  cin >> n;
  ktao();
  display();
  bubbleSort();
  display();

  return 0;
}