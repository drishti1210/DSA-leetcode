//###################  Letter Case Permutation ###########################
//-------------------------------------------------------------------------
// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]
 

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(S, 0, ans);
        return ans;
    }
    
    void backtrack(string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        // save initial value
        char c = s[i];
        // path1: toggle lower/upper case
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backtrack(s, i + 1, ans);
        // path2: reset back(NOT go to this path if c is digit)
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, ans);
        }
    }
};