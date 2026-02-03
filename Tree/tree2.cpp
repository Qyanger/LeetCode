

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

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size() >= 1){
                
                int position; // position 还有长度的意思
                int postorderBack = postorder[postorder.size()-1];
                for (int i = 0; i < inorder.size(); i++){
                    if (inorder[i] == postorderBack){
                        position = i;
                        break;
                    }
                }
                // 这里的越界处理的刚刚好 当(inorder.begin()+position+1, inorder.end())相等时，是空数组
                vector<int> leftInorder(inorder.begin(), inorder.begin()+position);
                vector<int> rightInorder(inorder.begin()+position+1, inorder.end());
                vector<int> leftPostorder(postorder.begin(), postorder.begin()+position);
                vector<int> rightPostorder(postorder.begin()+position, postorder.end()-1);
                TreeNode *root = new TreeNode(postorder[postorder.size()-1],buildTree(leftInorder,leftPostorder),buildTree(rightInorder,rightPostorder));
                return root;
                }
                return nullptr;
        }
};