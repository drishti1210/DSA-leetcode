class Solution {
public:
    int valueof(char ch){
      switch(ch){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return -1;
      }
    }
    int romanToInt(string s) {
        
      int n = s.length();
      int result = valueof(s[n-1]);
      for(int i = n-2;i>=0;i--){
        
        if(valueof(s[i]) >= valueof(s[i+1]) ){
          result = result + valueof(s[i]);
        }
        else{
          result = result - valueof(s[i]);
       }
      }
      return result;
    }
};