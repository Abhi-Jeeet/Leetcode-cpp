/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//T.C -> O(N^2);
//S.C -> O(N)
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) +1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh)>1) return false;

        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);

        if(!leftCheck || !rightCheck){
            return false;
        }
        else{
            return true;
        }
    }
};