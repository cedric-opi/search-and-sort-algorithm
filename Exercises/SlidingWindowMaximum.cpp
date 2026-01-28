# include <iostream>
# include <vector>
# include <deque> // hàng hai đầu

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> result;
        deque<int> dq; // hàng lưu indexes

        for(int i = 0; i < nums.size(); i++){
            // nếu phần tử đầu hàng nằm ngoài vùng cửa sổ -> bỏ
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            // nếu phần tử mới lớn hơn (các) số ở đuôi hàng đợi -> vứt (các) số cũ đi
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // thêm index mới nhất vào hàng
            dq.push_back(i);

            // khi cửa sổ đã đủ kích thước k -> đầu hàng chính là MAX
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1,3,-2,4,-7,8,5,9};
    int k = 3;

    cout << "Input array: ";
    for(int x : nums) cout << x << " ";
    cout << "Window size: " << k << endl;

    vector<int> result = solution.maxSlidingWindow(nums, k);

    cout << "Window Maximum: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}