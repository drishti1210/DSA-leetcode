//############ Reverse Pairs ####################
//-----------------------------------------------


// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1





class Solution {
public:
    int merge(vector<int>& nums, int low, int high, int mid){
        int total=0;
        int j= mid+1;
        for(int i = low;i<=mid;i++){
            while(j<=high && nums[i]> 2LL*nums[j] ){
                j++;
            }
            total+= (j - (mid +1));
        }
        vector<int>t;
        int left =  low, right = mid+1;
        
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                t.push_back(nums[left++]);
            }
            else {
                t.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            t.push_back(nums[left++]);
        }
        while(right <=high){
            t.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]= t[i-low];
        }
        return total;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return 0;
        int mid = low+ (high-low)/2;
        int inv= mergeSort(nums,low,mid);
        inv+= mergeSort(nums, mid+1,high);
        inv+=merge(nums,low,high,mid);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        return mergeSort(nums,0,n-1);
    }
};