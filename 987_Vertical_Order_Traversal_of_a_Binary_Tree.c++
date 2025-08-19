class Solution {
public:
//T.C -> O(N);
//S.C -> O(N);
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        map<int,map<int,multiset<int>>>mp; //vertical, level, node
        queue<pair<TreeNode*,pair<int,int>>>q; //node, vertical, level
        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* root = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mp[vertical][level].insert(root->val);

            if(root->left!=NULL){
                q.push({root->left,{vertical-1, level+1}});
            }
            if(root->right!=NULL){
                q.push({root->right,{vertical+1, level+1}});
            }
        }
        for(auto it: mp){
            vector<int>col;
            for(auto p: it.second){
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};