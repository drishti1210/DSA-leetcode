class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums;
        int j=0;
        for(int i=1;i<n;i++){
            if(i==n-1){
                int u = nums[i]+nums[j];
                nums[i]=u;
                return nums;
            }
            int update = nums[j]+nums[i];
            nums[i]=update;
            j++;
        }
        return nums;
    }
};