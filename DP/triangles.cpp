// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
	int n = size(triangle), level = n - 1;
	vector<vector<int> > dp(2, vector<int>(n, 0));
	dp[level-- & 1] = triangle[n - 1];
	for(; level >= 0; level--)
		for(int i = 0; i <= level; i++)
			dp[level & 1][i] = triangle[level][i] + min(dp[(level + 1) & 1][i], dp[(level + 1) & 1][i + 1]);
	return dp[0][0];
}
};