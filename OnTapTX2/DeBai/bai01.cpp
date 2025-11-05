#include <iostream>
#include <iomanip>
#include <algorithm>
#include <time.h>

using namespace std;

string names[5] = {"Senko", "Panasonic", "Asia", "Hatari", "Mitsubisi"};
string colors[5] = {"Blue", "Red", "Green", "Yellow", "White"};
int prices[5] = {100000, 150000, 200000, 400000, 300000};

struct QuatBan {
  string name;
  string color;
  int price;
};

int p;
int n = 8;
int soQuatDaMua = 0;
QuatBan d[100];

void ktaoP() {
  srand(time(NULL));
  p = rand() % 1200000 + 1;
}


void ktaoD() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    string name = names[rand() % 5];
    string color = colors[rand() % 5];
    int price = prices[rand() % 5];
    d[i] = {name, color, price};
  }
}

void sapxep() {
  for(int i = 0; i < n - 1; i ++) {
    for(int j = n - 1; j > i; j --) {
      if(d[j].price < d[j - 1].price) {
        swap(d[j], d[j - 1]);
      }
    }
  }
}

void hienthi() {
  cout << setw(5) << left << "STT";
  cout << setw(20) << left << "Tên hãng";
  cout << setw(15) << left << "Màu sắc";
  cout << setw(10) << left << "Giá bán" << endl;
  for(int i = 0; i < n; i ++) {
    cout << setw(5) << left << i + 1;
    cout << setw(20) << left << d[i].name;
    cout << setw(15) << left << d[i].color;
    cout << setw(10) << left << d[i].price << endl;
  }
}

bool thamLam() {
  for(int i = 0; i < n; i ++) {
    if(p >= d[i].price) {
      p = p - d[i].price;
      soQuatDaMua ++;
    } else {
      break;
    }
  }
  if(soQuatDaMua > 0) return true;
  else return false;
}

int main () {
  ktaoP();
  int temp = p;
  cout << "Số tiền bạn có là: " << p << endl;
  cout << "Danh sách sản phẩm của chúng tôi: " << endl;
  ktaoD();
  hienthi();
  sapxep();
  cout << "Danh sách sản phẩm của chúng tôi sau khi sắp xếp tăng dần theo giá: " << endl;
  hienthi();
  if(thamLam()) {
    cout << "Với số tiền " << temp << " tôi có thể mua được " << soQuatDaMua << " chiếc quạt trong danh sách." << endl;
    cout << setw(5) << left << "STT";
    cout << setw(20) << left << "Tên hãng";
    cout << setw(10) << left << "Giá bán" << endl;
    for(int i = 0; i < soQuatDaMua; i ++) {
      cout << setw(5) << left << i + 1;
      cout << setw(20) << left << d[i].name;
      cout << setw(10) << left << d[i].price << endl;
    }
  } else {
    cout << "Không thể mua được chiếc quạt nào !!!" << endl; 
  }
  return 0;
}