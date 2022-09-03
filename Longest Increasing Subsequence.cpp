//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int find_ans(vector<int> &nums, int curr, vector<int> &mem){
        int cnt = 0 ;
        
        if(mem[curr] != -1) return mem[curr] ;
        
        for(int i = curr + 1; i < nums.size() ; i++){
            if(nums[i] > nums[curr]){
                cnt = max(cnt, find_ans(nums,i,mem)) ;
            }
        }
        
        return mem[curr]=cnt + 1;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size() + 1, -1) ;

        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            ans = max(ans, find_ans(nums,i, dp)) ;
        }
        
        return ans ;
    }
};
