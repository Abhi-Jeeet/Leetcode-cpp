class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> incoming(n, 0);
        vector<bool> sus(n, false);
        for(const auto & invocation : invocations){
            graph[invocation[0]].push_back(invocation[1]);
            incoming[invocation[1]]++;
        }

        marksus(graph, sus, k);
        for(int i=0;i<n;i++){
            if(!sus[i]){
                for(int nei: graph[i]){
                    if(sus[nei]){
                        vector<int> result;
                        for(int j = 0; j<n;++j){
                            result.push_back(j);
                        }
                        return result;
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                result.push_back(i);
            }
        }
        return result;
    }

    void marksus(vector<vector<int>> & graph, vector<bool>& sus, int k){
        stack<int> stk;
        stk.push(k);
        sus[k] = true;
        while(!stk.empty()){
            int method = stk.top();
            stk.pop();

            for(int nei: graph[method]){
                if(!sus[nei]){
                    sus[nei] = true;
                    stk.push(nei);
                }
            }
        }
    }
};