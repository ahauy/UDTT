#include <iostream>
#include <algorithm> // Để dùng std::max
#include <limits.h>  // Để dùng INT_MIN

// 1. Tạo một cấu trúc để chứa bộ thông tin trả về
struct SubArrayInfo {
    int sum;
    int start_index;
    int end_index;
};

// 2. Nâng cấp hàm tìm tổng vắt ngang để trả về SubArrayInfo
SubArrayInfo maxCrossingSum(int A[], int left, int mid, int right) {
    // Tìm tổng lớn nhất và chỉ số tương ứng bên trái
    int sum = 0;
    int left_sum = INT_MIN;
    int max_left_index = mid; // Khởi tạo chỉ số
    for (int i = mid; i >= left; i--) {
        sum = sum + A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left_index = i; // Cập nhật chỉ số
        }
    }

    // Tìm tổng lớn nhất và chỉ số tương ứng bên phải
    sum = 0;
    int right_sum = INT_MIN;
    int max_right_index = mid + 1; // Khởi tạo chỉ số
    for (int i = mid + 1; i <= right; i++) {
        sum = sum + A[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right_index = i; // Cập nhật chỉ số
        }
    }

    // Trả về một "gói hàng" chứa đủ thông tin
    return {left_sum + right_sum, max_left_index, max_right_index};
}

// 3. Nâng cấp hàm chính để trả về và so sánh các SubArrayInfo
SubArrayInfo maxSubArraySum(int A[], int left, int right) {
    // Base case: Nếu chỉ có 1 phần tử
    if (left == right) {
        return {A[left], left, right};
    }

    // Chia
    int mid = left + (right - left) / 2;

    // Trị và Tổng hợp
    SubArrayInfo left_info = maxSubArraySum(A, left, mid);
    SubArrayInfo right_info = maxSubArraySum(A, mid + 1, right);
    SubArrayInfo cross_info = maxCrossingSum(A, left, mid, right);

    // So sánh sum của 3 trường hợp để tìm ra kết quả cuối cùng
    if (left_info.sum >= right_info.sum && left_info.sum >= cross_info.sum) {
        return left_info;
    } else if (right_info.sum >= left_info.sum && right_info.sum >= cross_info.sum) {
        return right_info;
    } else {
        return cross_info;
    }
}

int main() {
    int A[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(A) / sizeof(A[0]);

    std::cout << "Mang A[] da cho la: ";
    for(int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    
    // 4. Nhận về "gói hàng" kết quả cuối cùng
    SubArrayInfo result = maxSubArraySum(A, 0, n - 1);

    std::cout << "Mang con lien tuc co tong lon nhat la: " << result.sum << std::endl;
    
    // Dùng các chỉ số trong gói hàng để in ra mảng con
    std::cout << "Mang con do la: ";
    for (int i = result.start_index; i <= result.end_index; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}