class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(mat[r][c] == 0) continue;
                ans[r][c] = 1 + min(
                    c > 0 ? ans[r][c - 1] : rows * cols,
                    r > 0 ? ans[r - 1][c] : rows * cols
                );
            }
        }
        for(int r = rows - 1; r >= 0; r--){
            for(int c = cols - 1; c >= 0; c--){
                if(mat[r][c] == 0) continue;
                ans[r][c] = min(ans[r][c], 1 + min(
                    c < cols - 1 ? ans[r][c + 1] : rows * cols,
                    r < rows - 1 ? ans[r + 1][c] : rows * cols
                ));
            }
        }
        return ans;
    }
};