class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& cnt) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1) return;
        
        grid[i][j] = 2;
        cnt++;
        
        dfs(grid, i - 1, j, cnt);
        dfs(grid, i, j - 1, cnt);
        dfs(grid, i + 1, j, cnt);
        dfs(grid, i, j + 1, cnt);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, cnt = 0;
        
        for(int i =0 ; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) {
                    cnt = 0;
                    dfs(grid, i, j, cnt);
                    res = max(res, cnt);
                }
        
        return res;
    }
};