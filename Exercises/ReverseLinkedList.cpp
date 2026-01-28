# include <iostream>
# include <vector>

using namespace std;

// định nghĩa cấu trúc của một node
struct ListNode {
    int val; // giá trị của node
    ListNode *next; // con trỏ tới node tiếp theo

    ListNode(int x) : val(x), next(NULL) {};
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr !=NULL){
            // lưu lại node tiếp theo 
            ListNode* next_temp = curr->next;

            // đảo chiều
            curr->next = prev;

            // tăng giá trị duyệt trong list
            prev = curr;
            curr = next_temp;
        }
        return prev; // hiện tại chính là node đầu tiên sau khi đảo chiều
    }
};

void printList(ListNode* head){
    ListNode* temp = head;
    while (temp != NULL){
        cout << temp->val;
        if(temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << "-> NULL" << endl;
}

// hàm tạo linked list từ array
ListNode* createList(const vector<int>& values){
    if(values.empty()) return NULL;

    // tạo node đầu
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    // nối các node 
    for(size_t i = 1; i < values.size(); i++){
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main(){
    Solution solution;

    vector<int> data = {1,2,3,4,5};
    ListNode* head = createList(data);

    cout << "First List: ";
    printList(head);

    ListNode* newHead = solution.reverseList(head);

    cout << "Reverse List:";
    printList(newHead);

    return 0;
}
