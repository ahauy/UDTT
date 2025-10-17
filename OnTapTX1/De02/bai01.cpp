#include <iostream>

using namespace std;

// n: Số phần tử của mảng a
// a[]: Là mảng chứa các phần tử để tính tổng.
// b[]: Là mảng biểu diễn nhị phân cho mảng a [vd: a[1, 3] = b[1, 0, 1]]
// sum[]: đùng dể lưu tổng
int n, b[100], sum[1000];
int dem = 0;
int a[100];

// khởi tạo cấu hình ban đầu cho b
void init_b() {
  for(int i = 0; i < n; i ++) {
    b[i] = 0;
  }
}


// // hàm khỏi tạo mảng a
void init() {
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % 10;
  }
}

// int a[3] = {1, 2, 3};

// ham hien thi
void display(int a[], int n) {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// ví dụ: a[1, 2, 3] = b[1, 1, 1]
// a[1, 2] = b[1, 1, 0]


// kiem tra xem 1 so da nam trong mang hay chua
bool isInArr(int a[], int n, int x) {
  for(int i = 0; i < n; i ++) {
    if(a[i] == x) {
      return true;
    }
  }
  return false;
}

void next_config(int b[], int i) {
  b[i] = 1;
  i ++;
  while(i < n) {
    b[i] = 0;
    i ++;
  }
}

void listing_config() {
  init_b();
  int i;
  do {
    // display(b, n);
    i = n - 1;
    while(i >= 0 && b[i] == 1) {
      i--;
    }
    if(i >= 0){
      next_config(b, i);
      int s = 0;
      for(int i = 0; i < n; i ++) {
        if(b[i]) {
          s += a[i];
        }
      }
      if(!isInArr(sum, dem, s)) {
        sum[dem] = s;
        dem ++;
      }
      s = 0;
    }
  } while(i >= 0);
}

// hàm sắp xépa
void bubbleSort(int sum[], int dem) {
  for(int i = 0; i < dem; i ++) {
    for(int j = dem - 1; j > i; j --) {
      if(sum[j] < sum[j - 1]) {
        swap(sum[j], sum[j - 1]);
      }
    }
  }
}

int main() {
  n = 3;
  init();

  cout << "Mảng A: ";
  display(a, n);
  listing_config();
  bubbleSort(sum, dem);
  display(sum, dem);
  return 0;
}