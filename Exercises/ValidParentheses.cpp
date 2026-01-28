#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st; 

        for (char c : s) {
            // Nếu là dấu mở, đẩy vào stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                // Kiểm tra xem có khớp cặp dấu không
                char topElement = st.top();

                if ((c == ')' && topElement == '(') || (c == '}' && topElement == '{') || (c == ']' && topElement == '[')) {
                    st.pop(); // Khớp thì xóa khỏi stack
                } else {
                    return false; 
                }
            }
        }

        return st.empty(); // Stack rỗng = true
    }
};

int main() {
    Solution solution;

    string s1 = "{[]}";
    if (solution.isValid(s1)) {
        cout << "Test 1 passed: " << s1 << " is valid" << endl;
    } else {
        cout << "Test 1 failed: " << s1 << " is invalid" << endl;
    }

    string s2 = "([)]";
    if (solution.isValid(s2)) {
        cout << "Test 2 passed: " << s2 << " is valid" << endl;
    } else {
        cout << "Test 2 failed: " << s2 << " is invalid" << endl;
    }

    return 0;
}