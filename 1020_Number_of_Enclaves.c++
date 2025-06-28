class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, int delRow[], int delCol[]){
        visited[row][col]=1;
        for(int i=0; i<4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]==1 && !visited[newRow][newCol]){
                dfs(newRow, newCol, visited, grid, delRow, delCol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0, j, visited, grid, delRow, delCol);
            }
        }
        for(int j=0; j<m; j++){
            if(grid[n-1][j]==1 && !visited[n-1][j]){
                dfs(n-1, j, visited, grid, delRow, delCol);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i, 0, visited, grid, delRow, delCol);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i, m-1, visited, grid, delRow, delCol);
            }
        }
        int count=0;

        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};