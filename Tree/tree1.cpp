#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// struct  TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

int add_test(int a, int b){
    return a+b;
}
// int add_test(int a, int b){
//     return a+b+1;
// }
class Solution {
    public:
        int add_test(int a, int b){
            return a+b+1;
        }
        int test_class_add()
        {
            return add_test(0,0);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            std::vector<int> res;
            if(root == nullptr) {
                return res;
            }
            add_test(1, 2);
            res.push_back(root->val);

            std::vector<int> left = preorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());
            std::vector<int> right = preorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
            return res;

        }
        vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> res;
            if(root == nullptr) {
                return res;
            }
            std::vector<int> left = inorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());
            res.push_back(root->val);
            std::vector<int> right = inorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
            return res;
        }
        vector<int> postorderTraversal(TreeNode* root) {
            std::vector<int> res;
            if(root == nullptr) {
                return res;
            }
            std::vector<int> left = postorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());
            std::vector<int> right = postorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
            res.push_back(root->val);
            return res;
        }
};

int main() {
    printf("correct print\n");
    Solution test_add;
    int a =test_add.test_class_add();
    printf("%d",a);
    return 0;
}