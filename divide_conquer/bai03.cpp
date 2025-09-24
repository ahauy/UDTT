#include <iostream>
#include <iomanip>

using namespace std;

int n;
const int MAX = 100;

struct XeTai {
  string bienSo;
  double khoiLuong;
};

struct List {
  XeTai E[MAX];
  int count;
};

List L;

void init(List &L) {
  L.count = -1;
}

void generationList(List &L) {
  L.count = 7;
  L.E[0] = {"99AA-12345", 5000};
  L.E[1] = {"99AA-11111", 4500};
  L.E[2] = {"99AA-22222", 6000};
  L.E[3] = {"30AB-12567", 3000};
  L.E[4] = {"98AC-99999", 9000};
  L.E[5] = {"98AC-99999", 10000};
  L.E[6] = {"30AC-00000", 5000};
}

void displayList(List L) {
  cout << setw(5) << left << "STT";
  cout << setw(20) << left << "Biển số";
  cout << setw(10) << left << "Tải trọng" << endl;

  for(int i = 0; i < L.count; i ++) {
    cout << setw(5) << left << i + 1;
    cout << setw(20) << left << L.E[i].bienSo;
    cout << setw(15) << L.E[i].khoiLuong << endl;
  }
}

int max(double a[] , int l, int r) {
  if(l > r) {
    return 0;
  }

  int mid = (l + r) / 2;
  double maxLeft = max(a, l, mid);
  double maxRight = max(a, mid + 1, r);
  return maxLeft > maxRight ? maxLeft : maxRight;
}

int main() {

  init(L);
  generationList(L);
  displayList(L);
  return 0;
}