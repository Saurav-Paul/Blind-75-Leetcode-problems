//https://leetcode.com/problems/house-robber/
class Solution {
public:
    vector<int> dp;
    int find_answer(vector<int>&nums,int i){
        if(i >= nums.size()) return 0 ;
        
        if(dp[i] != -1) return dp[i] ;
        
        int curr_taken = nums[i] + find_answer(nums,i+2) ;
        int not_taken = find_answer(nums,i+1) ;
        
        return dp[i] = max(curr_taken, not_taken) ;
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1) ;
        return find_answer(nums,0) ;
    }
};
