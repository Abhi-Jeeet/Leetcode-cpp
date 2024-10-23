class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>ans;
        queue<TreeNode*>q;
        if(!root){
            return -1;
        }
        q.push(root);

        while(!q.empty()){
            vector<int>v;
            int s=q.size();
            for(int i=0; i<s; i++){
                TreeNode* front =q.front();
                q.pop();

                v.push_back(front->val);

                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            long long total = accumulate(v.begin(), v.end(),0LL);
            ans.push(total);
        }
        for(int i=0; i<k-1; i++){
            if(!ans.empty()){
                ans.pop();
            }
            else{
                return -1;
            }
        }
        return ans.empty() ? -1 : ans.top();

    }
};