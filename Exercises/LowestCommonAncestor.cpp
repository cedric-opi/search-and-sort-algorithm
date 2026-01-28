# include <iostream>

using namespace std;

// định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL) return NULL;

        // nếu root (LCA) chứa (hoặc tìm thấy) p hoặc q thì trả về chính root 
        if(root == p || root == q) return root;

        // recursive
        TreeNode* leftSearch = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSearch = lowestCommonAncestor(root->right, p, q);

        // xử lý kết quả
        // nếu cả hai bên trái phải đều tìm kiểm được một trong hai giá trị -> node hiện tại chính là LCA
        if(leftSearch != NULL && rightSearch != NULL){
            return root;
        }

        // nếu chỉ bên trái tìm thấy kết quả
        if(leftSearch != NULL){
            return leftSearch;
        }

        // nếu chỉ bên phải tìm thấy kết quả
        return rightSearch;
    }
};

int main(){
    // tạo node và cây
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // nối các node với nhau
    root->left = node5;
    root->right= node1;
    node5->left= node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;
    
    Solution solution;
    
    TreeNode* lca1 = solution.lowestCommonAncestor(root, node5, node1); // kì vọng là 3
    cout << "LCA of 5 and 1: " << lca1->value << endl;

    TreeNode* lca2 = solution.lowestCommonAncestor(root, node2, node7); 
    cout << "LCA of 2 and 7: " << lca2->value << endl;

    return 0;
}