//################### SEARCH IN 2D MATRIX ########################################
//-----------------------------------------------------------------------------------
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();
        if(!matrix.size()) return false;
        int low=0;
        int high= n*m-1;
        while(low<=high){
            int mid= (low+(high-low)/2);
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return false;
        
    }
};