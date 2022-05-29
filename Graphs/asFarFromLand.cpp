int x[] = { -1,
    0,
    1,
    0
};	// direction matric (from up then clockwise (up-left-down-right) )
int y[] = { 0,
    1,
    0,
    -1
};
class Solution
{
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            queue<pair<int, int>> q;
            int n= grid.size();
            int m= grid[0].size();
            
            for(int i=0 ;i <n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1)
                        q.push({i,j});
                }
            }
            
            if(q.size()==n*m)
                return -1;
            int level = 0;
            
            while(q.size()){
                int size=  q.size();
                level++;
                while(size--){
                    auto [si, sj]= q.front();
                    q.pop();
                    for(int i =0;i<4;i++){
                        int newi = si+x[i];
                        int newj = sj+y[i];
                        
                        if(newi>=0 and newj>=0 and newi<n and newj<m and grid[newi][newj]==0){
                            q.push({ newi,newj });
                            grid[newi][newj]=1;
                        }
                    }
                }
            }
            
            return level-1;
        }
};