class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto nbr:adj[i]){
                indegree[nbr]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            count++;

            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
        }
        if(count==numCourses)return true;
        return false;
    }
};