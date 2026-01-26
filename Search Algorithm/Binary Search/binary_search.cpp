/**
 * Binary Search Algorithm (Iterative)
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Note: Array must be sorted.
 */
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // nếu target là middle index, trả về luôn
        if (arr[mid] == target) {
            return mid;
        }

        // nếu target nhỏ hơn giá trị cần tìm, tìm nửa bên phải
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        // nếu target lớn hơn giá trị cần tìm, tìm nửa bên trái
        else {
            right = mid - 1;
        }
    }

    // nếu không tìm thấy, trả về -1
    return -1;
}

int main() {
    std::vector<int> data = {10, 23, 45, 70, 11, 15};
    int target = 70;

    // sắp xếp array trước khi sử dụng Binary Search
    std::sort(data.begin(), data.end());
    std::cout << "Sorted data: ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;

    int binaryResult = binarySearch(data, target);

    std::cout << "Binary Search: Element " << target << (binaryResult != -1 ? " found at index " + std::to_string(binaryResult) : " not found") << std::endl;

    return 0;
}