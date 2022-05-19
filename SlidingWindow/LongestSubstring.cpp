class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   int ans=0;
        int l=0,r=0;
        unordered_map<char,int>m;
        int temp=0;
        while(r<s.size()){
            if(m[s[r]]==0){
           
                int len = r-l+1;
                ans = max(ans,len);
                  m[s[r]]++;
                r++;
            }
            else{
                m[s[l]]--;
                l++;
                
            }
        }
        return ans;
    }
};