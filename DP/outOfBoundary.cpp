//########################## Out of Boundary Paths ########################
//-------------------------------------------------------------------------

// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
// Example 2:


// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12
 

// Constraints:

// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n






class Solution {
public:
  const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}};  // initialize all elements to -1 denoting not yet computed
public:    
bool outOfBounds(int m, int n, int r, int c) {
	return r < 0 || r >= m || c < 0 || c >= n;
}
int findPaths(int m, int n, int maxMove, int r, int c) {        
	bool isOut = outOfBounds(m, n, r, c);
	if(isOut || !maxMove) return isOut;
	if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  // return if already computed result
	dp[r][c][maxMove] = 0;   // elements of dp are initalized to -1, so set to 0 before exploring moves
	for(int i = 0; i < 4; i++) 
		dp[r][c][maxMove] = (dp[r][c][maxMove] + findPaths(m, n, maxMove-1, r + moves[i][0], c + moves[i][1])) % mod;
	return dp[r][c][maxMove];
}
};