// ####################### Delete Operation For Two Strings #####################
// ------------------------------------------------------------------------------
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

 

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
 

// Constraints:

// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.



class Solution {
public:
    int minDistance(string str1, string str2) {
        int n=str1.size();
	    int m=str2.size();
	    int dp[n+1][m+1];
	    for(int i=0; i<=n; i++)
	    {
	        for(int j=0; j<=m; j++)
	        {
	            if(j==0||i==0)
	            dp[i][j]=0;
	            
	        }
	    }
	     for(int i=1; i<=n; i++)
	     {
	        for(int j=1; j<=m; j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	            
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	                else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	            
	            
	        }
	     }
	     
	     int ans=n+m-2*dp[n][m];
	     return ans;
	     
    }
};
