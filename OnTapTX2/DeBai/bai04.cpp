#include <iostream>
#include <iomanip>
#include <algorithm>
#include <time.h>

using namespace std;

string brands[5] = {"Iphone", "Oppo", "SamSung", "Nokia", "Xiaomi"};
double sizes[5] = {6, 7, 8, 9, 10};
int prices[5] = {1000, 500, 800, 1200, 900}; //dola

struct Phone {
  string brand;
  double size; // inch
  int price; // dola
};

double s; // inch
int n = 7;
Phone d[100];

void ktaoD() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    string brand = brands[rand() % 5];
    double size = sizes[rand() % 5];
    int price = prices[rand() % 5];
    d[i] = {brand, size, price};
  }
}

void hienthi() {
  cout << left
      << setw(5) << "STT"
      << setw(15) << "Nhãn hiệu" 
      << setw(15) << "Kích thước"
      << setw(10) << "Giá bán" << endl;
  for(int i = 0; i < n; i ++) {
    cout << left
      << setw(5) << i + 1
      << setw(15) << d[i].brand
      << setw(15) << d[i].size
      << setw(10) << d[i].price << endl;
  }
}

int main() {
  cout << "Nhập kích thước balo đi cướp của bạn vào đây: ";
  cin >> s;
  cout << "Danh sách các điện thoại trong cửa hàng: " << endl;
  ktaoD();
  hienthi();  
  return 0;
}