#include <iostream>

using namespace std;

const int MAX = 8;

int A[MAX][MAX] = {0};
int X[MAX] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[MAX] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dem = 0;

void display() {
  for(int i = 0; i < MAX; i ++) {
    for(int j = 0; j < MAX; j ++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// kiểm tra xem x, y có còn trong bàn cờ hay không ?
bool isIn(int x, int y) {
  if(x >= 0 && x < MAX && y >= 0 && y < MAX) {
    return true;
  } else {
    return false;
  }
}

void move(int x, int y) {
  dem ++;
  A[x][y] = dem;
  for(int i = 0; i < MAX; i ++) {
    if(dem == MAX * MAX) {
      display();
      exit(0);
    }
    int u = x + X[i];
    int v = y + Y[i];
    if(isIn(u, v) && A[u][v] == 0) {
      move(u, v);
    }
  }
  -- dem;
  A[x][y] = 0;
}

int main() {
  move(0, 0);
  return 0;
}