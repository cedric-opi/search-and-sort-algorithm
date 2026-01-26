/**
 * Linear Search Algorithm
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int main() {
    std::vector<int> data = {10, 23, 45, 70, 11, 15};
    int target = 70;

    // gọi Linear Search
    int linearResult = linearSearch(data, target);

    std::cout << "Linear Search: Element " << target << (linearResult != -1 ? " found at index " + std::to_string(linearResult) : " not found") << std::endl;

    return 0;
}