#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
}

/**
 * Bubble Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); 
                swapped = true; 
            }
        }
        if (!swapped) break;
    }
}

/**
 * Selection Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i; 
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // luôn cập nhật cho tới khi tìm ra phần tử nhỏ nhất
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

/**
 * Insertion Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // dịch chuyển phần tử sang phải
            j = j - 1;
        }
        // chèn key vào vị trí đúng
        arr[j + 1] = key;
    }
}

/**
 * Merge Sort
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; // tránh việc mid có thể trùng với left mãi mãi khi chỉ còn hai phần tử
    int n2 = r - m; 
    std::vector<int> L(n1), R(n2); 

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
 
    int i = 0, j = 0, k = l;
    // sắp xếp và hợp nhất các phần tử của L và R vào arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    // sao chép các phần tử còn lại của L 
    while (i < n1) arr[k++] = L[i++];
    // sao chép các phần tử còn lại của R
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // tìm điểm ở giữa mà không bị tràn số
        // sắp xếp nửa trái
        mergeSort(arr, l, m); 
        // sắp xếp nửa phải
        mergeSort(arr, m + 1, r);
        // gộp hai mảng đã sắp xếp
        merge(arr, l, m, r);
    }
}

/**
 * Quick Sort
 * Time Complexity: O(n log n) average, O(n^2) worst
 * Space Complexity: O(log n)
 */
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    // index có giá trị nhỏ hơn pivot
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); 
        }
    }
    // đặt pivot vào vị trí đúng
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        // sắp xếp phe bên trái của pivot
        quickSort(arr, low, pi - 1);
        // sắp xếp phe bên phải của pivot
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Heap Sort
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    // kiểm tra con trái
    if (l < n && arr[l] > arr[largest]) largest = l;
    // kiểm tra con phải
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    }
}   

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    // xây dựng heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
    // sắp xếp heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // hoán đổi phần tử Max với phần tử cuối
        heapify(arr, i, 0); // xây dựng lại heap
    }
}

int main() {
    // array gốc
    std::vector<int> original = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> data;

    // in array gốc
    std::cout << "Original array: ";
    printVector(original);

    // sắp xếp bằng Bubble Sort
    data = original; bubbleSort(data);
    std::cout << "Bubble Sort:    "; printVector(data);

    // sắp xếp bằng Selection Sort
    data = original; selectionSort(data);
    std::cout << "Selection Sort: "; printVector(data);

    // sắp xếp bằng Insertion Sort
    data = original; insertionSort(data);
    std::cout << "Insertion Sort: "; printVector(data);

    // sắp xếp bằng Merge Sort
    data = original; mergeSort(data, 0, data.size() - 1);
    std::cout << "Merge Sort:     "; printVector(data);

    // sắp xếp bằng Quick Sort
    data = original; quickSort(data, 0, data.size() - 1);
    std::cout << "Quick Sort:     "; printVector(data);

    // sắp xếp bằng Heap Sort
    data = original; heapSort(data);
    std::cout << "Heap Sort:      "; printVector(data);

    return 0;
}