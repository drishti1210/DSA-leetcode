// ########################  Rotting Oranges ##############################
//-------------------------------------------------------------------------

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.




class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir ={-1,0,1,0,-1};
        int n = grid.size();
        int m= grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                for(int i =0 ;i<4;i++){
                    int r = p.first+dir[i];
                    int c = p.second+dir[i+1];
                    if(r>=0 && c>=0 && r<n && c <m && grid[r][c] ==1){
                        grid[r][c]=2;
                        fresh--;
                        q.push({r,c});
                    }
                }
                
            }
            ans++;
        }
        if(fresh>0){
            return -1;
        }
        if(ans==-1) return 0;
        return ans;
    }
};