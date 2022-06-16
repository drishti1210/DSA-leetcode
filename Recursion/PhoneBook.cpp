// ################## Letter Combinations of a Phone Number ##############
 //------------------------------------------------------------------------
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].



class Solution {
    private:
    void solve(string mapping[],int index, string output,vector<string>&ans,string &digits){
       //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        //convert to integer
        int number = digits[index]-'0';
        string value = mapping[number];
        for(int i =0 ; i<value.length();i++){
            output.push_back(value[i]);
            solve(mapping,index+1,output,ans,digits);
            output.pop_back(); //backtrack
        }
    }
public:
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
    
    if(digits.length()==0){
        return ans;
    }
        string output ="";
        int index=0;
        string mapping[10] = {"","","abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(mapping, index, output, ans,digits);
        return ans;
    }
};  