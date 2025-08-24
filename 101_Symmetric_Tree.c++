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
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)return true;
        if(left==NULL || right==NULL)return false;

        if(left->val==right->val){
            return isMirror(left->left, right-> right) && isMirror(left->right, right->left);
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};