class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i , int j, int row, int col){
        if(i<0 || i>=row || j<0 || j>=col|| grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        
        dfs(grid,i+1, j, row, col);
         dfs(grid,i-1, j, row, col);
         dfs(grid,i, j+1, row, col);
         dfs(grid,i, j-1, row, col);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int row  = grid.size();
        int col =  grid[0].size();
        for( int i=0 ;i <row;i++){
            for(int j =0;j<col;j++){
                if(i==0 || i==row-1){
                   if(grid[i][j]==1) {
                        dfs(grid, i, j,row, col);
                    }
                }
                else if(j==0 || j==col-1){
                  if(grid[i][j]==1) { 
                       dfs(grid, i, j, row, col);
                   }
                }
            }
        }
        int count =0;
        
        for(int i=0; i<row; i++){
            for(int j= 0 ; j<col;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
       return count; 
    }
};