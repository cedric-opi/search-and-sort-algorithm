# include <iostream>
# include <vector> // dynamic array
# include <map>

using namespace std;

class Solution {
public: 
    vector<int> twoSum(vector<int> nums, int target){
        // khai báo map với key = là giá trị, value = vị trí
        map<int,int> m; 

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int targetNum = target - num;

            if(m.find(targetNum) != m.end()){
                // trả về vị trí số cũ và vị trí hiện tại
                return {m[targetNum], i};
            }

            // num (key) là giá trị mà ta đang tiếp tục tìm kiếm
            // gán i để trả về vị trí của số đó (do đề bài yêu cầu)
            m[num] = i;
        }
        return {}; 
    }
};

int main() {
    Solution solution;

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;

    // chạy giải thuật
    vector<int> result = solution.twoSum(nums, target);

    // mỗi một chuỗi số chỉ có một đáp án đúng -> một đáp án chỉ có 2 số
    if(result.size() == 2){
        cout << "Index: {" << result[0] << ", " << result[1] << "}" << endl;
        cout << "Number: {" << nums[result[0]] << ", " << nums[result[1]] << "}" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}