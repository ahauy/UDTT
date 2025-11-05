#include <iostream>
using namespace std;

int main() {
    const int n = 4, m = 5; // bạn có thể tự đổi
    int a[n] = {1, 3, 4, 6};
    int b[m] = {1, 2, 4, 3, 5};

    int dp[n+1][m+1];

    // Khởi tạo bảng dp với giá trị 0
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = 0;

    // Tính dp theo quy hoạch động
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    int len = dp[n][m]; // độ dài LCS
    int index = len - 1;

    int c[len]; // mảng lưu dãy con LCS

    // Truy vết từ dp[n][m]
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            c[index] = a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // In kết quả
    cout << "Do dai day con chung dai nhat: " << len << endl;
    cout << "Day con chung: ";
    for(int k = 0; k < len; k++)
        cout << c[k] << " ";
    cout << endl;

    cout << endl;
    for(int i = 0; i <= n; i ++) {
      for(int j = 0; j <= m; j ++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }  
    return 0;
}
