//################### SET MATRIX ZEROES ###################
//---------------------------------------------------------


// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // constant space solution
        bool first_column=false;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                
                if(matrix[i][j]==0){
                    if(j==0){
                        first_column=true;
                    }
                    else matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        // assigning 0 to each row starting from 1,1
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[i].size();j++)matrix[i][j]=0;
            }
        }
        
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                for(int j=1;j<matrix.size();j++)matrix[j][i]=0;
            }
        }
        
        
        if(matrix[0][0]==0){
            for(int i=0;i<matrix[0].size();i++)matrix[0][i]=0;

        }
        
        if(first_column){
            for(int i=0;i<matrix.size();i++)matrix[i][0]=0;
            
        }
    }
};