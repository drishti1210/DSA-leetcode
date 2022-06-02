class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int i,j,n=mat.size(),m=mat[0].size(),r=0;
        vector<int>a;
        vector<vector<int>> res(m, vector<int>(n, 0));
        // for(i=0;i<n;i++){
        //     for(j=0;j<m;j++){
        //         a.push_back(mat[i][j]);
        //     }
        // }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                res[i][j]=mat[j][i];
            }
        }
        return res;
    }
};