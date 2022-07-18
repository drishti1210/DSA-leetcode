// ############################### 3 SUM CLOSEST ###########################
//---------------------------------------------------------------------------
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
 

// Constraints:

// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
// Accepted
// 839,030
// Submissions
// 1,801,572











class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() <3)
            return 0;
        //Random gauge for sum
        int sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        for(int i =0;i < nums.size()-2;i++)
        {
            if(i>0 && nums[i-1] == nums[i])
                continue;
            int l = i+1,r = nums.size()-1;
            while(l<r)
            {
                int cSum = nums[i] + nums[l] + nums[r];
                if(cSum == target)
                    return cSum;
                //Calculate the difference and find minimal difference
                sum = abs(cSum - target)  < abs(sum - target) ? cSum: sum;
            //  cout << "\nSum : " << sum  << "\tfrom " << "i: " << i << "\tl: " << l << "\tr:" << r<< endl;
                if(cSum < target)
                    l++;
                else if (cSum > target)
                    r--;
                
            }
            
        }
        return sum;
        
        
    }
};