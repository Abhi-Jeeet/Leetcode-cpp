class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        int visited[n] = {0};
        queue<int>q;
        visited[0]=1;
        q.push(0);
        vector<int>bfs;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            bfs.push_back(frontNode);
            
            for(auto nbr: adj[frontNode]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return bfs;
        
        
    }
};