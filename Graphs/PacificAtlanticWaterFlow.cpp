class Solution {
public:
    
   void dfs(int i, int j, int prev, vector<vector<int>>& ocean,vector<vector<int>>& heights){
        int row = heights.size();
        int col= heights[0].size();
        if(i>=row || j>=col || i<0 || j<0 || prev> heights[i][j])
            return;
       if(ocean[i][j]==1)
           return;
       ocean[i][j]=1;
       dfs(i+1,j, heights[i][j],ocean,heights);
       dfs(i-1,j, heights[i][j],ocean,heights);
       dfs(i,j+1, heights[i][j],ocean,heights);
       dfs(i,j-1, heights[i][j],ocean,heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 
        int row = heights.size();
        int col= heights[0].size();
        vector<vector<int>> pacific(row, vector<int>(col,0));
         vector<vector<int>> atlantic(row, vector<int>(col,0));
        vector<vector<int>>ans;
        for(int i=0; i<row;i++){
            dfs(i,0,heights[i][0],pacific,heights);
            dfs(i, col-1,  heights[i][col-1],atlantic, heights);
            
        }
        
        for(int j =0; j<col;j++){
            dfs(0,j,heights[0][j],pacific,heights);
            dfs(row-1,j, heights[row-1][j],atlantic, heights);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

